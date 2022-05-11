#ifndef ANTITHETIC_H
#define ANTITHETIC_H

#include "Random2.h"
#include "Wrapper.h"

class AntiThetic: public RandomBase {
    public:
        AntiThetic(const Wrapper<RandomBase>& innerGenerator);
        virtual RandomBase* clone() const;
        virtual void GetUniforms(valarray<double>& variates);
        virtual void Skip(unsigned long numberOfPaths);
        virtual void SetSeed(unsigned long Seed);
        virtual void Reset();
        virtual void ResetDimensionality(unsigned long NewDimensionality);
        virtual ~AntiThetic() {};
    private:
        Wrapper<RandomBase> innerGenerator;
        bool OddEven;
        valarray<double> NextVariates;

};

#endif