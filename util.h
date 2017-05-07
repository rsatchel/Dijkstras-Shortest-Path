// util.h
// utility files used for heap operations

#ifndef UTIL_H
#define UTIL_H 

#include <iostream>
#include "heap.h"

//using namespace std;

void swap(struct VertexNode *E1, struct VertexNode *E2);	// swaps 2 specified elements
int parent(int i);						// returns parent of specified element
int left(int i);						// returns left child of specified element
int right(int i);						// returns right child of specified element

#endif
