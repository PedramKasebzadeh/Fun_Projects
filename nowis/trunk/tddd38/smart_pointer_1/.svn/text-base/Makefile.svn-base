CC = g++
CFLAGS = -Wall -Wextra -std=c++98
LDFLAGS =

default :  test

test : test.o smart_pointer.o
	$(CC) $^ -o $@ $(LDFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean : 
	rm -f *.o

mrproper : clean
	rm -f test 

smart_pointer.o : smart_pointer.h

test.o : smart_pointer.h

