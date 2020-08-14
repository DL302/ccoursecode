CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99 -no-pie

test: cards.o deck.o eval.o test-c4deck.o
	gcc -o test cards.o deck.o eval.o test-c4deck.o -Wall -Werror -std=gnu99 -ggdb3