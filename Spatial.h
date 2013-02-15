#pragma once
#include "phidget21.h"
#include <string>
class Spatial
{
public:
	Spatial(void);
	CPhidgetSpatial_SpatialEventDataHandle data;
	double Gx,Gy,Gz;
	void getAcc(int axis);
	void open(void);
	int wait(int milliseconds);
	 int displayProperties(void);
    static int SpatialDataHandler(CPhidgetSpatialHandle spatial, void *userptr, CPhidgetSpatial_SpatialEventDataHandle *data, int count);
    void setDataRate(int ms);
    void getAcc(void);
    void close(void);
	virtual ~Spatial(void);
	virtual void registerHandlers();
    virtual void attachHandler();
    virtual void detachHandler();
    virtual void errorHandler(int error);
	std::string getErrorDescription(int errorCode);
private: 
	CPhidgetHandle spatial;
	int serialNo, version;
	int getDeviceSerialNumber(void);
	const char* DeviceType;
	int numAccelAxes, numGyroAxes, numCompassAxes, dataRateMax, dataRateMin;
	//int CCONV AttachHandler(CPhidgetHandle spatial, void *userptr);
 //   int CCONV DetachHandler(CPhidgetHandle spatial, void *userptr);
 //   int CCONV ErrorHandler(CPhidgetHandle spatial, void *userptr, int ErrorCode, const char *unknown);
};

