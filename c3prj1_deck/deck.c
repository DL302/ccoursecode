#include <stdio.h>
#include <stdlib.h>
#include "cards.h"
#include "deck.h"
#include <assert.h>
//print out contents of a hand
void print_hand(deck_t *hand)
{
    size_t num = hand->n_cards;
    for (size_t i = 0; i < num; i++)
    {
        print_card(*hand->cards[i]);
    }
}

//check if deck contains a certain card or not
int deck_contains(deck_t *d, card_t c)
{
    size_t num = d->n_cards;
    for (size_t i = 0; i < num; i++)
    {
        if (c.value == d->cards[i]->value && c.suit == d->cards[i]->suit)
        {
            return 1;
        }
    }
    return 0;
}

//shuffle an inputted deck
void shuffle(deck_t *d)
{
    //fisher-yates shuffle
    size_t num = d->n_cards;
    for (size_t i = 0; i < num; i++)
    {
        int randNum = rand() % (num - i) + i;
        card_t *tmp = d->cards[i];
        d->cards[i] = d->cards[randNum];
        d->cards[randNum] = tmp;
    }
}

//check if the deck is valid [does not have duplicate cards]
void assert_full_deck(deck_t *d)
{
    size_t num = d->n_cards;
    for (size_t i = 0; i < num; i++)
    {
        int count = 0;
        for (size_t j = 0; j < num; j++)
        {
            if ((deck_contains(d, *d->cards[i]) && deck_contains(d, *d->cards[j])) && (d->cards[i]->value == d->cards[j]->value && d->cards[i]->suit == d->cards[j]->suit))
            {
                count++;
            }
        }
        assert(count == 1);
    }
}