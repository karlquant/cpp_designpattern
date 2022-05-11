#include "ParkMiller.h"

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;

ParkMiller::ParkMiller(long Seed_): Seed(Seed_) {
    if (Seed == 0) {
        Seed = 1;
    }
} 

long ParkMiller::GetOneRandomInteger() {
    long k;
    k = Seed / q;
    Seed = a * (Seed - k*q) - r*k;
    if (Seed < 0) {
        Seed += m;
    }
    return Seed;
}

void ParkMiller::SetSeed(long Seed_) {
    Seed = Seed_;
    if (Seed == 0) {
        Seed = 1;
    }
}

unsigned long ParkMiller::Max() {
    return m - 1;
}

unsigned long ParkMiller::Min() {
    return 1;
}

RandomParkMiller::RandomParkMiller(unsigned long Dimensionality_, unsigned long Seed_): RandomBase(Dimensionality_), innerGenerator(Seed_), InitialSeed(Seed_) {
    Recipocal = 1 / (innerGenerator.Max() + 1);

}

RandomBase* RandomParkMiller::clone() const {
    return new RandomParkMiller(*this);
}

void RandomParkMiller::GetUniforms(valarray<double>& variates){
    for (unsigned long i=0; i < GetDimensionality(); i++){
        variates[i] = innerGenerator.GetOneRandomInteger()*Recipocal;
    }
}

void RandomParkMiller::Skip(unsigned long numberOfPaths) {
    valarray<double> tmp(GetDimensionality());
    for (unsigned long i = 0; i < numberOfPaths; i++) {
        GetUniforms(tmp);
    }
}

void RandomParkMiller::SetSeed(unsigned long Seed) {
    InitialSeed = Seed;
    innerGenerator.SetSeed(Seed);
}

void RandomParkMiller::Reset() {
    innerGenerator.SetSeed(InitialSeed);
}


void RandomParkMiller::ResetDimensionality(unsigned long NewDimensionality) {
    RandomBase::ResetDimensionality(NewDimensionality);
    innerGenerator.SetSeed(InitialSeed);
}