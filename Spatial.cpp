#include "Spatial.h"
#include <iostream>

using namespace std;

Spatial::Spatial(void)
{
	this->spatial = 0;


//   CPhidgetSpatial_set_OnSpatialData_Handler(this->spatial, SpatialDataHandler, NULL);
}

Spatial::~Spatial(void)
{
	CPhidget_delete((CPhidgetHandle)this->spatial);
}
