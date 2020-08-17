#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "future.h"
#include "input.h"

int main()
{
    FILE *a = fopen("test.txt", "r");
    deck_t *sdeck = malloc(sizeof(*sdeck));
    sdeck->cards = NULL;
    sdeck->n_cards = 0;
    add_card_to(sdeck, card_from_num(0));
    size_t hn = 0;
    future_cards_t *f = malloc(sizeof(*f));
    f->decks = NULL;
    f->n_decks = 0;
    deck_t **test = read_input(a, &hn, f);
    future_cards_from_deck(sdeck, f);
    printf("read input\n");
    printf("hand1:\n");
    print_hand(test[0]);
    printf("\n");
    printf("hand2:\n");
    print_hand(test[1]);
    printf("\n%zu\n", hn);
    fclose(a);
    free_deck(test[0]);
    free_deck(test[1]);
    free_deck(sdeck);
    free(test);
    free(f->decks[0].cards);
    free(f->decks);
    free(f);
    return EXIT_SUCCESS;
}