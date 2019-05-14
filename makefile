__start__: a.out
	./a.out

a.out: main.o  
	g++ -std=c++14 main.o  

main.o: main.cpp MergeSort.hpp QuickSort.hpp HeapSort.hpp test_functions.hpp
	g++ -c -std=c++14 -Wall -pedantic main.cpp

clean:
	rm -f *.o a.out

