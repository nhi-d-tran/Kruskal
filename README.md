# Kruskal


Kruskal’s algorithm for finding the Minimum Spanning Tree of a giving undirected graph

Problem: Given an undirected graph, G = <N, E>, the task is find
a minimum spanning tree of G, using the Kruskal’s algorithm.


I.	Input (argv[1])

An undirected graph, represented by a list of edges with costs, <ni, nj, c>, where the first text line is the number of nodes, N, in G, follows by a list of triplets, <ni, nj, cost>

For example:

		5	// there are 5 nodes in the graph 
    
		1  5 10 // an undirected edge: i.e.,  an edge <1, 5, 10> and an edge <5, 1, 10>
    
    	2  3  5 // an undirected edge: i.e.,  an edge <2, 3, 5> and an edge <3, 2, 5>
        
     	1  2  20 // an undirected edge: i.e.,   an edge <1, 2, 20> and an edge <2, 1, 20>
        
		3  5  2 // an undirected edge: i.e.,  an edge <3, 5, 2> and an edge < 5, 3, 2>


II.	

1) Output-1 ( argv[2]): 

A minimum spanning tree (MST) of G, represented by a list of undirected edges with costs where the first text line is the number nodes, N, follows by the list of edges with costs in MST of G plus the total cost of the MST.


2)	Output-2 (argv[3]) : For all debugging outputs. 
