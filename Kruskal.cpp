class KruskalMST
{
public:
	int numNodes; 			// number of nodes in G
	int* inWhichSet;			// 1-D array, size of N + 1
	int numSet;
	int totalMSTCost;
	undirectedEdge* MSTofG;		// the head of a linked list stack
	undirectedEdge* edgeListHead;	// the head of a linked list

	KruskalMST(int N)
	{
		numNodes = N;
		numSet = numNodes;
		inWhichSet = new int[numNodes + 1];
		totalMSTCost = 0;
		edgeListHead = new undirectedEdge();
		MSTofG = new undirectedEdge();

		for(int i = 1; i < numNodes + 1; i++)
		{
			inWhichSet[i] = i;
		}
	}

	~KruskalMST()
	{
		delete[] inWhichSet;
	}

	void insertEdge(undirectedEdge* newEdge)
	{
		undirectedEdge* current = edgeListHead;

		if(current->next == NULL)
		{
			current->next = newEdge;
		}
		else
		{
			while(current->next != NULL && current->next->edgeCost < newEdge->edgeCost)
			{
				current = current->next;
			}
			undirectedEdge* temp = current->next;
			current->next = newEdge;
			newEdge->next = temp;
		}
	}

	undirectedEdge* removedEdge(undirectedEdge* edgeListHead)
	{
		undirectedEdge* current = edgeListHead->next;
		edgeListHead->next = current->next;
		return current;
	}

	void pushEdge(undirectedEdge* nextEdge)
	{
		undirectedEdge* current = MSTofG;

		while(current->next != NULL)
		{
			current = current->next;
		}
		nextEdge->next = current->next;
		current->next = nextEdge;
	}

	void merge2Sets(int i, int j)
	{
		if(inWhichSet[i] < inWhichSet[j])
		{
			int temp = inWhichSet[j];

			for(int k = 1; k < numNodes + 1; k++)
			{
				if(inWhichSet[k] == temp)
				{
					inWhichSet[k] = inWhichSet[i];
				}
			}
		}
		else
		{
			int temp = inWhichSet[i];

			for(int k = 1; k < numNodes + 1; k++)
			{
				if(inWhichSet[k] == temp)
				{
					inWhichSet[k] = inWhichSet[j];
				}
			}
		}
	}

	void printSet(int* inWhichSet, ofstream& outFile)
	{
		for(int i = 1; i < numNodes + 1; i++)
		{
			outFile << inWhichSet[i] << " ";
		}
		outFile << endl;
		outFile << endl;
	}

	void printList(undirectedEdge* edgeListHead, ofstream &outFile)
	{
		undirectedEdge* current = edgeListHead;
		while(current != NULL)
		{
			if(current->next == NULL)
			{
				outFile << "<" << current->Ni <<", " << current->Nj << ", " << current->edgeCost << ">";
				outFile << endl;
				outFile << "==============" << endl;
			}
			else
			{

				outFile<< "<" << current->Ni <<", " << current->Nj << ", " << current->edgeCost << ">" << endl;
			}
			current = current->next;
		}
		outFile << endl;
	}
};