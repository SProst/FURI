#pragma once
#include <string>
#include "phidget21.h"
using namespace std;

class Phidget
{
public:
	Phidget(void);
	virtual ~Phidget(void);

	int open(int serialNumber);
	int close();
	int waitForAttachment(int timeout);
	string getDeviceType();
	string getDeviceName();
	string getDeviceLabel();
	string getLibraryVersion();
	int getDeviceSerialNumber();
	int getDeviceVersion();

	static string getErrorDescription(int errorCode);

protected:
	CPhidgetHandle handle_;
	void init(CPhidgetHandle handle);

	virtual void registerHandlers();
    virtual void attachHandler();
    virtual void detachHandler();
    virtual void errorHandler(int error);

private:
	static int CCONV AttachHandler(CPhidgetHandle handle, void *userptr);
    static int CCONV DetachHandler(CPhidgetHandle handle, void *userptr);
    static int CCONV ErrorHandler (CPhidgetHandle handle, void *userptr, int ErrorCode, const char *unknown);
};

