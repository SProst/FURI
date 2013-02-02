#include "Utility.h"


Utility::Utility(void)
{
}


Utility::~Utility(void)
{
}

double Utility::GetTime()
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart/(double)f.QuadPart;
}

double Utility::CalculateTilt(double gx, double gy)
{
	double tilt = asin(gx) + asin(gy);
	tilt = tilt * ((180) / 3.14159265358);

	return tilt;
}
