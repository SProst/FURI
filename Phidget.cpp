#include "Phidget.h"
#include <iostream>
using namespace std;

namespace phidgets { 
Phidget::Phidget(void)
{
}


Phidget::~Phidget(void)
{
	 CPhidget_delete(handle_);
}

int  Phidget::AttachHandler(CPhidgetHandle spatial, void *userptr)
{
	((Phidget*)userptr)->attachHandler();
	return 0;
}

int  Phidget::DetachHandler(CPhidgetHandle spatial, void *userptr)
{
	((Phidget*)userptr)->detachHandler();
	return 0;
}

int  Phidget::ErrorHandler(CPhidgetHandle handle, void *userptr, int ErrorCode, const char *unknown)
{
	((Phidget*)userptr)->errorHandler(ErrorCode);
	return 0;
}

void Phidget::init(CPhidgetHandle handle)
{
  handle_ = handle;
  cout << "Initialized" << endl;
}

void Phidget::registerHandlers(void)
{
  CPhidget_set_OnAttach_Handler(handle_, AttachHandler, this);
  CPhidget_set_OnDetach_Handler(handle_, DetachHandler, this);
  CPhidget_set_OnError_Handler(handle_, ErrorHandler, this);
  cout << "Registered handles" << endl;
}

int  Phidget::open()
{
	return CPhidget_open(handle_,-1);
}

int  Phidget::close()
{
	cout << "Closing Phidget Device" << endl;
	return(CPhidget_close(handle_));
}

int  Phidget::waitForAttachment(int timeout)
{
  return CPhidget_waitForAttachment(handle_, timeout);
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

}