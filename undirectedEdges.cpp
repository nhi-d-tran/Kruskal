
class undirectedEdge
{
public:
	int Ni;			// and integer from 1 to N
	int Nj;			// and integer from 1 to N
	int edgeCost;	// a positive integer > 0
	undirectedEdge* next;

	undirectedEdge()
	{
		Ni = 0;
		Nj = 0;
		edgeCost = 0;
		next = NULL;
	}

	undirectedEdge(int i, int j, int cost)
	{
		this->Ni = i;
		this->Nj = j;
		this->edgeCost = cost;
		next = NULL;
	}

	void printEdge()
	{
		cout << Ni << " " << Nj  << " " << edgeCost << endl;
	}

	~undirectedEdge()
	{
		Ni = 0;
		Nj = 0;
		edgeCost = 0;
		next = NULL;
	}
};