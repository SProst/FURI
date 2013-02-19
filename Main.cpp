#include <time.h>

#include "Edge.h"
#include "Utility.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "Spatial.h"
#include <list>
#include <fstream>
#include <iostream>

using namespace cv;
using namespace std;
using namespace phidgets;

	int main(int argc, char* argv[])
{
	//ofstream outputFile;
	//VideoCapture capture(0);
	//if(!capture.isOpened())
	//	return -1;

	Spatial spatial;

	Mat image, image2, cannyEdge, cannyEdge2;
	vector<Edge> listOfEdge;
	vector<Edge> listOfEdges2;
	int sum = 0;

	//string imagename = "C:\\Users\\Spencer\\Documents\\Visual Studio 2012\\Projects\\FURI\\x64\\Release\\High_Complexity.jpg";
	//string imagenameShifted = "C:\\Users\\Spencer\\Documents\\Visual Studio 2012\\Projects\\FURI\\x64\\Release\\High_Complexity_Shifted.jpg";
	//image = imread(imagename, CV_LOAD_IMAGE_GRAYSCALE);
	//image2 = imread(imagenameShifted,CV_LOAD_IMAGE_GRAYSCALE);

//	        for (;;)
//        {
//		//	CPhidgetSpatial_setDataRate(spatial, 16);
//            capture >> image;
//            if (image.empty())
//                break;
//			cv::cvtColor(image,image,CV_RGB2GRAY);
//			imshow("Video", image);
//
//			getchar();
//
//			capture >> image2;
//			if (image2.empty())
//				break;
//			imshow("Video Frame 2", image2);
//			cv::cvtColor(image2,image2,CV_RGB2GRAY);
//
//			char key = (char) waitKey(16); //delay 5 milli seconds, usually long enough to display and capture input
//
//			switch (key)
//            {	
//                case 'q':
//                case 'Q':
//                case 27: //escape key
//			printf("Closing...\n");
////			CPhidget_close((CPhidgetHandle)spatial);
////			CPhidget_delete((CPhidgetHandle)spatial);
//                    return 0;
//					break;
//                //case 'p': //Save an image
//                //    sprintf(filename, "filename%.3d.jpg", n++);
//                //    imwrite(filename, frame);
//                //    cout << "Saved " << filename << endl;
//                //    break;
//                default:
//                    break;
//            }
//		}
	//if(image.empty())
 //   {
 //       fprintf(stderr, "Cannot load image\n");
 //       return -1;
 //   }
	// if( !image.data ) // check if the image has been loaded properly
 //       return -1;
	// if(imagenameShifted.empty())
	// {
	//	 fprintf(stderr, "Cannot load image\n");
	//	 return -1;
	// }
	 //if(!image2.data )
		// return -1;
	//Mat grey(image.rows, image.cols, CV_8UC1);
	//Mat grey2(image2.rows, image2.cols, CV_8UC1);

	/*
	cvtColor(image, grey, CV_RGB2GRAY);
	cvtColor(image2, grey2, CV_RGB2GRAY);*/

	

	//try {
 //       imwrite("cannyEdge.jpg", cannyEdge);
	//	imwrite("cannyEdgeShifted.jpg", cannyEdge2);
 //   }
 //   catch (runtime_error& ex) {
 //       fprintf(stderr, "Exception converting image to JPG format: %s\n", ex.what());
 //       return 1;
 //   }

  // fprintf(stdout, "Saved PNG file with alpha data.\n");
/*	
	outputFile.open("outputFile.txt");
	outputFile << "Total Edges: " << listOfEdge.size() << endl;
	outputFile << "---------------------------" << endl;
	for(int i = 0; i < listOfEdge.size(); i++)
	{
		Edge edge = listOfEdge[i];
		for(int j = 0; j < listOfEdges2.size(); j++)
		{
			Edge edge2 = listOfEdges2[j];
			
			if(edge.getLength() == edge2.getLength())
			{
				for(int k = 0; k < edge.getLength(); k++)
				{
					sum += abs(edge.edgeVectorOriginal[k] - edge2.edgeVectorOriginal[k]);
				}
			}
			if(sum == 0)
			{
				outputFile << "SUM: " << sum << endl;
				outputFile << "SR" << "\t" << "SC" << endl;
				outputFile << edge.getStartEdgeRow() << "\t" << edge.getStartEdgeColumn() << endl;
				outputFile << "SHIFTED" << endl;
				outputFile << "SR" << "\t" << "SC" << endl;
				outputFile << edge2.getStartEdgeRow() << "\t" << edge.getStartEdgeColumn() << endl;
				outputFile << "--------" << endl;
			}
			sum = 0;
		}
	}

	float endTime = (float)clock()/CLOCKS_PER_SEC;

	
//	float timeElapsed = endTime - startTime;
//	outputFile << "Time Elapsed: " << timeElapsed << endl;

	outputFile.close();
	*/
	cout << "END OF PROGRAM" << endl;

	// imshow("Edge" , cannyEdge);
	// imshow("Edge2", cannyEdge2);
	waitKey();
	getchar();
    return 0;
}





