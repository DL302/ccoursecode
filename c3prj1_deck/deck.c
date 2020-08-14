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

//add inputted card to inputted deck
void add_card_to(deck_t *deck, card_t c)
{
    card_t *card = malloc(sizeof(*card));
    card->suit = c.suit;
    card->value = c.value;
    deck->cards = realloc(deck->cards, (1 + deck->n_cards) * sizeof(*deck->cards));
    deck->cards[deck->n_cards] = card;
    deck->n_cards++;
}

//add an empty card [value and suit both are 0] to inputted deck and return pointer to it
card_t *add_empty_card(deck_t *deck)
{
    card_t *empty_card = malloc(sizeof(*empty_card));
    empty_card->suit = 0;
    empty_card->value = 0;
    deck->cards = realloc(deck->cards, (1 + deck->n_cards) * sizeof(*deck->cards));
    deck->cards[deck->n_cards] = empty_card;
    deck->n_cards++;
    return empty_card;
}

//create a full deck excluding the inputted deck_t * excluded_cards

deck_t *make_deck_exclude(deck_t *excluded_cards)
{
    deck_t *result = malloc(sizeof(*result));
    result->cards = malloc(sizeof(*result->cards));
    result->n_cards = 0;
    for (size_t i = 0; i < 52; i++)
    {
        card_t *card = malloc(sizeof(*card));
        *card = card_from_num(i);
        if (!deck_contains(excluded_cards, *card))
        {
            result->cards = realloc(result->cards, (1 + result->n_cards) * sizeof(*result->cards));
            result->cards[result->n_cards] = card;
            result->n_cards++;
        }
        else
        {
            free(card);
        }
    }
    return result;
}

//given an array of hands [deck_t **hands], create the remaining deck
deck_t *build_remaining_deck(deck_t **hands, size_t n_hands)
{
    deck_t *cards_in_hands = malloc(sizeof(*cards_in_hands));
    cards_in_hands->n_cards = 0;
    cards_in_hands->cards = malloc(sizeof(*cards_in_hands->cards));
    for (size_t i = 0; i < n_hands; i++)
    {
        for (size_t j = 0; j < hands[i]->n_cards; j++)
        {
            if (hands[i]->cards[j]->suit == 0 && hands[i]->cards[j]->value == 0)
            {
                continue;
            }
            else
            {
                cards_in_hands->cards = realloc(cards_in_hands->cards, (1 + cards_in_hands->n_cards) * sizeof(*cards_in_hands->cards));
                cards_in_hands->cards[cards_in_hands->n_cards] = hands[i]->cards[j];
                cards_in_hands->n_cards++;
            }
        }
    }
    deck_t *result = make_deck_exclude(cards_in_hands);
    free(cards_in_hands->cards);
    free(cards_in_hands);
    return result;
}

//free allocated memory of inputted deck
void free_deck(deck_t *deck)
{
    for (size_t i = 0; i < deck->n_cards; i++)
    {
        free(deck->cards[i]);
    }
    free(deck->cards);
    free(deck);
}