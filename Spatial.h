#pragma once
#include "phidget21.h"
#include "Phidget.h"
#include <string>

namespace phidgets {
class Spatial
{
public:
	Spatial(void);
	double Gx,Gy,Gz;
	void getAcc(int axis);
	int wait(int milliseconds);
	 int displayProperties(void);
    void setDataRate(int ms);
    void getAcc(void);
	virtual ~Spatial(void);
protected: 
	CPhidgetSpatialHandle spatial_handle_;

	void zero();
	void setDataRate(int rate);

	virtual void dataHandler(CPhidgetSpatial_SpatialEventDataHandle *data, int count);
private: 
	static int CCONV SpatialDataHandler(CPhidgetSpatialHandle spatial, void *userptr, CPhidgetSpatial_SpatialEventDataHandle *data, int count);
};

}