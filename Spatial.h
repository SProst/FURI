#pragma once
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
private: 
	CPhidgetSpatialHandle spatial;
	int serialNo, version;
	const char* DeviceType;
	int numAccelAxes, numGyroAxes, numCompassAxes, dataRateMax, dataRateMin;
	static int AttachHandler(CPhidgetHandle spatial, void *userptr);
    static int DetachHandler(CPhidgetHandle spatial, void *userptr);
    static int ErrorHandler(CPhidgetHandle spatial, void *userptr, int ErrorCode, const char *unknown);
};

