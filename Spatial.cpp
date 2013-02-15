//#include "Spatial.h"
//#include <iostream>
//
//using namespace std;
//
//Spatial::Spatial(void)
//{
//	this->spatial = 0;
//
//
////   CPhidgetSpatial_set_OnSpatialData_Handler(this->spatial, SpatialDataHandler, NULL);
//}
//
////void Spatial::registerHandlers(void)
////{
////CPhidget_set_OnAttach_Handler((CPhidgetHandle)this->spatial, &Spatial::AttachHandler, this);
////  CPhidget_set_OnDetach_Handler((CPhidgetHandle)this->spatial, &Spatial::DetachHandler, this);
////  CPhidget_set_OnError_Handler((CPhidgetHandle)this->spatial, &Spatial::ErrorHandler, this);
////}
//
//int Spatial::getDeviceSerialNumber()
//{
//	int serNum;
//	CPhidget_getSerialNumber(spatial, &serNum);
//	return serNum;
//}
//
//void Spatial::attachHandler()
//{
//	cout << "Phidget attached : " << getDeviceSerialNumber() << endl;
//}
//
//int Spatial::AttachHandler(CPhidgetHandle spatial, void *userptr)
//{
//	((Spatial*)userptr)->attachHandler();
//
//	return 0;
//}
//
//int Spatial::DetachHandler(CPhidgetHandle spatial, void *userptr)
//{
//	int serialNo;
//	CPhidget_getSerialNumber(spatial, &serialNo);
//	cout << "Spatial" << serialNo << "detached!" << endl;
//	return 0;
//}
//
//
//Spatial::~Spatial(void)
//{
//	CPhidget_delete((CPhidgetHandle)this->spatial);
//}
