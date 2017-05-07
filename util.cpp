#include<iostream>
#include"util.h"

using namespace std;

// swaps two VertexNodes
void swap(struct VertexNode *E1, struct VertexNode *E2){
	VertexNode temp = *E1;
	*E1 = *E2;
	*E2 = temp;
}

// identifies parent 
int parent(int i){
	int var1 = (i)/2; 
	return var1;
}

// identifies left child
int left(int i){
	int var2 = 2*i;//+1;
	return var2;
}

// identifies right child
int right(int i){
	int var3 = 2 * i+1;// + 2;
	return var3;
}

// indentifies the maximum of two nodes
int max(int a, int b){
	if (a>b) return a;
	else return b;
}
