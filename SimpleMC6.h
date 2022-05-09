#ifndef SIMPLEMC6_H
#define SIMPLEMC6_H

#include "Vanilla3.h"
#include "Parameters.h"

double SimpleMonteCarlo6(const VanillaOption& theOption, double Spot, const Parameters& Vol, const Parameters& r, unsigned long NumberOfPaths);

#endif