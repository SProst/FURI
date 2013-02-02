#pragma once
#include <windows.h>
#include <time.h>
#include <math.h>

class Utility
{
public:
	Utility(void);
	virtual ~Utility(void);

	double EuclideanDistance();
	double GetTime();
	double CalculateTilt(double gx, double gy);
};

