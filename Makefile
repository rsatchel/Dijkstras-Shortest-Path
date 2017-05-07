run:		main.o util.o heap.o graph.o
	g++ -std=c++11 main.cpp heap.cpp util.cpp graph.cpp -g -o run

clean:
	rm *.o

cleanAll:
	rm *.o run
