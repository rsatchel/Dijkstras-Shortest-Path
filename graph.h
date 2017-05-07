#ifndef GRAPH_H
#define GRAPH_H
#include <fstream>
//#define MAX_INT 32767
#include <climits>
using namespace std;


struct Vertex{
	int num;
	Vertex *next = NULL;
	int weight = INT_MAX;//MAX_INT;
	Vertex(int _num, int _weight){
		num = _num;
		weight = _weight;
	}
};


struct edgeList{
	Vertex *head = NULL;

	void addEdge(Vertex *v);	

	void printEdges();	
};

struct VertexNode{
	//static int num;// = -1;
	int num = -1;
	VertexNode *parent = NULL;
	int dist = INT_MAX;//MAX_INT;
	VertexNode(){};
};

struct Graph{
	VertexNode *vertices; 
	edgeList *EL;
	int numEdges;
	int numVertices;

	Graph(int size, int edges);

	void addEdge(int s, int t, int w);
	void printGraph();

};




void addEdge(Vertex *v);
void printEdges();
void addEdge(int s, int t, int w);
void printGraph();
void printPath(VertexNode *v);



//void printGraph();
void addEdge(int s, int t, int w);
Graph* readInGraph();

//void initializeSingleSource(Graph *g, VertexNode *source); 
//void relax(VertexNode *u, VertexNode *v, int weight, HEAP *A);
void dijkstraSP(Graph *g, VertexNode *s, VertexNode *t);
void dijkstraSP2(Graph *g, VertexNode *s, VertexNode *t);


#endif
