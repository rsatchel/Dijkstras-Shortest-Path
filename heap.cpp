// This program implements all of the heap methods

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "heap.h"
#include "util.h"
#include <fstream>
#include <sstream>
using namespace std;

HEAP *h;

// Creates a new heap with capacity as specified and size 0
HEAP*  initialize(int n){
	HEAP* h = new HEAP();
	h->capacity = n;
	h->size = 0;
	h->E = new VertexNode[n];
	return h;
}


// Builds new heap after reading in array 
void buildHeap(HEAP *A, VertexNode *array, int size){
	A->size = size;

	//Copy array elements	
	for (int i = 0; i < size; i++) {	// read in array dist and ID's
		A->E[i].num = array[i].num;
		A->E[i].dist = array[i].dist;	
	}
	
	int j = A->size / 2;			// from leftmost parent node, 
	for(int i = j; i>=1; i--){		// recursively heapify
		minHeapify(A, i);
	}
}




// Heapify for minHeap
void minHeapify(HEAP *A, int i){
	int smallest = i;				// current smallest is parent
	int l = left(i);				// identify left child
	int r = right(i);				// identify right child
	
	if(A->size >= l){				// check l is within bounds of array
		if(A->E[l-1].dist < A->E[smallest-1].dist){	// if l is smaller than current smallest
			smallest = l;			// then l is now smallest
		}	
	}
		
	if (A->size >= r){				// check r is within bounds of array
		if(A->E[r-1].dist < A->E[smallest - 1].dist){	// if r is smaller than current smalles
			smallest = r;			// smallest is now r
		}
	}	
	if(smallest != i){				// check if either l or r is smaller than parent
		swap(&(A->E[smallest-1]),&(A->E[i-1]));	// swap parent and smallest
		minHeapify(A,smallest);	// recursively call to leaf nodes
	}
}





//	Prints out heap capacity, size and current heap information
void printHeap(HEAP *A){
	cout << "Heap: ";
	for(int i=0; i<A->size; i++){
		cout << A->E[i].num << " ";		// print out key of each element
	}
	cout << endl;
}




// insert new element with specified key into the heap
void insert(HEAP *A, int dist){
	if(A->size == A->capacity){			// if heap is already full, complain
		cout << "Could not insert key, heap is full!" << endl;
		return;
	}
	A->size = A->size + 1;				// if heap is NOT full, increase size by 1
	int i = A->size;				// determine where to place new element
	while((i > 1) && A->E[parent(i)-1].dist < dist){
		A->E[i-1] = A->E[parent(i)-1];
		i = parent(i);
	}
	A->E[i-1].dist = dist;
	
}




// delete minimum (root) element and print to screen
VertexNode* deleteMin(HEAP *A){
	if(A->size < 1){				// if heap is empty, there is no min element
		cout << "Error: no elements to be extracted!" << endl;
		return NULL;
	}
	swap(&A->E[0], &A->E[A->size - 1]);		// swap root and last element
	A->size = A->size - 1;				// reduce size of heap by 1
	minHeapify(A, 1);		
	// heapify to fix broken heap property
	return &A->E[A->size];				// return minimum value
}




// Changes priority of specified element moving it up the tree	
void decreaseKey(HEAP *A, int i, int dist){
	if(dist > A->E[i-1].dist){
		cout << "Error: new key is greater than current key!" << endl;
	}
	else{
		A->E[i-1].dist = dist;
		while(i>1 && (A->E[parent(i)-1].dist > A->E[i-1].dist)){
			swap(&(A->E[i-1]), &(A->E[parent(i)-1]));
			i = parent(i);
		}
	}
}



