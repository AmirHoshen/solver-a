#include "solver.hpp"

#include <string>
#include <complex>

namespace solver {

    RealVariable::RealVariable(){};
    RealVariable::RealVariable(double){};
    RealVariable RealVariable::operator-(RealVariable){};
    RealVariable RealVariable::operator-(double){};
    RealVariable RealVariable::operator+(RealVariable){};
    RealVariable RealVariable::operator+(double){};
    RealVariable RealVariable::operator*(RealVariable){};
    RealVariable RealVariable::operator*(double){};
    RealVariable RealVariable::operator/(RealVariable){};
    RealVariable RealVariable::operator/(double){};
    RealVariable RealVariable::operator^(RealVariable){};
    RealVariable RealVariable::operator^(double){};
    RealVariable RealVariable::operator==(RealVariable){};
    RealVariable RealVariable::operator==(double){};

    ComplexVariable::ComplexVariable(){};
    ComplexVariable::ComplexVariable(std::complex<double>){};
    ComplexVariable ComplexVariable::operator-(ComplexVariable){};
    ComplexVariable ComplexVariable::operator-(double){};
    ComplexVariable ComplexVariable::operator+(ComplexVariable){};
    ComplexVariable ComplexVariable::operator+(double){};
    ComplexVariable ComplexVariable::operator*(ComplexVariable){};
    ComplexVariable ComplexVariable::operator*(double){};
    ComplexVariable ComplexVariable::operator/(ComplexVariable){};
    ComplexVariable ComplexVariable::operator/(double){};
    ComplexVariable ComplexVariable::operator^(ComplexVariable){};
    ComplexVariable ComplexVariable::operator^(double){};
    ComplexVariable ComplexVariable::operator==(ComplexVariable){};
    ComplexVariable ComplexVariable::operator==(double){};
    double solve(solver::RealVariable){return 0;};
    std::complex<double> solve(solver::ComplexVariable){};

    RealVariable operator * (double ,const RealVariable & ){};
    RealVariable operator + (double ,const RealVariable & ){};
    RealVariable operator - (double ,const RealVariable & ){};
    RealVariable operator==(double ,const RealVariable & ){};

    ComplexVariable operator==(double ,const ComplexVariable & ){};
    ComplexVariable operator * (double ,const ComplexVariable & ){};
    ComplexVariable operator + (double ,const ComplexVariable & ){};
    ComplexVariable operator - (double ,const ComplexVariable & ){};

};