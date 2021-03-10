CPP = g++
CPPFLAGS = -Wall -Wextra -std=c++98

default : test6

all : test1 test2 test3 test4 test5 test6

test1 : container-1-test.o
	$(CPP) $^ -o $@ 

test2 : container-2-test.o
	$(CPP) $^ -o $@ 

test3 : container-3-test.o
	$(CPP) $^ -o $@ 

test4 : container-4-test.o
	$(CPP) $^ -o $@ 

test5 : container-5-test.o
	$(CPP) $^ -o $@ 

test6 : container-6-test.o
	$(CPP) $^ -o $@ 

%.o : %.c
	$(CPP) -o $@ -c $< $(CPPFLAGS)

clean :
	rm -f *.o

mrproper : clean
	rm -f test1 test2 test3 test4 test5 test6

container-1-test.o : Container.h Container.tcc

