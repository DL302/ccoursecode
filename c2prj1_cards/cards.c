#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"

//check that the card is a valid card
void assert_card_valid(card_t c)
{
    assert((c.value == 0 || (c.value >= 2 && c.value <= VALUE_ACE)) && (c.suit >= SPADES && c.suit <= CLUBS));
}

//convert hand_ranking_t enum to respective string
const char *ranking_to_string(hand_ranking_t r)
{
    switch (r)
    {
    case 0:
        return "STRAIGHT_FLUSH";
        break;
    case 1:
        return "FOUR_OF_A_KIND";
        break;
    case 2:
        return "FULL_HOUSE";
        break;
    case 3:
        return "FLUSH";
        break;
    case 4:
        return "STRAIGHT";
        break;
    case 5:
        return "THREE_OF_A_KIND";
        break;
    case 6:
        return "TWO_PAIR";
        break;
    case 7:
        return "PAIR";
        break;
    case 8:
        return "NOTHING";
        break;
    default:
        return "INVALID";
        break;
    }
    return "";
}

//return character that represents the card's value
char value_letter(card_t c)
{
    assert_card_valid(c);
    if (c.value < VALUE_JACK)
    {
        return '0' + c.value;
    }
    else if (c.value == VALUE_JACK)
    {
        return 'J';
    }
    else if (c.value == VALUE_QUEEN)
    {
        return 'Q';
    }
    else if (c.value == VALUE_KING)
    {
        return 'K';
    }
    else if (c.value == VALUE_ACE)
    {
        return 'A';
    }
    else
    {
        return 'X';
    }
}

//return letter that represents suit
char suit_letter(card_t c)
{
    assert_card_valid(c);
    switch (c.suit)
    {
    case SPADES:
        return 's';
        break;
    case HEARTS:
        return 'h';
        break;
    case DIAMONDS:
        return 'd';
        break;
    case CLUBS:
        return 'c';
        break;
    default:
        return 'x';
        break;
    }
}

//print card given a card_t [ex As, 0s, Kc]
void print_card(card_t c)
{
    assert_card_valid(c);
    printf("%c%c ", value_letter(c), suit_letter(c));
}

//given character representation of card [ex (A,s)], create a card_t of it
card_t card_from_letters(char value_let, char suit_let)
{
    card_t temp;
    assert((value_let == '0' || (value_let >= '2' && value_let <= '9') || value_let == 'J' || value_let == 'Q' || value_let == 'K' || value_let == 'A') && (suit_let == 's' || suit_let == 'h' || suit_let == 'd' || suit_let == 'c'));
    if (value_let == '0' || (value_let >= '2' && value_let <= '9'))
    {
        temp.value = value_let - '0';
    }
    else if (value_let == 'J')
    {
        temp.value = VALUE_JACK;
    }
    else if (value_let == 'Q')
    {
        temp.value = VALUE_QUEEN;
    }
    else if (value_let == 'K')
    {
        temp.value = VALUE_KING;
    }
    else if (value_let == 'A')
    {
        temp.value = VALUE_ACE;
    }

    switch (suit_let)
    {
    case 's':
        temp.suit = SPADES;
        break;
    case 'h':
        temp.suit = HEARTS;
        break;
    case 'd':
        temp.suit = DIAMONDS;
        break;
    case 'c':
        temp.suit = CLUBS;
        break;
    }
    return temp;
}

//map each number from 0 to 52 to a unique card
card_t card_from_num(unsigned c)
{
    card_t temp;
    int value;
    int suit;
    assert(c >= 0 && c < 52);
    value = c % 13;
    suit = c / 13;
    if (value == 0 || (value >= 2 && value <= 9))
    {
        temp.value = value;
    }
    else if (value == 10)
    {
        temp.value = VALUE_JACK;
    }
    else if (value == 11)
    {
        temp.value = VALUE_QUEEN;
    }
    else if (value == 12)
    {
        temp.value = VALUE_KING;
    }
    else if (value == 1)
    {
        temp.value = VALUE_ACE;
    }
    switch (suit)
    {
    case 0:
        temp.suit = SPADES;
        break;
    case 1:
        temp.suit = HEARTS;
        break;
    case 2:
        temp.suit = DIAMONDS;
        break;
    case 3:
        temp.suit = CLUBS;
        break;
    }
    return temp;
}
