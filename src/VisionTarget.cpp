#include "VisionTarget.h"

const double VisionTarget::WIDTH = 0.506;
const double VisionTarget::HEIGHT = 0.305;

VisionTarget::VisionTarget(std::vector<int> initPoints, int id)
{
	Set(initPoints);
	this->id = id;
}

VisionTarget::~VisionTarget() { }

Point VisionTarget::GetUL()
{
	return MakePoint(x, y);
}

Point VisionTarget::GetLL()
{
	return MakePoint(x, y + height);
}

Point VisionTarget::GetUR()
{
	return MakePoint(x + width, y);
}

Point VisionTarget::GetLR()
{
	return MakePoint(x + width, y + height);
}

Point VisionTarget::GetCenter()
{
	return MakePoint(x + GetWidth()/2, y + GetHeight()/2);
}

int VisionTarget::GetWidth()
{
	return width;
}

int VisionTarget::GetHeight()
{
	return height;
}

int VisionTarget::GetHeightConvex()
{
	return hHeight;
}

int VisionTarget::GetID()
{
	return id;
}

void VisionTarget::Set(std::vector<int> setPoints) {
	if (setPoints.size() == PARAM_COUNT)
	{
		x = setPoints[0];
		y = setPoints[1];
		width = setPoints[2];
		height = setPoints[3];
		//hHeight = setPoints[4];
	}
	else
		printf("Warning: Not enough parameters passed from camera");

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

double VisionTarget::GetDistance()
{
	double fovy = 37.5;
	double dist	 = HEIGHT * 480 / (2 * height * tan(fovy * (M_PI / 180)));
	return dist;
}

Point VisionTarget::MakePoint(int x, int y)
{
	Point p;
	p.x = x;
	p.y = y;
	return p;
}
