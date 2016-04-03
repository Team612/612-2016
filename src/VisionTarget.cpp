#include "VisionTarget.h"

VisionTarget::VisionTarget(std::vector<int> initPoints, int id)
{
	Set(initPoints);
	this->id = id;
}

VisionTarget::~VisionTarget()
{
	// TODO Auto-generated destructor stub
}

Point VisionTarget::GetUL()
{
	Point p;
	p.x = x;
	p.y = y;
	return p;
}

Point VisionTarget::GetLL()
{
	Point p;
	p.x = x;
	p.y = y + height;
	return p;
}

Point VisionTarget::GetUR()
{
	Point p;
	p.x = x + width;
	p.y = y;
	return p;
}

Point VisionTarget::GetLR()
{
	Point p;
	p.x = x + width;
	p.y = y + height;
	return p;
}

Point VisionTarget::GetCenter()
{
	Point c;

	c.x = x + GetWidth()/2;
	c.y = y + GetHeight()/2;

	return c;
}

int VisionTarget::GetWidth()
{
	return width;
}

int VisionTarget::GetHeight()
{
	return height;
}

int VisionTarget::GetID()
{
	return id;
}

void VisionTarget::Set(std::vector<int> setPoints) {
	x = setPoints[0];
	y = setPoints[1];
	width = setPoints[2];
	height = setPoints[3];
}


double VisionTarget::GetAspectRatio() {
	return GetWidth() / GetHeight();
}

//Basic print method for debugging
void VisionTarget::Print() {
	printf("ID: %u \n", id);
	printf("X (%u) \n", x);
	printf("Y (%u) \n", y);
	printf("W (%u)\n", width);
	printf("H (%u) \n", height);

}

//Finds a VisionTarget in a list of VisionTargets that most closely matches the given aspect
//ratio
std::shared_ptr<VisionTarget> VisionTarget::FindClosestAspect(double aspect,
		std::vector<std::shared_ptr<VisionTarget>> targets)
{
	int closest = 0; //i.e. closest to the given number
	for (int x = 1; x < (int)targets.size(); x++)
	{
		if (abs(aspect - targets[x]->GetAspectRatio()) <
				abs(aspect - targets[closest]->GetAspectRatio()))
		{
			closest = x;
		}
	}

	return targets[closest];
}
