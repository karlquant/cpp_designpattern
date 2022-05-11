#include "AntiThetic.h"

AntiThetic::AntiThetic(const Wrapper<RandomBase>& innerGenerator_): RandomBase(*innerGenerator_), innerGenerator(innerGenerator_) {
    innerGenerator->Reset();
    OddEven = true;
    NextVariates.resize(GetDimensionality());
}

RandomBase* AntiThetic::clone() const {
    return new AntiThetic(*this);
}

void AntiThetic::GetUniforms(valarray<double>& variates) {
    if (OddEven) {
        innerGenerator->GetUniforms(variates);
        for (unsigned long i=0; i < GetDimensionality(); i++) {
            NextVariates[i] = 1.0 - variates[i];

        }
        OddEven = false;
    } else {
        variates = NextVariates;
        OddEven = true;
    }

}

void AntiThetic::SetSeed(unsigned long Seed) {
    innerGenerator->SetSeed(Seed);
    OddEven = true;
}

void AntiThetic::Skip(unsigned long numberOfPaths) {
    if (numberOfPaths == 0) {
        return;
    } 
    
    if (OddEven) {
        OddEven = false;
        numberOfPaths--;
    }
    innerGenerator->Skip(numberOfPaths / 2);
    if(numberOfPaths % 2) {
        valarray<double> tmp(GetDimensionality());
        GetUniforms(tmp);
    }
}


void AntiThetic::ResetDimensionality(unsigned long NewDimensionality) {
    RandomBase::ResetDimensionality(NewDimensionality);
    NextVariates.resize(NewDimensionality);
    innerGenerator->ResetDimensionality(NewDimensionality);
}

void AntiThetic::Reset() {
    innerGenerator->Reset();
    OddEven = true;
}