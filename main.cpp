// main.cpp

#include <iostream>
#include "heap.h"
#include "graph.h"
#include "util.h"
#include <stdlib.h>
using namespace std;

struct HEAP *x;
Graph *graph;

int main(){
	char command;
	int s, t;
	cout << endl << "CSE310 Assignment 3" << endl;
	cout << "Shortest Path" << endl << endl;
	
	// prompts user for commands
	// S = STOP
	// R = Read in array from text file HEAPinput.txt
	// W = Write heap information (capacity, size and elements) to screen)
	// P = Compute Dijkstras shortest path 
	// Q = Compute Dijkstras shortest path and provide resulting heap
	do{
	cin >> command;
	switch(command){
/////////////////////////////////////////////////////////////////
		case 'S':
		cout << "STOP" << "\n" << endl;
		break;

/////////////////////////////////////////////////////////////////

		case 'R':
		graph = readInGraph();
		break;

/////////////////////////////////////////////////////////////////

		case 'W':
		if (graph != NULL) {
			graph->printGraph();
		}
		else cout << "No graph to write!" << endl;
		break;

///////////////////////////////////////////////////////////////////

		case 'P': 
		cin >> s >> t;
		//Check if s or t are out of bounds
		if (s < 1 || t < 1 || s > graph->numVertices || t > graph->numVertices){
			cout << "src/dest index out of range!" << endl; 
			break;		
		}

		//Call algorithm
		dijkstraSP(graph, &graph->vertices[s-1], &graph->vertices[t-1]);

		//Print total distance
		cout << graph->vertices[t-1].dist << endl;
				
		//Print path
		printPath(&graph->vertices[t-1]); 
		cout << endl;

		break;

///////////////////////////////////////////////////////////////////////////////////////

		case 'Q':					
		cin >> s >> t;

		//Check if s or t are out of bounds
		if (s < 1 || t < 1 || s > graph->numVertices || t > graph->numVertices){
			cout << "src/dest index out of range!" << endl; 
			break;		
		}

		//Call algorithm
		dijkstraSP2(graph, &graph->vertices[s-1], &graph->vertices[t-1]);

		break;

////////////////////////////////////////////////////////////////////////////////////////////

		default:
		cout << "Enter a valid command..." << "\n" << endl;
		break;
			
	}
	}while (command != 'S');

	return 0;
}
