r: 
	rm -f exec
	rm -f a.out
	g++ -std=c++17 -g Sorted_List.cc test_list.cc
	valgrind --tool=memcheck --leak-check=yes ./a.out
	./a.out