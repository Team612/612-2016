#ifndef VISIONTARGET_H_
#define VISIONTARGET_H_

#include "WPILib.h"
#include <cmath>

//Represents basically a bounding box (with a few perks)
class VisionTarget
{
public:
	VisionTarget(std::vector<int> initPoints, int id); //See "Set()"
	virtual ~VisionTarget();

	Point GetUL(); //Upper-Left
	Point GetLL(); //Lower-Left
	Point GetUR(); //Upper-Right
	Point GetLR(); //Lower-Right

	Point GetCenter();

	int GetWidth();
	int GetHeight();

	double GetAspectRatio(); //width/height

	int GetID(); //The tracking ID set by RoboRealm to distinguish one object as it moves frame to frame

	void Set(std::vector<int> setPoints); //Sets the points in a size 8 vector in the following format {ulx, uly, urx, ury, llx, lly, lrx, lry}
	//(This is hour RoboRealm formats points sent from bounding boxes)

	void Print();

	static std::shared_ptr<VisionTarget> FindClosestAspect(double aspect, std::vector<std::shared_ptr<VisionTarget>> targets);

private:
	int x;
	int y;
	int width;
	int height;

	int id; //The tracking ID as given by RoboRealm
};

#endif /* VISIONTARGET_H_ */
