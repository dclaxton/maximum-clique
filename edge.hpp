class Edge
{
	int start, destination, weight;

public:
	Edge(int _start, int _destination, int _weight)
	{
		start = _start;
		destination = _destination;
		weight = _weight;
	}

	int getStart()
	{
		return start;
	}
	void setStart(int s)
	{
		start = s;
	}
	int getDest()
	{
		return destination;
	}
	void setDest(int d)
	{
		destination = d;
	}
	int getWeight()
	{
		return weight;
	}
	void setWeight(int w)
	{
		weight = w;
	}
};