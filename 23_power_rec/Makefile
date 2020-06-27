pow: power.o test-power.o
	gcc -o pow power.o test-power.o

power.o: power.c
	gcc -c power.c -Wall -Werror -pedantic -std=gnu99

test-power.o: test-power.c
	gcc -c test-power.c -Wall -Werror -pedantic -std=gnu99