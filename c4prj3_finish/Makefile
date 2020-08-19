CFLAGS = -Wall -Werror -pedantic -std=gnu99 -ggdb3
poker: cards.o deck.o eval.o future.o input.o main.o
	gcc -o poker cards.o deck.o eval.o future.o input.o main.o $(CFLAGS)

clean:
	rm poker *.o