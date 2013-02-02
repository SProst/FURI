#pragma once
#include <vector>
using namespace std;

class Edge
{
public:
	Edge(void);
	int getStartEdgeRow();
	int getStartEdgeColumn();
	int getEndEdgeRow();
	int getEndEdgeColumn();
	void setStartEdgeRow(int row);
	void setStartEdgeColumn(int column);
	void setLength(int length);
	int getLength();
	int getEdgeSumCanny();
	int getEdgeSumOriginal();

	virtual ~Edge(void);
private:
	int startEdgeRow;
	int startEdgeColumn;
	int endEdgeRow;
	int endEdgeColumn;
	int length;
	int edgeSumCanny;
	int edgeSumOriginal;
	vector<int> edgeVectorCanny;
	vector<int> edgeVectorOriginal;
};

