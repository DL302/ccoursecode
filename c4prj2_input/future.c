#include <stdio.h>
#include <stdlib.h>
#include "future.h"
#include "cards.h"
#include "deck.h"

//adds ptr to fc at index
//?3 means index 3

void add_future_card(future_cards_t *fc, size_t index, card_t *ptr)
{
    if (index + 1 > fc->n_decks)
    {
        fc->decks = realloc(fc->decks, (index + 1) * sizeof(*fc->decks));
        for (size_t i = fc->n_decks; i < index + 1; i++)
        {
            fc->decks[i].cards = NULL;
            fc->decks[i].n_cards = 0;
        }
        fc->n_decks = index + 1;
    }
    fc->decks[index].cards = realloc(fc->decks[index].cards, (1 + fc->decks[index].n_cards) * sizeof(*fc->decks[index].cards));
    fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
    fc->decks[index].n_cards++;
}

//takes in shuffled deck and future_cards_t
//draws cards from shuffled deck and assigns the cards to
//the pointed to in the future_cards_t
void future_cards_from_deck(deck_t *deck, future_cards_t *fc)
{
    if (deck->n_cards < fc->n_decks)
    {
        perror("Shuffled deck size is not large enough for fc\n");
    }

    for (size_t i = 0; i < fc->n_decks; i++)
    {
        if (fc->decks[i].n_cards == 0)
        {
            continue;
        }

        for (size_t j = 0; j < fc->decks[i].n_cards; j++)
        {
            fc->decks[i].cards[j]->value = deck->cards[i]->value;
            fc->decks[i].cards[j]->suit = deck->cards[i]->suit;
        }
    }
}