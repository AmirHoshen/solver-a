#pragma once

#include <string>
#include <complex>

namespace solver {
    class RealVariable {
    public:
        double pow;
        double coefficient;
        double constant;
        bool leftside;
        RealVariable();
        RealVariable operator-(RealVariable);
        RealVariable operator-(double);
        RealVariable operator+(RealVariable);
        RealVariable operator+(double);
        RealVariable operator*(RealVariable);
        RealVariable operator*(double);
        RealVariable operator/(RealVariable);
        RealVariable operator/(double);
        RealVariable operator^(int);
        RealVariable operator==(RealVariable);
        RealVariable operator==(double);
    };
    class ComplexVariable {
    public:
        std::complex<double> pow;
        std::complex<double> coefficient;
        std::complex<double> constant;
        bool leftside;
        ComplexVariable();
        ComplexVariable operator-(ComplexVariable);
        ComplexVariable operator-(std::complex<double>);
        ComplexVariable operator+(ComplexVariable);
        ComplexVariable operator+(std::complex<double>);
        ComplexVariable operator*(ComplexVariable);
        ComplexVariable operator*(std::complex<double>);
        ComplexVariable operator/(ComplexVariable);
        ComplexVariable operator/(std::complex<double>);
        ComplexVariable operator^(int);
        ComplexVariable operator==(ComplexVariable);
        ComplexVariable operator==(std::complex<double>);
    };
    RealVariable operator*(double ,const RealVariable & );
    RealVariable operator+(double ,const RealVariable & );
    RealVariable operator-(double ,const RealVariable & );
    RealVariable operator==(double ,const RealVariable & );

    ComplexVariable operator==(std::complex<double> ,const ComplexVariable & );
    ComplexVariable operator*(std::complex<double> ,const ComplexVariable & );
    ComplexVariable operator+(std::complex<double> ,const ComplexVariable & );
    ComplexVariable operator-(std::complex<double> ,const ComplexVariable & );
    ComplexVariable operator*(int ,const ComplexVariable & );
    ComplexVariable operator+(int ,const ComplexVariable & );
    ComplexVariable operator-(int ,const ComplexVariable & );
    double solve(RealVariable);
    std::complex<double> solve(ComplexVariable);

}