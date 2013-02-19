#include "Spatial.h"
#include <iostream>

using namespace phidgets; 
using namespace std;

namespace phidgets {

Spatial::Spatial(void):
	Phidget(),
	spatial_handle_(0)
{
	int result;
	CPhidgetSpatial_create(&spatial_handle_);
	Phidget::init((CPhidgetHandle) spatial_handle_);
	Phidget::registerHandlers();
//	CPhidgetSpatial_set_OnSpatialData_Handler(spatial_handle_, SpatialDataHandler, this);
//	CPhidget_open((CPhidgetHandle)spatial_handle_,-1);
	Phidget::open();

	printf("Waiting for spatial to be attached.... \n");
	if((result = waitForAttachment(10000)))
	{
		printf("Problem waiting for attachment \n");
	}
}

void Spatial::zero()
{
	// zero (calibrate) gyro
	CPhidgetSpatial_zeroGyro(spatial_handle_);
}

int CCONV Spatial::SpatialDataHandler(CPhidgetSpatialHandle handle, void *userptr, CPhidgetSpatial_SpatialEventDataHandle *data, int count)
{
	((Spatial*)userptr)->dataHandler(data, count);
	return 0;
}

void Spatial::setDataRate(int rate)
{
	CPhidgetSpatial_setDataRate(spatial_handle_, rate);
}

void Spatial::dataHandler(CPhidgetSpatial_SpatialEventDataHandle *data, int count)
{
	cout << "Empty data handler" << endl;
}

Spatial::~Spatial(void)
{
}
}