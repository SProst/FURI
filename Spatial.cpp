#include "Spatial.h"
#include <iostream>

using namespace phidgets; 
using namespace std;

namespace phidgets {
Spatial::Spatial(void)
{
	this->spatial = 0;
	
}

Spatial::~Spatial(void)
{
	CPhidget_delete((CPhidgetHandle)this->spatial);
}
}