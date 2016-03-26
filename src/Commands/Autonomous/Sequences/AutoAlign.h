#ifndef AUTO_ALIGN_H
#define AUTO_ALIGN_H

#include "Commands/CommandGroup.h"
#include "AlignToTarget.h"
#include "FindTarget.h"
#include "WPILib.h"

class AutoAlign: public CommandGroup
{
public:
	AutoAlign(FindTarget::Direction dir);
};

#endif
