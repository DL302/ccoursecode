#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include "future.h"

int main()
{
    future_cards_t *f = malloc(sizeof(*f));
    f->n_decks = 0;
    f->decks = malloc(sizeof(*f->decks));
    deck_t *hand1 = malloc(sizeof(*hand1));
    hand1->n_cards = 0;
    hand1->cards = NULL;
    deck_t *hand2 = malloc(sizeof(*hand2));
    hand2->n_cards = 0;
    hand2->cards = NULL;
    card_t as = card_from_num(0);
    card_t bs = card_from_num(1);
    add_card_to(hand1, as);
    add_card_to(hand2, bs);
    card_t *ec0 = add_empty_card(hand1);
    card_t *ec00 = add_empty_card(hand2);
    card_t *ec1 = add_empty_card(hand1);
    card_t *ec11 = add_empty_card(hand2);
    card_t *ec2 = add_empty_card(hand1);
    card_t *ec3 = add_empty_card(hand2);
    add_future_card(f, 0, ec0);
    add_future_card(f, 0, ec00);
    add_future_card(f, 1, ec1);
    add_future_card(f, 1, ec11);
    add_future_card(f, 2, ec2);
    add_future_card(f, 3, ec3);

    deck_t *sdeck = malloc(sizeof(*sdeck));
    sdeck->cards = NULL;
    sdeck->n_cards = 0;
    add_card_to(sdeck, card_from_num(10));
    add_card_to(sdeck, card_from_num(9));
    add_card_to(sdeck, card_from_num(8));
    add_card_to(sdeck, card_from_num(11));
    printf("shuffled deck:\n");
    print_hand(sdeck);
    printf("\n");

    future_cards_from_deck(sdeck, f);
    printf("hand1:\n");
    print_hand(hand1);
    printf("\n");
    printf("hand2:\n");
    print_hand(hand2);
    printf("\n");

    free_deck(hand1);
    printf("freed hand1\n");
    free_deck(hand2);
    printf("freed hand2\n");
    for (size_t i = 0; i < f->n_decks; i++)
    {
        free(f->decks[i].cards);
    }
    free_deck(sdeck);
    free(f->decks);
    free(f);
    return EXIT_SUCCESS;
}