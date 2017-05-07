# Dijkstras-Shortest-Path
Dijkstra's Shortest Path for a directed edge weight graph. 

From command line program takes 4 different commands: 

S (Stop)

R reads in an edge weighted directed graph from file GRAPHinput.txt to 
build the adjacency lists, and waits for the next command). 
The file GRAPHinput.txt is a text file. 
The first line of the file contains two integers n and m, 
which indicates the number of vertices and the number of edges 
on the graph, respectively. 
It is followed by m lines, where each line contains three 
integers: u, v, and w. 
These three integers indicate the information of an 
edge: there is an edge pointing from u to v, with weight w. 
Note that the vertices of the graph are indexed from 1 to n 
(not from 0 to n − 1).

W, the program writes the graph information to the screen, and 
waits for the next command. 
The screen output format of W is as follows: The first line 
contains two integers, n and m, where n is the number of 
vertices and m is the number of edges. It is followed 
by n lines, where each of these n lines has the following 
format: u : (v1 w1) (v2 w2) ... (vx, wx)

P s t, the program runs Dijkstra’s shortest path algorithm to 
compute a shortest s-t path, and prints out the shortest path 
information from s to t to the screen, and waits for the 
next command. The screen output format of P s t is as 
follows: There are two lines. 
The first line contains an integer dist, which is the 
length of the shortest path computed. The next line contains 
the indexes of all vertices along the path direction, 
starting from src and ending with dest, in format 
of: s v1 v2 ... t 
The program reads in only one graph, but may be asked to 
compute s-t shortest paths for different pairs of s and t. 
Therefore, during the computation of the s-t shortest path, 
the program does not modify the given graph.

Q s t. On reading Q s t, the program computes and outputs the 
shortest s-t path, as in the case of P s t. In addition, it 
prints out the content of the heap (after relaxations along s 
to its neighbors are done). Here it lists the ID’s of the 
corresponding vertex at heap location i, for i = 1, 2, . . ..
