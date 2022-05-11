#ifndef SIMPLEMC8_H
#define SIMPLEMC8_H

#include "Vanilla3.h"
#include "Random2.h"
#include "Parameters.h"
#include "StatisticsMC.h"

void SimpleMonteCarlo8(const VanillaOption& theOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths, StatisticsMC& gatherer, RandomBase& generator);

#endif