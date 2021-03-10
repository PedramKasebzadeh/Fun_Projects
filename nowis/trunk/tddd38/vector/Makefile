CPP = g++
CPPFLAGS = -Wall -Wextra -std=c++98

default : test

test : test-fixed_size_vector.o
	$(CPP) $^ -o $@

%.o : %.c
	$(CPP) -c $< -o $@ $(CPPFLAGS)

clean :
	rm -f *.o

mrproper /Users/pedram/Desktop/cpp/TDDE18_and_TDDD38/Lab 3/linked_list.en.pdf: clean
	rm -f test

test-fixed_size_vector.o : fixed_size_vector.h

