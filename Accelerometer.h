#pragma once
#include <phidget21.h>
#include <iostream>
using namespace std;

class Accelerometer
{
public:
	Accelerometer(void);
	int CCONV AttachHandler(CPhidgetHandle spatial, void *userptr);
	int CCONV DetachHandler(CPhidgetHandle spatial, void *userptr);
	int CCONV ErrorHandler(CPhidgetHandle spatial, void *userptr, int ErrorCode, const char *unknown);
	int CCONV SpatialDataHandler(CPhidgetSpatialHandle spatial, void *userptr, CPhidgetSpatial_SpatialEventDataHandle *data, int count);
	int display_properties(CPhidgetHandle phid);
	int spatial_simple();

	virtual ~Accelerometer(void);
};

