#ifndef RANDOM2_H
#define RANDOM2_H

#include <valarray>
using namespace std;

class RandomBase {
    public:
        RandomBase(unsigned long Dimensionality);
        inline unsigned long GetDimensionality() const;
        virtual RandomBase* clone() const=0;
        virtual void GetUniforms(valarray<double>& variates)=0;
        virtual void Skip(unsigned long numberOfPaths)=0;
        virtual void SetSeed(unsigned long seed)=0;
        virtual void Reset()=0;

        virtual void GetGaussians(valarray<double>& variates);
        virtual void ResetDimensionality(unsigned long NewDimensionality);
        virtual ~RandomBase() {};

    private:
        unsigned long Dimensionality;
};

unsigned long RandomBase::GetDimensionality() const{
    return Dimensionality;
}

#endif