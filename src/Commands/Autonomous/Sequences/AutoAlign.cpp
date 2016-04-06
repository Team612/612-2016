#include "AutoAlign.h"

AutoAlign::AutoAlign(HorizontalFind::Direction dir)
{
	AddSequential(new HorizontalFind(dir));
	AddSequential(new HorizontalAlign());
	AddParallel(new VerticalAlign());
	//AddSequential(new Rumble(OI::Stick::DRIVER, OI::RumbleSide::BOTH, 0.5, 0.5));
}
