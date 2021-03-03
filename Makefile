n:
	rm -f exec
	rm -f a.out
	g++ -std=c++11 NotePad.cpp
	./a.out

r:
	rm -f exec
	rm -f a.out
	g++ -std=c++17 main.cpp
	./a.out

g:
	rm -f exec
	rm -f a.out
	g++ -std=c++11 NumberGuesser.cpp
	./a.out
  

# compile: clean
# 	g++ -std=c++11 -o exec main.cpp

# clean:
# 	rm -f exec
# 	rm -f a.out

# run:
# 	./exec

