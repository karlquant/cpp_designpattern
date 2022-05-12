#include "PathDependent.h"

PathDependent::PathDependent(const valarray<double>& LookAtTimes_): LookAtTimes(LookAtTimes_) {

}

const valarray<double>& PathDependent::GetLookAtTimes() const {
    return LookAtTimes;
}