#include "AutoAlign.h"

AutoAlign::AutoAlign(FindTarget::Direction dir)
{
	AddSequential(new FindTarget(dir));
	AddSequential(new AlignToTarget());
	//AddSequential(new Rumble(OI::Stick::DRIVER, OI::RumbleSide::BOTH, 0.5, 0.5));
}
