#include "cards.h"
#include <stdio.h>

int main(void)
{
    hand_ranking_t test = FULL_HOUSE;
    printf("test hand is %s\n", ranking_to_string(test));
    card_t ace_of_spades;
    card_t king_of_spades;
    ace_of_spades.value = VALUE_ACE;
    ace_of_spades.suit = SPADES;
    printf("ace_of_spades currently: ");
    print_card(ace_of_spades);
    printf("\n");
    printf("ace_of_spades now: ");
    ace_of_spades = card_from_letters('2', 'h');
    print_card(ace_of_spades);
    printf("\n");
    for (int i = 0; i < 52; i++)
    {
        king_of_spades = card_from_num(i);
        print_card(king_of_spades);
    }
    return 0;
}