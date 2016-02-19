#ifndef AUTO_ALIGN_H
#define AUTO_ALIGN_H

#include "Commands/CommandGroup.h"
#include "Commands/AlignToTarget.h"
#include "Commands/FindTarget.h"
#include "Commands/Rumble.h"
#include "WPILib.h"

class AutoAlign: public CommandGroup
{
public:
	AutoAlign(FindTarget::Direction dir);
};

#endif
