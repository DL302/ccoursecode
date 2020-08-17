CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99

futest: cards.o deck.o test-future.o future.o
	gcc -o futest cards.o deck.o future.o test-future.o $(CFLAGS)
intest: cards.o deck.o test-input.o future.o input.o
	gcc -o intest cards.o deck.o input.o future.o test-input.o $(CFLAGS)
clean:
	rm *.o futest intest