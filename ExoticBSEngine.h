#ifndef EXOTICBSENGINE_H
#define EXOTICBSENGINE_H

#include "ExoticEngine.h"
#include "Random2.h"

class ExoticBSEngine: public ExoticEngine {
    public:
        ExoticBSEngine(const Wrapper<PathDependent>& theProduct_, const Parameters& R_, const Parameters& D_, const Parameters& Vol_, const Wrapper<RandomBase>& theGenerator_, double Spot);
        virtual void GetOnePath(valarray<double>& SpotValues);

        virtual ~ExoticBSEngine() {};
    private:
        Wrapper<RandomBase> theGenerator;
        valarray<double> Drifts;
        valarray<double> StandardDeviations;
        double logSpot;
        unsigned long NumberOfTimes;
        valarray<double> variates;
};

#endif