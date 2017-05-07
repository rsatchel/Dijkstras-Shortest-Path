//#ifndef GRAPH_H
//#define GRAPH_H
#include<iostream>
#include "graph.h"
#include "heap.h"

using namespace std;

// add an edge to an existing vertex
void edgeList::addEdge(Vertex *v){
	v->next = head;
	head = v;
}

// print out a list of all of the edges with their weights
void edgeList::printEdges(){
	Vertex *current = head;
	while (current != NULL) {
		cout << "(" << current->num << " " << current->weight << ") " ;
		current = current->next;
	}

}


// create new graph passing it the size and edges
Graph::Graph(int size, int edges) {
	EL  = new edgeList[size];
	for (int i = 0; i < size; i++) {
		EL[i].head == NULL;		
	}
	// create a new vertex using "size" parameter
	vertices = new VertexNode[size];	
	for (int i = 0; i < size; i++) {
		// initialise all vertices to "infinity"
		vertices[i].num = i+1;	
		vertices[i].dist = INT_MAX;//MAX_INT;	
	}
	// read in the edges and size to the constructor
	numEdges = edges;
	numVertices = size;
}

// add an edge to an existing graph
void Graph::addEdge(int s, int t, int w) {
	// create a new vertex
	Vertex *v = new Vertex(t, w);
	// and add an edge
	EL[s-1].addEdge(v); 
}

// print out the contents of the graph
void Graph::printGraph(){
	//print out the number of vertices and edges
	cout << numVertices << " " << numEdges << endl;
	// traverse the graph and print out all of the edges
	for (int i = 0; i< numVertices; i++){
		cout << i+1 << " : ";
		EL[i].printEdges();
		cout << endl;
	}
	
}


// read in data from specified file
Graph* readInGraph() {

	string input;
	ifstream inputGraph("GRAPHinput.txt");
	// check if file is valid and open
	if(inputGraph.is_open()){
		int vertices, edges;
		// read in the vertice and edges data
		inputGraph >> vertices >> edges;
		// create a new graph with the data provided
		Graph *graph = new Graph(vertices, edges);
		
		for(int i=0; i<edges; i++) {
			//Read in source, target and weight
			int source, target, weight;
			inputGraph >> source >> target >> weight;

			//Add edges
			graph->addEdge(source, target, weight);
		}
		return graph;
	}

	else {
	cout << "Unable to open file!!\n\n" << endl; 
	return NULL;
	}
}

// initialise just one source vertex to distance "infinity" (INT_MAX MAX_INT) and parent is NULL
void initializeSingleSource(Graph *g, VertexNode *source){
	// traverse the total number of vertices and set distance to "infinity"
	for (int i = 0; i < g->numVertices; i++) {
		g->vertices[i].dist = INT_MAX;//MAX_INT;
		g->vertices[i].parent = NULL;	
	}
	// set the source distance to 0
	source->dist = 0;

}

// relax the edge between two specified vertices
void relax(VertexNode *u, VertexNode *v, int weight, HEAP *A){	
	// check for lowest distance
	if(v->dist > (u->dist + weight)){
		// go through the heap
		for(int i = 0; i< A->size; i++){
			// checking if we need to decrease the key
			if (A->E[i].num == v->num){
				//decrease key source dist + its weight
				v->dist  = u->dist + weight;
				// make v's parent u
				v->parent = u;
				// decrease key starting at index 1 (not 0)
				decreaseKey(A, i+1, u->dist + weight);	
				return;
			}
		} 
		cout << "ERROR: Could not find matching VertexNode in graph" << endl;
	}

}


// compute shortest path between two vertices
void dijkstraSP(Graph *g, VertexNode *s, VertexNode *t){
	// initialise the graph source node
	initializeSingleSource(g, s);
	// initialise heap for the number of vertices
	HEAP *myHeap = initialize(g->numVertices); 
	// build the heap
	buildHeap(myHeap, g->vertices, g->numVertices); 	

	while(myHeap->size != 0){
		// go throught the heap and extract the min 
		VertexNode *u = deleteMin(myHeap);	
		Vertex *v = (g->EL[u->num-1]).head;

		while (v != NULL) {	
			// go through the vertices and relax them	
			relax(&g->vertices[u->num-1], &g->vertices[v->num-1], v->weight, myHeap);
			//Go to next vertex (describes a connection)
			v = v->next; 
		}	
		// if the ID is the same then break
		if (u->num == t->num)
			break;
	}
	// free the memory
	delete myHeap;
}

// compute shortest path between two vertices and print resulting heap
void dijkstraSP2(Graph *g, VertexNode *s, VertexNode *t){
	// initialise the graph source node
	initializeSingleSource(g, s);
	// initialise heap for the number of vertices
	HEAP *myHeap = initialize(g->numVertices); 
	buildHeap(myHeap, g->vertices, g->numVertices); 	
	
	while(myHeap->size != 0){
	// go throught the heap and extract the min 
		VertexNode *u = deleteMin(myHeap);	
		Vertex *v = (g->EL[u->num-1]).head;

		while (v != NULL) {		
			// go through the vertices and relax them	
			relax(&g->vertices[u->num-1], &g->vertices[v->num-1], v->weight, myHeap);
			//Go to next vertex (describes a connection)
			v = v->next; 
		}
		// if the ID is the same then break
		if (u->num == t->num)
			break;	
	}
	
	//Print total distance
	cout << g->vertices[t->num-1].dist << endl;
			
	//Print path
	printPath(&g->vertices[t->num-1]); 
	cout << endl;

	//Print Heap
	printHeap(myHeap);

	// free memory
	delete myHeap;
}

// recursively prints path taken by Dijkstras
void printPath(VertexNode *v) {
	if (v != NULL){ 
		printPath(v->parent);
		cout << v->num << " " ;
	}
}







