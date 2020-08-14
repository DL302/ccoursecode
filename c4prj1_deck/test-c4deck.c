#include <stdio.h>
#include "cards.h"
#include "eval.h"
#include "deck.h"

int main()
{
    deck_t *test_deck = malloc(sizeof(*test_deck));
    test_deck->cards = malloc(sizeof(*test_deck->cards));
    test_deck->n_cards = 0;
    card_t test_card;
    test_card = card_from_num(0);
    add_card_to(test_deck, test_card);
    printf("adding card to deck:\n");
    print_hand(test_deck);
    printf("done\n");
    printf("adding null card:\n");
    card_t *not = add_empty_card(test_deck);
    printf("done\n");
    *not = card_from_num(1);
    deck_t *exclude_test_deck = make_deck_exclude(test_deck);
    printf("exclusion deck:\n");
    print_hand(exclude_test_deck);
    printf("done\n");

    deck_t *testmatch = malloc(sizeof(*testmatch));
    testmatch->cards = malloc(8 * sizeof(*testmatch->cards));
    testmatch->n_cards = 8;
    char val[] = {'K', 'K', 'Q', 'Q', '0', '9', '9', '9'};
    char su[] = {'s', 'h', 's', 'h', 's', 'd', 'c', 'h'};
    for (size_t i = 0; i < 8; i++)
    {
        card_t *tmp = malloc(sizeof(*tmp));
        *tmp = card_from_letters(val[i], su[i]);
        testmatch->cards[i] = tmp;
    }
    deck_t **decks = malloc(2 * sizeof(*decks));
    decks[0] = test_deck;
    decks[1] = testmatch;
    size_t numdecks = 2;
    printf("buildremainingdeck test:\n");
    deck_t *remand = build_remaining_deck(decks, numdecks);
    print_hand(remand);
    printf("done\n");
    unsigned *matches = get_match_counts(testmatch);
    printf("match counts test:\n");
    for (size_t j = 0; j < 8; j++)
    {
        printf("%u ", matches[j]);
    }

    printf("\ndone\n");
    free_deck(exclude_test_deck);
    free_deck(test_deck);
    free_deck(testmatch);
    free(decks);
    free_deck(remand);
    free(matches);
    return EXIT_SUCCESS;
}