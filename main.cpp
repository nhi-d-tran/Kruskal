#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
	ifstream inFile;
	ofstream outFile1;
	ofstream outFile2;

	inFile.open(argv[1]);
	outFile1.open(argv[2]);
	outFile2.open(argv[3]);

	// if not the right file
	if (!inFile)
	{
		cout << "ERROR open file";
		exit(1);
	}
	int node;
	inFile >> node;
	KruskalMST* kruskal = NULL;
	undirectedEdge* newEdge = NULL;
	kruskal = new KruskalMST(node);
	outFile2 << "PrintSet for inWhichSet: " << endl;
	kruskal->printSet(kruskal->inWhichSet, outFile2);

	int Ni, Nj, edgeCost;
	outFile2 << "PrintList in ascending order: " << endl;
	while(!inFile.eof())
	{
		inFile >> Ni >> Nj >> edgeCost;
		newEdge = new undirectedEdge(Ni, Nj, edgeCost);
		kruskal->insertEdge(newEdge);
		kruskal->printList(kruskal->edgeListHead, outFile2);
	}
	outFile2 << endl;

	undirectedEdge* nextEdge = NULL;

	while(kruskal->numSet != 1)
	{
		do
		{
			nextEdge = kruskal->removedEdge(kruskal->edgeListHead);
		}
		while(kruskal->inWhichSet[nextEdge->Ni] == kruskal->inWhichSet[nextEdge->Nj]);

		kruskal->pushEdge(nextEdge);
		kruskal->totalMSTCost += nextEdge->edgeCost;
		kruskal->merge2Sets(nextEdge->Ni, nextEdge->Nj);
		kruskal->numSet--;
		outFile2 << "Print inWhichSet array after merge: " << endl;
		kruskal->printSet(kruskal->inWhichSet, outFile2);
		outFile2 << "Print information of node: " << endl;
		kruskal->printList(kruskal->MSTofG, outFile2);
	}
	outFile1 << "Output the entire MSTofG: " << endl;
	kruskal->printList(kruskal->MSTofG, outFile1);
	outFile1 << endl;
	outFile1 << "Print the totalCost: " << kruskal->totalMSTCost << endl;;

	inFile.close();
	outFile1.close();
	outFile2.close();

	return 0;
}
