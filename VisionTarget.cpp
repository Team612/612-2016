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

int VisionTarget::GetID()
{
	return id;
}

void VisionTarget::Set(std::vector<int> setPoints) {
	ul.x = (int)setPoints[0];
	ul.y = (int)setPoints[1];

	ur.x = (int)setPoints[2];
	ur.y = (int)setPoints[3];

	ll.x = (int)setPoints[4];
	ll.y = (int)setPoints[5];

	lr.x = (int)setPoints[6];
	lr.y = (int)setPoints[7];
}


double VisionTarget::GetAspectRatio() {
	return GetWidth() / GetHeight();
}

//Basic print method for debugging
void VisionTarget::Print() {
	printf("ID: %u \n", id);
	printf("UL (%u, %u) \n", ul.x, ul.y);
	printf("UR (%u, %u) \n", ur.x, ur.y);
	printf("LL (%u, %u) \n", ll.x, ll.y);
	printf("LR (%u, %u) \n", lr.x, lr.y);

}

//Finds a VisionTarget in a list of VisionTargets that most closely matches the given aspect
//ratio
std::shared_ptr<VisionTarget> VisionTarget::FindClosestAspect(double aspect,
		std::vector<std::shared_ptr<VisionTarget>> targets)
{
	int closest = 0; //i.e. closest to the given number
	for (int x = 1; x < targets.size(); x++)
	{
		if (abs(aspect - targets[x]->GetAspectRatio()) <
				abs(aspect - targets[closest]->GetAspectRatio()))
		{
			closest = x;
		}
	}

	return targets[closest];
}
