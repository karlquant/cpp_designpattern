#include "PayOff1.h"


PayOff::PayOff(double Strike_, OptionType TheOptionsType_): Strike(Strike_) , TheOptionsType(TheOptionsType_) {

}

double PayOff::operator() (double Spot) const{
    switch (TheOptionsType)
    {
    case call:
        return Spot - Strike > 0 ? Spot - Strike : 0;
    case put:
        return Strike - Spot > 0 ? Strike - Spot : 0;
    
    default:
        throw("unknown option type found");
    }
}