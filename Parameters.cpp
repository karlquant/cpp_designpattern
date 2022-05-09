#include "Parameters.h"

Parameters::Parameters(const ParametersInner& innerObject) {
    innerObjectPtr = innerObject.clone();
}

Parameters::Parameters(const Parameters& original) {
    innerObjectPtr = original.innerObjectPtr->clone();
}

Parameters& Parameters::operator=(const Parameters& original) {
    if (this != &original) {
        delete innerObjectPtr;
        innerObjectPtr = original.innerObjectPtr->clone();
    }
    return *this;
}

Parameters::~Parameters() {
    delete innerObjectPtr;
}

double Parameters::Mean(double time1, double time2) const {
    double total = Integral(time1, time2);
    return total / (time2 - time1);
}

double Parameters::RootMeanSquare(double time1, double time2) const {
    double total = IntegralSquare(time1, time2);
    return total / (time2 - time1);
}

ParametersConstant::ParametersConstant(double Constant_): Constant(Constant_){
    ConstantSquare = Constant * Constant;
}

ParametersInner* ParametersConstant::clone() const{
    return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1, double time2) const {
    return (time2 - time1) * Constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const {
    return (time2 - time1) * ConstantSquare;
}
