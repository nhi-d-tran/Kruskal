class graphNode
{
public:
	int nodeID;		// an integer from 1 to N
	graphNode* next;

	//constructor
	graphNode(int id)
	{
		nodeID = id;
		next = NULL;
	}

	//destructor
	~graphNode()
	{
		nodeID = 0;
		delete[] next;
	}
};
