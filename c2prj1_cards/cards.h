#ifndef CARD_H
#define CARD_H
#define VALUE_ACE 14
#define VALUE_KING 13
#define VALUE_QUEEN 12
#define VALUE_JACK 11
typedef enum
{
    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS,
    NUM_SUITS
} suit_t;

struct card_tag
{
    unsigned value;
    suit_t suit;
};
typedef struct card_tag card_t;
typedef enum
{
    STRAIGHT_FLUSH,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    FLUSH,
    STRAIGHT,
    THREE_OF_A_KIND,
    TWO_PAIR,
    PAIR,
    NOTHING
} hand_ranking_t;

//map each number from 0 to 52 to a unique card
card_t card_from_num(unsigned c);

//check that the card is a valid card
void assert_card_valid(card_t c);

//convert hand_ranking_t enum to respective string
const char *ranking_to_string(hand_ranking_t r);

//return character that represents the card's value
char value_letter(card_t c);

//return letter that represents suit
char suit_letter(card_t c);

//print card given a card_t [ex As, 0s, Kc]
void print_card(card_t c);

//given character representation of card [ex (A,s)], create a card_t of it
card_t card_from_letters(char value_let, char suit_let);
#endif
