#ifndef AUTO_ALIGN_H
#define AUTO_ALIGN_H

#include <Commands/Autonomous/Sequences/HorizontalAlign.h>
#include <Commands/Autonomous/Sequences/HorizontalFind.h>
#include <Commands/Autonomous/Sequences/VerticalAlign.h>
#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoAlign: public CommandGroup
{
public:
	AutoAlign(HorizontalFind::Direction dir);
};

#endif
