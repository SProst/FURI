#include "Edge.h"


Edge::Edge(void)
{
		startEdgeRow = -1;
		startEdgeColumn = -1;
		endEdgeRow = -1;
		endEdgeColumn = -1;
		length = -1;
		edgeSumCanny = 0;
		edgeSumOriginal = 0;
		edgeVectorCanny.clear();
		edgeVectorOriginal.clear();
}


Edge::~Edge(void)
{
}

int Edge::getStartEdgeRow()
{
	return startEdgeRow;
}

int Edge::getStartEdgeColumn()
{
	return startEdgeColumn;
}

int Edge::getEndEdgeRow()
{
	return endEdgeRow;
}

int Edge::getEndEdgeColumn()
{
	return endEdgeColumn;
}

int Edge::getLength()
{
	return length;
}
