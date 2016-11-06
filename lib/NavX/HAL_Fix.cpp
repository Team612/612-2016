#include "HAL_Fix.h"

void delayMillis(int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
