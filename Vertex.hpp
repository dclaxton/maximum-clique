#include <vector>

class Vertex
{
public:
	int start;
	std::vector<int> clique, adjacency;
	Vertex(int _start)
	{
		start = _start;
	}
};