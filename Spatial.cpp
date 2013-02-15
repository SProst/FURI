#include "Spatial.h"
#include "phidget21.h"
#include <iostream>

using namespace std;

Spatial::Spatial(void)
{
	this-> spatial = 0;
	 CPhidgetSpatial_create(&this->spatial);
	   CPhidget_set_OnAttach_Handler((CPhidgetHandle)this->spatial, AttachHandler, NULL);
  CPhidget_set_OnDetach_Handler((CPhidgetHandle)this->spatial, DetachHandler, NULL);
  CPhidget_set_OnError_Handler((CPhidgetHandle)this->spatial, ErrorHandler, NULL);

   CPhidgetSpatial_set_OnSpatialData_Handler(this->spatial, SpatialDataHandler, NULL);
}

int Spatial::AttachHandler(CPhidgetHandle spatial, void *userptr)
{
	int serialNo;
	CPhidget_getSerialNumber(spatial, &serialNo);
	cout << "Spatial" << serialNo << "attached" << endl;
}


Spatial::~Spatial(void)
{
	CPhidget_delete((CPhidgetHandle)this->spatial);
}
