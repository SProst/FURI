#include "Phidget.h"
#include <iostream>
using namespace std;

Phidget::Phidget(void)
{
}


Phidget::~Phidget(void)
{
}

int CCONV Phidget::AttachHandler(CPhidgetHandle spatial, void *userptr)
{
	((Phidget*)userptr)->attachHandler();

	return 0;
}

int CCONV Phidget::DetachHandler(CPhidgetHandle spatial, void *userptr)
{
	((Phidget*)userptr)->detachHandler();
	return 0;
}

int CCONV Phidget::ErrorHandler(CPhidgetHandle handle, void *userptr, int ErrorCode, const char *unknown)
{
	((Phidget*)userptr)->errorHandler(ErrorCode);
	return 0;
}

void Phidget::init(CPhidgetHandle handle)
{
  handle_ = handle;
}

void Phidget::registerHandlers(void)
{
CPhidget_set_OnAttach_Handler((CPhidgetHandle)this->handle_, &Phidget::AttachHandler, this);
  CPhidget_set_OnDetach_Handler((CPhidgetHandle)this->handle_, DetachHandler, this);
  CPhidget_set_OnError_Handler((CPhidgetHandle)this->handle_, ErrorHandler, this);
}

std::string Phidget::getErrorDescription(int errorCode)
{
	char a[1000];
  const char * errorPtr = a;
  CPhidget_getErrorDescription(errorCode, &errorPtr);
  return std::string(errorPtr);
}

int Phidget::getDeviceSerialNumber()
{
	int serNum;
	CPhidget_getSerialNumber(handle_, &serNum);
	return serNum;
}

void Phidget::attachHandler()
{
	cout << "Phidget attached : " << getDeviceSerialNumber() << endl;
}

void Phidget::detachHandler()
{
	cout << "Phidget detached : " << getDeviceSerialNumber() << endl;
}

void Phidget::errorHandler(int error)
{
	cout << "Phidget error " << error << getErrorDescription(error).c_str();
}
