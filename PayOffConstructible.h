#ifndef PAYOFFCONSTRUCTIBLE_H
#define PAYOFFCONSTRUCTIBLE_H


#include <iostream>
#include "PayOff3.h"
#include "PayOffFactory.h"
#include <string>

using namespace std;

template <class T>
class PayOffHelper {
    public: 
        PayOffHelper(string);
        static PayOff* Create(double);

};

template <class T>
PayOff* PayOffHelper<T>::Create(double Strike) {
    return new T(Strike);
}

template <class T>
PayOffHelper<T>::PayOffHelper(string PayOffId) {
    PayOffFactory& theFactory = PayOffFactory::Instance();
    theFactory.RegisterPayOff(PayOffId, PayOffHelper<T>::Create);
}

#endif