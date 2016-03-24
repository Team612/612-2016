/*
 * NetworkTables.cpp
 *
 *  Created on: Mar 4, 2016
 *      Author: champ
 */

#include "NetworkTables.h"

NetworkTables::NetworkTables()
{
	NetworkTable::SetPort(1735);
	wheels = NetworkTable::GetTable("SmartDashboard");
	wheels->PutNumber("Hello", 37);
	startTime = std::chrono::high_resolution_clock::now();
}


void NetworkTables::AddValue(double val)
{
	auto time = std::chrono::high_resolution_clock::now();
	wheels->PutNumber("x", (double)((time - startTime)).count());
	wheels->PutNumber("y", val);
}
