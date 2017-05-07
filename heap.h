// header file for heap.cpp

#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include "util.h"
#include "graph.h"

//using namespace std;

// element structure has key property
struct ELEMENT{
	int key;
};



// heap structure has capacity & size properties and pointer to element
struct HEAP{
	int capacity;
	int size; 	
	VertexNode *E;
	 
};  
	// heap methods
	HEAP* initialize(int n);					// initialise new heap of capacity n

	void readInArray(HEAP *A);					// read in heap data from file
	
	void buildHeap(HEAP *A, VertexNode *array, int size);					// build the heap using minHeap property
	
	void minHeapify(HEAP *A, int i);			// heapify for minHeap property
	
	void printHeap(HEAP *A);					// print heap size, capacity and each element to screen
	
	void insert(HEAP *A, int dist);				// insert new element
	
	VertexNode* deleteMin(HEAP *A);						// delete min (root) element
	
	void decreaseKey(HEAP *A, int i, int dist);	// decrease key of specified element to new key value 



#endif
