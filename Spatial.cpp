#include "Spatial.h"
#include <iostream>

using namespace std;

int CCONV AttachHandler(CPhidgetHandle spatial, void *userptr)
{
	((Spatial*)userptr)->attachHandler();

	return 0;
}

int CCONV DetachHandler(CPhidgetHandle spatial, void *userptr)
{
	((Spatial*)userptr)->detachHandler();
	return 0;
}

int CCONV ErrorHandler(CPhidgetHandle handle, void *userptr, int ErrorCode, const char *unknown)
{
	((Spatial*)userptr)->errorHandler(ErrorCode);
	return 0;
}
Spatial::Spatial(void)
{
	this->spatial = 0;


//   CPhidgetSpatial_set_OnSpatialData_Handler(this->spatial, SpatialDataHandler, NULL);
}

void Spatial::registerHandlers(void)
{
CPhidget_set_OnAttach_Handler((CPhidgetHandle)this->spatial, AttachHandler, this);
  CPhidget_set_OnDetach_Handler((CPhidgetHandle)this->spatial, DetachHandler, this);
  CPhidget_set_OnError_Handler((CPhidgetHandle)this->spatial, ErrorHandler, this);
}

std::string Spatial::getErrorDescription(int errorCode)
{
	char a[1000];
  const char * errorPtr = a;
  CPhidget_getErrorDescription(errorCode, &errorPtr);
  return std::string(errorPtr);
}

int Spatial::getDeviceSerialNumber()
{
	int serNum;
	CPhidget_getSerialNumber(spatial, &serNum);
	return serNum;
}

void Spatial::attachHandler()
{
	cout << "Phidget attached : " << getDeviceSerialNumber() << endl;
}

void Spatial::detachHandler()
{
	cout << "Phidget detached : " << getDeviceSerialNumber() << endl;
}

void Spatial::errorHandler(int error)
{
	cout << "Phidget error " << error << getErrorDescription(error).c_str();
}


Spatial::~Spatial(void)
{
	CPhidget_delete((CPhidgetHandle)this->spatial);
}
