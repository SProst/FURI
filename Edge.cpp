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
/*
Edge::compute(void)
{
	Mat cannyEdge, cannyEdge2;
	Mat greyGaussian(image.rows, image.cols, CV_8UC1);
	Mat greyGaussian2(image2.rows, image2.cols, CV_8UC1);

	GaussianBlur(image,greyGaussian, Size(3,3) ,0,0);
	GaussianBlur(image2, greyGaussian2, Size(3,3),0,0 );

	//Mat edge(grey.rows, grey.cols, CV_8UC1);
	//Mat edge2(grey2.rows, grey2.cols, CV_8UC1);
	Canny(greyGaussian,cannyEdge,25,100,3);
	Canny(greyGaussian2,cannyEdge2,25,100,3);

//	float startTime = (float)clock()/CLOCKS_PER_SEC;

	for(int y = 0; y < cannyEdge.rows; y++)
	{
		Edge edge;

		for(int x = 0; x < cannyEdge.cols; x++)
		{
				Scalar u = cannyEdge.at<uchar>(y,x);
				Scalar v = image.at<uchar>(y,x);
			//	cout << u.val[0] << ", ";
				if(u.val[0] > 0 && edge.getStartEdgeRow == -1)
				{
					edge.startEdgeRow = y;
					edge.startEdgeColumn = x;
					edge.edgeVectorCanny.push_back(u.val[0]);
					edge.edgeVectorOriginal.push_back(v.val[0]);
				}
				if(u.val[0] > 0 && edge.startEdgeRow != -1)
				{
					edge.edgeVectorCanny.push_back(u.val[0]);
					edge.edgeVectorOriginal.push_back(v.val[0]);
				}
				else if(edge.startEdgeRow != -1)
				{
					edge.endEdgeRow = y;
					edge.endEdgeColumn = x;
					edge.length = edge.edgeVectorCanny.size();
				}
		}
			if(edge.length > 10)
				{
					for(int i = 0; i < edge.edgeVectorCanny.size(); i++)
					{
						edge.edgeSumCanny += edge.edgeVectorCanny[i];
					}
					for(int j = 0; j < edge.edgeVectorOriginal.size(); j++)
					{
						edge.edgeSumOriginal += edge.edgeVectorOriginal[j];
					}
				/*	cout << "Canny Edge Sum: " << edge.edgeSumCanny << endl;
					cout << "Original Image Greyscale Sum: " << edge.edgeSumOriginal << endl; 
					listOfEdge.push_back(edge);
				}
	}

	for(int y = 0; y < cannyEdge2.rows; y++)
	{
		Edge edge = InitializeEdge();

		for(int x = 0; x < cannyEdge2.cols; x++)
		{
				Scalar u = cannyEdge2.at<uchar>(y,x);
				Scalar v = image2.at<uchar>(y,x);
			//	cout << u.val[0] << ", ";
				if(u.val[0] > 0 && edge.startEdgeRow == -1)
				{
					edge.startEdgeRow = y;
					edge.startEdgeColumn = x;
					edge.edgeVectorCanny.push_back(u.val[0]);
					edge.edgeVectorOriginal.push_back(v.val[0]);
				}
				if(u.val[0] > 0 && edge.startEdgeRow != -1)
				{
					edge.edgeVectorCanny.push_back(u.val[0]);
					edge.edgeVectorOriginal.push_back(v.val[0]);
				}
				else if(edge.startEdgeRow != -1)
				{
					edge.endEdgeRow = y;
					edge.endEdgeColumn = x;
					edge.length = edge.edgeVectorCanny.size();
				}
		}
			if(edge.length > 10)
				{
					for(int i = 0; i < edge.edgeVectorCanny.size(); i++)
					{
						edge.edgeSumCanny += edge.edgeVectorCanny[i];
					}
					for(int j = 0; j < edge.edgeVectorOriginal.size(); j++)
					{
						edge.edgeSumOriginal += edge.edgeVectorOriginal[j];
					}
				/*	cout << "Canny Edge Shifted Sum: " << edge.edgeSumCanny << endl;
					cout << "Original Image Shifted Greyscale Sum: " << edge.edgeSumOriginal << endl; 
					listOfEdges2.push_back(edge);
				}
	}
} */