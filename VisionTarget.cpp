#include "VisionTarget.h"

VisionTarget::VisionTarget(std::vector<double> initPoints)
{
	ul.x = (int)initPoints[0];
	ul.y = (int)initPoints[1];

	ur.x = (int)initPoints[2];
	ur.y = (int)initPoints[3];

	ll.x = (int)initPoints[4];
	ll.y = (int)initPoints[5];

	lr.x = (int)initPoints[6];
	lr.y = (int)initPoints[7];
}

VisionTarget::~VisionTarget()
{
	// TODO Auto-generated destructor stub
}

double VisionTarget::PIDGet()
{
	return GetCenter().x; //shut up, your mom is an arbitrary value
}

Point VisionTarget::GetUL()
{
	return ul;
}

Point VisionTarget::GetLL()
{
	return ll;
}

Point VisionTarget::GetUR()
{
	return ur;
}

Point VisionTarget::GetLR()
{
	return lr;
}

Point VisionTarget::GetCenter()
{
	Point c;

	c.x = ul.x + GetWidth()/2;
	c.y = ul.y + GetHeight()/2;

	return c;
}

int VisionTarget::GetWidth()
{
	return ur.x - ul.x;
}

int VisionTarget::GetHeight()
{
	return ll.y - ul.y;
}
