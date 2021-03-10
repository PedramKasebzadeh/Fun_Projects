CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++98
LDFLAGS = 

EXEC = test

default : test

test : test.o geometric_object.o
	$(CXX) $^ -o $(EXEC) $(LDFLAGS)

%.o : %.c
	$(CXX) -o $@ -c $< $(CXXFLAGS)

test.o : point.h line.h circle.h rectangle.h geometric_object.h triangle.h plane.h

test.o : geometric_object.h point.h line.h circle.h rectangle.h geometric_object.h plane.h triangle.h

geometric_object.o : geometric_object.h

clean : 
	rm -f *.o

mrproper : clean
	rm -f test 

