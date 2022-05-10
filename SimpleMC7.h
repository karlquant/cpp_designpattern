#ifndef SIMPLEMC7_H
#define SIMPLEMC7_H

#include "Vanilla3.h"
#include "Parameters.h"
#include "StatisticsMC.h"

void SimpleMonteCarlo7(const VanillaOption& theOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths, StatisticsMC& gatherer);

#endif