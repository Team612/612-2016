#ifndef AUTO_ALIGN_H
#define AUTO_ALIGN_H

#include "HorizontalAlign.h"
#include "HorizontalFind.h"
#include "VerticalAlign.h"
#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoAlign: public CommandGroup
{
public:
	AutoAlign(HorizontalFind::Direction dir);
};

#endif
