#ifndef VISIONTARGET_H_
#define VISIONTARGET_H_

#include "WPILib.h"

//Represents basically a bounding box (with a few perks)
class VisionTarget : PIDSource
{
public:
	VisionTarget(std::vector<double> initPoints);
	virtual ~VisionTarget();
	double PIDGet(); //Required for PIDSource

	Point GetUL();
	Point GetLL();
	Point GetUR();
	Point GetLR();

	Point GetCenter();

	int GetWidth();
	int GetHeight();

private:
	Point ul; //Upper-Left point
	Point ll;
	Point ur;
	Point lr;
};

#endif /* VISIONTARGET_H_ */
