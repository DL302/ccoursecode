#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

//usage: ./programname inputfile.txt numberofMonteCarlotrialstoperform
//file is required, number of trials to perform is not, will default to 10000
int main(int argc, char **argv)
{
    //cli argument error checking
    if (argc < 2)
    {
        fprintf(stderr, "Usage: poker <inputfile.txt> <number of Monte Carlo trials to perform>\nThe input file is required, however the second argument isn't and will default to 10000 trials\n");
        return EXIT_FAILURE;
    }
    unsigned num_trials = 10000;
    if (argc == 3)
    {
        num_trials = atoi(argv[2]);
    }
    FILE *inf = fopen(argv[1], "r");
    if (inf == NULL)
    {
        fprintf(stderr, "Could not open input file \"%s\"\n", argv[1]);
        return EXIT_FAILURE;
    }
    future_cards_t *fucars = malloc(sizeof(*fucars));
    fucars->decks = NULL;
    fucars->n_decks = 0;
    size_t numOfHands;
    deck_t **decks = read_input(inf, &numOfHands, fucars);
    deck_t *restOfDeck = build_remaining_deck(decks, numOfHands);
    unsigned winCounts[numOfHands + 1];
    memset(winCounts, 0, sizeof(winCounts));
    //trials
    for (size_t i = 0; i < num_trials; i++)
    {
        shuffle(restOfDeck);
        future_cards_from_deck(restOfDeck, fucars);
        unsigned curWinCount[numOfHands];
        memset(curWinCount, 0, sizeof(curWinCount));
        for (size_t j = 0; j <= numOfHands - 2; j++) //for each hand except the last
        {
            for (size_t a = j; a < numOfHands - 1; a++) //comparing every single hand with each other
            {
                int compResult = compare_hands(decks[j], decks[a + 1]);
                if (compResult == 1)
                {
                    curWinCount[j]++;
                }
                else if (compResult == -1)
                {
                    curWinCount[a + 1]++;
                }
            }
        }
        //whichever hand has the most wins is the hand that wins
        unsigned max = get_largest_element(curWinCount, numOfHands);
        unsigned count = 0;
        unsigned index = 0;
        for (size_t b = 0; b < numOfHands; b++)
        {
            if (curWinCount[b] == max)
            {
                index = b;
                count++;
            }
        }
        if (count > 1) //if there is a tie
        {
            winCounts[numOfHands]++;
        }
        else
        {
            winCounts[index]++;
        }
    }
    //print data
    double percentage;
    for (size_t k = 0; k < numOfHands; k++)
    {
        percentage = 100 * (double)winCounts[k] / num_trials;
        printf("Hand %zu won %u / %u times (%.2f%%)\n", k, winCounts[k], num_trials, percentage);
        free_deck(decks[k]);
    }
    //free up memory
    free(decks);
    printf("And there were %u ties\n", winCounts[numOfHands]);
    free_deck(restOfDeck);
    for (size_t a = 0; a < fucars->n_decks; a++)
    {
        free(fucars->decks[a].cards);
    }
    free(fucars->decks);
    free(fucars);
    if (fclose(inf) != 0)
    {
        perror("Could not close input file\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}