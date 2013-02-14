#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv\cv.h"
#include <time.h>
#include <phidget21.h>
#include "Edge.h"
#include "Utility.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>

using namespace cv;
using namespace std;


//callback that will run if the Spatial is attached to the computer
int CCONV AttachHandler(CPhidgetHandle spatial, void *userptr)
{
	int serialNo;
	CPhidget_getSerialNumber(spatial, &serialNo);
	printf("Spatial %10d attached!", serialNo);

	return 0;
}

//callback that will run if the Spatial is detached from the computer
int CCONV DetachHandler(CPhidgetHandle spatial, void *userptr)
{
	int serialNo;
	CPhidget_getSerialNumber(spatial, &serialNo);
	printf("Spatial %10d detached! \n", serialNo);

	return 0;
}

//callback that will run if the Spatial generates an error
int CCONV ErrorHandler(CPhidgetHandle spatial, void *userptr, int ErrorCode, const char *unknown)
{
	printf("Error handled. %d - %s \n", ErrorCode, unknown);
	return 0;
}

//callback that will run at datarate
//data - array of spatial event data structures that holds the spatial data packets that were sent in this event
//count - the number of spatial data event packets included in this event
int CCONV SpatialDataHandler(CPhidgetSpatialHandle spatial, void *userptr, CPhidgetSpatial_SpatialEventDataHandle *data, int count)
{
	int i;
	printf("Number of Data Packets in this event: %d\n", count);
	for(i = 0; i < count; i++)
	{
		printf("=== Data Set: %d ===\n", i);
		printf("Acceleration> x: %6f  y: %6f  x: %6f\n", data[i]->acceleration[0], data[i]->acceleration[1], data[i]->acceleration[2]);
		printf("Angular Rate> x: %6f  y: %6f  x: %6f\n", data[i]->angularRate[0], data[i]->angularRate[1], data[i]->angularRate[2]);
		printf("Magnetic Field> x: %6f  y: %6f  x: %6f\n", data[i]->magneticField[0], data[i]->magneticField[1], data[i]->magneticField[2]);
		printf("Timestamp> seconds: %d -- microseconds: %d\n", data[i]->timestamp.seconds, data[i]->timestamp.microseconds);
	}

	printf("---------------------------------------------\n");

	return 0;
}

//Display the properties of the attached phidget to the screen.  
//We will be displaying the name, serial number, version of the attached device, the number of accelerometer, gyro, and compass Axes, and the current data rate
// of the attached Spatial.
int display_properties(CPhidgetHandle phid)
{
	int serialNo, version;
	const char* ptr;
	int numAccelAxes, numGyroAxes, numCompassAxes, dataRateMax, dataRateMin;

	CPhidget_getDeviceType(phid, &ptr);
	CPhidget_getSerialNumber(phid, &serialNo);
	CPhidget_getDeviceVersion(phid, &version);
	CPhidgetSpatial_getAccelerationAxisCount((CPhidgetSpatialHandle)phid, &numAccelAxes);
	CPhidgetSpatial_getGyroAxisCount((CPhidgetSpatialHandle)phid, &numGyroAxes);
	CPhidgetSpatial_getCompassAxisCount((CPhidgetSpatialHandle)phid, &numCompassAxes);
	CPhidgetSpatial_getDataRateMax((CPhidgetSpatialHandle)phid, &dataRateMax);
	CPhidgetSpatial_getDataRateMin((CPhidgetSpatialHandle)phid, &dataRateMin);

	

	printf("%s\n", ptr);
	printf("Serial Number: %10d\nVersion: %8d\n", serialNo, version);
	printf("Number of Accel Axes: %i\n", numAccelAxes);
	printf("Number of Gyro Axes: %i\n", numGyroAxes);
	printf("Number of Compass Axes: %i\n", numCompassAxes);
	printf("datarate> Max: %d  Min: %d\n", dataRateMax, dataRateMin);

	return 0;
}

CPhidgetSpatialHandle InitializeSpatialSensor()
{
	int result;
	const char *err;

	//Declare a spatial handle
	CPhidgetSpatialHandle spatial = 0;

	//create the spatial object
	CPhidgetSpatial_create(&spatial);

	//Set the handlers to be run when the device is plugged in or opened from software, unplugged or closed from software, or generates an error.
	CPhidget_set_OnAttach_Handler((CPhidgetHandle)spatial, AttachHandler, NULL);
	CPhidget_set_OnDetach_Handler((CPhidgetHandle)spatial, DetachHandler, NULL);
	CPhidget_set_OnError_Handler((CPhidgetHandle)spatial, ErrorHandler, NULL);

	//Registers a callback that will run according to the set data rate that will return the spatial data changes
	//Requires the handle for the Spatial, the callback handler function that will be called, 
	//and an arbitrary pointer that will be supplied to the callback function (may be NULL)
	CPhidgetSpatial_set_OnSpatialData_Handler(spatial, SpatialDataHandler, NULL);

	//open the spatial object for device connections
	CPhidget_open((CPhidgetHandle)spatial, -1);

	//get the program to wait for a spatial device to be attached
	printf("Waiting for spatial to be attached.... \n");
	if((result = CPhidget_waitForAttachment((CPhidgetHandle)spatial, 10000)))
	{
		CPhidget_getErrorDescription(result, &err);
		printf("Problem waiting for attachment: %s\n", err);
		return 0;
	}
	else
		return spatial;
}

int spatial_simple()
{
	int result;
	const char *err;

	//Declare a spatial handle
	CPhidgetSpatialHandle spatial = 0;

	//create the spatial object
	CPhidgetSpatial_create(&spatial);

	//Set the handlers to be run when the device is plugged in or opened from software, unplugged or closed from software, or generates an error.
	CPhidget_set_OnAttach_Handler((CPhidgetHandle)spatial, AttachHandler, NULL);
	CPhidget_set_OnDetach_Handler((CPhidgetHandle)spatial, DetachHandler, NULL);
	CPhidget_set_OnError_Handler((CPhidgetHandle)spatial, ErrorHandler, NULL);

	//Registers a callback that will run according to the set data rate that will return the spatial data changes
	//Requires the handle for the Spatial, the callback handler function that will be called, 
	//and an arbitrary pointer that will be supplied to the callback function (may be NULL)
	CPhidgetSpatial_set_OnSpatialData_Handler(spatial, SpatialDataHandler, NULL);

	//open the spatial object for device connections
	CPhidget_open((CPhidgetHandle)spatial, -1);

	//get the program to wait for a spatial device to be attached
	printf("Waiting for spatial to be attached.... \n");
	if((result = CPhidget_waitForAttachment((CPhidgetHandle)spatial, 10000)))
	{
		CPhidget_getErrorDescription(result, &err);
		printf("Problem waiting for attachment: %s\n", err);
		return 0;
	}

	//Display the properties of the attached spatial device
	display_properties((CPhidgetHandle)spatial);

	//read spatial event data
	printf("Reading.....\n");
	
	//Set the data rate for the spatial events
	CPhidgetSpatial_setDataRate(spatial, 16);

	//run until user input is read
	printf("Press any key to end\n");
	getchar();

	//since user input has been read, this is a signal to terminate the program so we will close the phidget and delete the object we created
	printf("Closing...\n");
	CPhidget_close((CPhidgetHandle)spatial);
	CPhidget_delete((CPhidgetHandle)spatial);

	return 0;
}


/*void Compute(Mat &image, Mat &image2, vector<Edge>& listOfEdge, vector<Edge>& listOfEdges2)
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

	int main(int argc, char* argv[])
{
	ofstream outputFile;
	VideoCapture capture(0);
	if(!capture.isOpened())
		return -1;

	Mat image, image2, cannyEdge, cannyEdge2;
	vector<Edge> listOfEdge;
	vector<Edge> listOfEdges2;
	int sum = 0;
	CPhidgetSpatialHandle spatial = InitializeSpatialSensor();
	//string imagename = "C:\\Users\\Spencer\\Documents\\Visual Studio 2012\\Projects\\FURI\\x64\\Release\\High_Complexity.jpg";
	//string imagenameShifted = "C:\\Users\\Spencer\\Documents\\Visual Studio 2012\\Projects\\FURI\\x64\\Release\\High_Complexity_Shifted.jpg";
	//image = imread(imagename, CV_LOAD_IMAGE_GRAYSCALE);
	//image2 = imread(imagenameShifted,CV_LOAD_IMAGE_GRAYSCALE);

	        for (;;)
        {
			CPhidgetSpatial_setDataRate(spatial, 16);
            capture >> image;
            if (image.empty())
                break;
			cv::cvtColor(image,image,CV_RGB2GRAY);
			imshow("Video", image);
			char key = (char) waitKey(5); //delay 5 milli seconds, usually long enough to display and capture input
			switch (key)
            {
			case 'c':
			case 'C':
				capture >> image2;
			if (image2.empty())
				break;
			imshow("Video Frame 2", image2);
			cv::cvtColor(image2,image2,CV_RGB2GRAY);
			break; 
                case 'q':
                case 'Q':
                case 27: //escape key
			printf("Closing...\n");
			CPhidget_close((CPhidgetHandle)spatial);
			CPhidget_delete((CPhidgetHandle)spatial);
                    return 0;
					break;
                //case 'p': //Save an image
                //    sprintf(filename, "filename%.3d.jpg", n++);
                //    imwrite(filename, frame);
                //    cout << "Saved " << filename << endl;
                //    break;
                default:
                    break;
            }
		}
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
    return 0;
}





