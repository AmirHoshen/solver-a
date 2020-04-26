#include "solver.hpp"

#include <string>
#include <complex>

namespace solver {
    RealVariable::RealVariable(){
        pow = 0;
        coefficient = 1;
        constant = 0;
        leftside = true;
    };
    RealVariable RealVariable::operator-(RealVariable other){
        RealVariable newVariable;
           if (!this->leftside) {
            newVariable.pow = this->pow + other.pow;
            newVariable.coefficient = this->coefficient + other.coefficient;
            newVariable.constant = this->constant + other.constant;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.pow = this->pow - other.pow;
        newVariable.coefficient = this->coefficient - other.coefficient;
        newVariable.constant = this->constant - other.constant;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator-(double other){
        RealVariable newVariable;
        if (!this->leftside) {
            newVariable.pow = this->pow;
            newVariable.coefficient = this->coefficient;
            newVariable.constant = this->constant + other;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.pow = this->pow;
        newVariable.coefficient = this->coefficient;
        newVariable.constant = this->constant - other;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator+(RealVariable other){
        RealVariable newVariable;
        if (!this->leftside) {
            newVariable.pow = this->pow - other.pow;
            newVariable.coefficient = this->coefficient - other.coefficient;
            newVariable.constant = this->constant - other.constant;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.pow = this->pow + other.pow;
        newVariable.coefficient = this->coefficient + other.coefficient;
        newVariable.constant = this->constant + other.constant;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator+(double other){
        RealVariable newVariable;
        if (!this->leftside) {
            newVariable.pow = this->pow;
            newVariable.coefficient = this->coefficient;
            newVariable.constant = this->constant - other;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.pow = this->pow;
        newVariable.coefficient = this->coefficient;
        newVariable.constant = this->constant + other;
        newVariable.leftside = this->leftside;
        return newVariable;
    };

    RealVariable RealVariable::operator*(RealVariable other){
        RealVariable newVariable;
        newVariable.pow = this->pow*sec.constant + this->coefficient*other.coefficient + this->constant*other.pow;
        newVariable.coefficient = this->coefficient*other.constant + this->constant*other.coefficient;
        newVariable.constant = this->constant*other.constant;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator*(double other){
        RealVariable newVariable;
        newVariable.pow = this->pow*other;
        newVariable.coefficient = this->coefficient*other;
        newVariable.constant = this->constant*other;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
//need to think
    // RealVariable RealVariable::operator/(RealVariable sec){
    //     this->pow = this->pow*sec.constant + this->coefficient*sec.coefficient + this->constant*sec.pow;
    //     this->coefficient = this->coefficient*sec.constant + this->constant*sec.coefficient;
    //     this->constant = this->constant*sec.constant;
    //     return this;
    // };
    RealVariable RealVariable::operator/(double other){
        RealVariable newVariable;
        if(other == 0)throw std::runtime_error("Cannot be divided by Zero!!!");
        newVariable.pow = this->pow/other;
        newVariable.coefficient = this->coefficient/other;
        newVariable.constant = this->constant/other;
        newVariable.leftside = this->leftside;
        return newVariable;
    };

    RealVariable RealVariable::operator/(RealVariable){};


    RealVariable RealVariable::operator^(int other){
        RealVariable newVariable;
        newVariable.pow = this->pow;
        newVariable.coefficient = this->coefficient;
        newVariable.constant = this->constant;
        newVariable.leftside = this->leftside;
        if (other>2 || other<0) {
            throw std::exception("line 117 if error other>2 ?!");
        }
        if (other == 0) {
            newVariable.pow = 0;
            newVariable.coefficient = 0;
            newVariable.constant = 1;
            return newVariable;
        }
        if (other == 1) {
            return newVariable;
        }
        if (newVariable.pow != 0) {
            throw std::exception("line 129 broken if statement");
        }
        newVariable.pow = this->coefficient*this->coefficient;
        newVariable.coefficient = 2*this->coefficient*this->constant;
        newVariable.constant = this->constant*this->constant;
        return newVariable;
    };
    RealVariable RealVariable::operator==(RealVariable other){
        RealVariable newVariable;
        newVariable.pow = this->pow - other.pow;
        newVariable.coefficient = this->coefficient - other.coefficient;
        newVariable.constant = this->constant - other.constant;
        newVariable.leftside = false;
        return newVariable;
    };
    RealVariable RealVariable::operator==(double other){
        RealVariable newVariable;
        newVariable.pow = this->pow;
        newVariable.coefficient = this->coefficient;
        newVariable.constant = this->constant - other;
        newVariable.leftside = false;
        return newVariable;
    };
    RealVariable operator*(double sec ,const RealVariable & first){
        RealVariable newVariable;
        newVariable.pow = first.pow*sec;
        newVariable.coefficient = first.coefficient*sec;
        newVariable.constant = first.constant*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    RealVariable operator+(double sec,const RealVariable & first){
        RealVariable newVariable;
        if (!first.leftside) {
            newVariable.pow = -first.pow;
            newVariable.coefficient = -first.coefficient;
            newVariable.constant = -first.constant - sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.pow = first.pow;
        newVariable.coefficient = first.coefficient;
        newVariable.constant = first.constant + sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    RealVariable operator-(double sec,const RealVariable & first){
        RealVariable newVariable;
        if (!first.leftside) {
            newVariable.pow = first.pow;
            newVariable.coefficient = first.coefficient;
            newVariable.constant = first.constant - sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.pow = -first.pow;
        newVariable.coefficient = -first.coefficient;
        newVariable.constant = -first.constant + sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    RealVariable operator==(double sec,const RealVariable & first){
        RealVariable newVariable;
        newVariable.pow = -first.pow;
        newVariable.coefficient = -first.coefficient;
        newVariable.constant = sec - first.constant;
        newVariable.leftside = false;
        return newVariable;
    };

    double solve(RealVariable equ){
        if (equ.pow == 0){
            return -equ.constant/equ.coefficient;
        }
        return -equ.coefficient/2 + std::sqrt(equ.coefficient*equ.coefficient-4*equ.pow*equ.constant)/2;
    };



    ComplexVariable::ComplexVariable(){
        pow = 0;
        coefficient = 1;
        constant = 0;
        leftside = true;
    };
    ComplexVariable ComplexVariable::operator-(ComplexVariable sec){
        ComplexVariable newVariable;
        if (!this->leftside) {
            newVariable.pow = this->pow + sec.pow;
            newVariable.coefficient = this->coefficient + sec.coefficient;
            newVariable.constant = this->constant + sec.constant;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.pow = this->pow - sec.pow;
        newVariable.coefficient = this->coefficient - sec.coefficient;
        newVariable.constant = this->constant - sec.constant;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator-(std::complex<double> sec){
        ComplexVariable newVariable;
        if (!this->leftside) {
            newVariable.pow = this->pow;
            newVariable.coefficient = this->coefficient;
            newVariable.constant = this->constant + sec;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.pow = this->pow;
        newVariable.coefficient = this->coefficient;
        newVariable.constant = this->constant - sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator+(ComplexVariable sec){
        ComplexVariable newVariable;
        if (!this->leftside) {
            newVariable.pow = this->pow - sec.pow;
            newVariable.coefficient = this->coefficient - sec.coefficient;
            newVariable.constant = this->constant - sec.constant;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.pow = this->pow + sec.pow;
        newVariable.coefficient = this->coefficient + sec.coefficient;
        newVariable.constant = this->constant + sec.constant;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator+(std::complex<double> sec){
        ComplexVariable newVariable;
        if (!this->leftside) {
            newVariable.pow = this->pow;
            newVariable.coefficient = this->coefficient;
            newVariable.constant = this->constant - sec;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.pow = this->pow;
        newVariable.coefficient = this->coefficient;
        newVariable.constant = this->constant + sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };

    ComplexVariable ComplexVariable::operator*(ComplexVariable sec){
        ComplexVariable newVariable;
        newVariable.pow = this->pow*sec.constant + this->coefficient*sec.coefficient + this->constant*sec.pow;
        newVariable.coefficient = this->coefficient*sec.constant + this->constant*sec.coefficient;
        newVariable.constant = this->constant*sec.constant;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator*(std::complex<double> sec){
        ComplexVariable newVariable;
        newVariable.pow = this->pow*sec;
        newVariable.coefficient = this->coefficient*sec;
        newVariable.constant = this->constant*sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    //need to think
    // ComplexVariable ComplexVariable::operator/(ComplexVariable sec){
    //     this->pow = this->pow*sec.constant + this->coefficient*sec.coefficient + this->constant*sec.pow;
    //     this->coefficient = this->coefficient*sec.constant + this->constant*sec.coefficient;
    //     this->constant = this->constant*sec.constant;
    //     return this;
    // };
    ComplexVariable ComplexVariable::operator/(std::complex<double> sec){
        ComplexVariable newVariable;
        newVariable.pow = this->pow/sec;
        newVariable.coefficient = this->coefficient/sec;
        newVariable.constant = this->constant/sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };

    ComplexVariable ComplexVariable::operator/(ComplexVariable){};


    ComplexVariable ComplexVariable::operator^(int sec){
        ComplexVariable newVariable;
        newVariable.pow = this->pow;
        newVariable.coefficient = this->coefficient;
        newVariable.constant = this->constant;
        newVariable.leftside = this->leftside;
        if (sec>2 || sec<0) {
            throw std::exception();
        }
        if (sec == 0) {
            newVariable.pow = 0;
            newVariable.coefficient = 0;
            newVariable.constant = 1;
            return newVariable;
        }
        if (sec == 1) {
            return newVariable;
        }
        if (newVariable.pow != 0.0) {
            throw std::exception();
        }
        newVariable.pow = this->coefficient*this->coefficient;
        newVariable.coefficient = 2.0*this->coefficient*this->constant;
        newVariable.constant = this->constant*this->constant;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator==(ComplexVariable sec){
        ComplexVariable newVariable;
        newVariable.pow = this->pow - sec.pow;
        newVariable.coefficient = this->coefficient - sec.coefficient;
        newVariable.constant = this->constant - sec.constant;
        newVariable.leftside = false;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator==(std::complex<double> sec){
        ComplexVariable newVariable;
        newVariable.pow = this->pow;
        newVariable.coefficient = this->coefficient;
        newVariable.constant = this->constant - sec;
        newVariable.leftside = false;
        return newVariable;
    };
    ComplexVariable operator * (std::complex<double> sec ,const ComplexVariable & first){
        ComplexVariable newVariable;
        newVariable.pow = first.pow*sec;
        newVariable.coefficient = first.coefficient*sec;
        newVariable.constant = first.constant*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator * (int sec ,const ComplexVariable & first){
        ComplexVariable newVariable;
        newVariable.pow = first.pow*(1.0*sec);
        newVariable.coefficient = first.coefficient*(1.0*sec);
        newVariable.constant = first.constant*(1.0*sec);
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator + (std::complex<double> sec,const ComplexVariable & first){
        ComplexVariable newVariable;
        if (!first.leftside) {
            newVariable.pow = -first.pow;
            newVariable.coefficient = -first.coefficient;
            newVariable.constant = -first.constant - 1.0*sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.pow = first.pow;
        newVariable.coefficient = first.coefficient;
        newVariable.constant = first.constant + 1.0*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator + (int sec,const ComplexVariable & first){
        ComplexVariable newVariable;
        if (!first.leftside) {
            newVariable.pow = -first.pow;
            newVariable.coefficient = -first.coefficient;
            newVariable.constant = -first.constant - 1.0*sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.pow = first.pow;
        newVariable.coefficient = first.coefficient;
        newVariable.constant = first.constant + 1.0*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator - (std::complex<double> sec,const ComplexVariable & first){
        ComplexVariable newVariable;
        if (!first.leftside) {
            newVariable.pow = first.pow;
            newVariable.coefficient = first.coefficient;
            newVariable.constant = first.constant - sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.pow = -first.pow;
        newVariable.coefficient = -first.coefficient;
        newVariable.constant = -first.constant + 1.0*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator - (int sec,const ComplexVariable & first){
        ComplexVariable newVariable;
        if (!first.leftside) {
            newVariable.pow = first.pow;
            newVariable.coefficient = first.coefficient;
            newVariable.constant = first.constant - 1.0*sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.pow = -first.pow;
        newVariable.coefficient = -first.coefficient;
        newVariable.constant = -first.constant + 1.0*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator==(std::complex<double> sec ,const ComplexVariable & first){
        ComplexVariable newVariable;
        newVariable.pow = -first.pow;
        newVariable.coefficient = -first.coefficient;
        newVariable.constant = sec - first.constant;
        newVariable.leftside = false;
        return newVariable;
    };
    std::complex<double>  solve(ComplexVariable equ){
        if (equ.pow == 0.0){
            return -equ.constant/equ.coefficient;
        }
        return -equ.coefficient/2.0 + std::sqrt(equ.coefficient*equ.coefficient-4.0*equ.pow*equ.constant)/2.0;
    };

};