#include "Spatial.h"
#include <iostream>

using namespace phidgets; 
using namespace std;

namespace phidgets {

Spatial::Spatial(void):
	Phidget(),
	spatial_handle_(0)
{
	CPhidgetSpatial_create(&spatial_handle_);
	Phidget::init((CPhidgetHandle) spatial_handle_);
	Phidget::registerHandlers();
	CPhidgetSpatial_set_OnSpatialData_Handler(spatial_handle_, SpatialDataHandler, this);
	
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

void Spatial::dataHandler(CPhidgetSpatial_SpatialEventDataHandle *data, int count)
{
	cout << "Empty data handler" << endl;
}

Spatial::~Spatial(void)
{
}
}