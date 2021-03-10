CPP = g++
CPPFLAGS = -Wall -Wextra -std=c++98

default : prog6

all : prog6

prog6 : program6.cc
	$(CPP) -o $@ $^ $(CPPFLAGS)

clean :
	rm -f *.o

mrproper : clean
	rm -f prog6

