#include "doctest.h"
#include "solver.hpp"

#include <string>
#include <complex>

using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;

TEST_CASE("Check Initialize") {
    CHECK_NOTHROW(RealVariable x);
    CHECK_NOTHROW(ComplexVariable x);
}
TEST_CASE("Test simple equations") {
    RealVariable x;
            CHECK(solve(x == 5) == 5);
            CHECK(solve(x == -5) == -5);
            CHECK(solve(x == 0) == 0);
            CHECK(solve(x == 0.6) == 0.6);
            CHECK(solve(1.7 == x) == 1.7);
            CHECK(solve(1 == x) == 1);
            CHECK(solve(0 == x) == 0);
            CHECK(solve(-10 == x) == -10);
}

TEST_CASE("Test real equations +") {
    RealVariable x;
            CHECK(solve(x + 2 == 7) == 5);
            CHECK(solve(x + 10 == 5) == -5);
            CHECK(solve(x + 10 == 10) == 0);
            CHECK(solve(x + 0.8 == 1.3) == 0.5);
            CHECK(solve(1.7 == x + 5.2) == -3.5);
            CHECK(solve(1 == x + 2) == -1);
            CHECK(solve(10 == x + 10) == 0);
            CHECK(solve(-10 == x + 10) == -20);
            CHECK(solve(10 == 10 + x) == 0);
            CHECK(solve(-10 == 10 + x) == -20);
}

TEST_CASE("Test real equations -") {
    RealVariable x;
            CHECK(solve(x - 2 == 7) == 9);
            CHECK(solve(x - 10 == 5) == 15);
            CHECK(solve(x - 10 == -10) == 0);
            CHECK(solve(x - 0.7 == 1.3) == 2.0);
            CHECK(solve(1.7 == x - 5.2) == 6.9);
            CHECK(solve(1 == x - 2) == 3);
            CHECK(solve(10 == x - 10) == 20);
            CHECK(solve(-10 == x - 10) == 0);
            CHECK(solve(10 == 10 - x) == 0);
            CHECK(solve(-10 == 10 - x) == 20);
}

TEST_CASE("Test real equations *") {
    RealVariable x;
            CHECK(solve(x * 2 == 7) == 3.5);
            CHECK(solve(x * 10 == 5) == 0.5);
            CHECK(solve(x * 10 == -10) == -1);
            CHECK(solve(x * 0.7 == 1.4) == 2.0);
            CHECK(solve(7.5 == x * 5) == 1.5);
            CHECK(solve(1 == x * 2) == 0.5);
            CHECK(solve(10 == x * 10) == 1);
            CHECK(solve(-10 == x * 10) == -1);
            CHECK(solve(10 == 10 * x) == 1);
            CHECK(solve(0 == 10 * x) == 0);
}

TEST_CASE("Test real equations /") {
    RealVariable x;
            CHECK(solve(x / 2 == 7) == 14.0);
            CHECK(solve(x / 10 == 0.05) == 0.5);
            CHECK(solve(x / 10 == -10) == -100);
            CHECK(solve(x / 0.2 == 1.2) == 0.24);
            CHECK(solve(7.5 == x / 5) == 37.5);
            CHECK(solve(1 == x / 2) == 2.0);
            CHECK(solve(10 == x / 10) == 100.0);
            CHECK(solve(-10 == x / 10) == -100.0);
}

TEST_CASE("Test real equations both sides ^2") {
    RealVariable x;
            CHECK(solve(x + 1 == 2 * x + 1) == 0.0);
            CHECK(solve(x - 1 == 2 * x - 1) == 0.0);
            CHECK((solve((x ^ 2) == x ) == 0.0 || solve((x ^ 2) == x) == 1.0));
            CHECK((solve((x^2)  ==  x +2) == 2.0 || solve((x ^ 2) == x + 2) == -1.0));
}

// test ComplexVariable

TEST_CASE("Test simple equations") {
    ComplexVariable x;
            CHECK(solve(x == 5) == 5.0);
            CHECK(solve(x == -5) == -5.0);
            CHECK(solve(x == 0) == 0.0);
            CHECK(solve(x == 0.6) == 0.6);
            CHECK(solve(1.7 == x) == 1.7);
            CHECK(solve(1 == x) == 1.0);
            CHECK(solve(0 == x) == 0.0);
            CHECK(solve(-10 == x) == -10.0);
}

TEST_CASE("Test real equations +") {
    ComplexVariable x;
            CHECK(solve(x + 2 == 7) == 5.0);
            CHECK(solve(x + 10 == 5) == -5.0);
            CHECK(solve(x + 10 == 10) == 0.0);
            CHECK(solve(x + 0.8 == 1.3) == 0.5);
            CHECK(solve(1.7 == x + 5.2) == -3.5);
            CHECK(solve(1 == x + 2) == -1.0);
            CHECK(solve(10 == x + 10) == 0.0);
            CHECK(solve(-10 == x + 10) == -20.0);
            CHECK(solve(10 == 10 + x) == 0.0);
            CHECK(solve(-10 == 10 + x) == -20.0);
}

TEST_CASE("Test real equations -") {
    ComplexVariable x;
            CHECK(solve(x - 2 == 7) == 9.0);
            CHECK(solve(x - 10 == 5) == 15.0);
            CHECK(solve(x - 10 == -10) == 0.0);
            CHECK(solve(x - 0.7 == 1.3) == 2.0);
            CHECK(solve(1.7 == x - 5.2) == 6.9);
            CHECK(solve(1 == x - 2) == 3.0);
            CHECK(solve(10 == x - 10) == 20.0);
            CHECK(solve(-10 == x - 10) == 0.0);
            CHECK(solve(10 == 10 - x) == 0.0);
            CHECK(solve(-10 == 10 - x) == 20.0);
}

TEST_CASE("Test real equations *") {
    ComplexVariable x;
            CHECK(solve(x * 2 == 7) == 3.5);
            CHECK(solve(x * 10 == 5) == 0.5);
            CHECK(solve(x * 10 == -10) == -1.0);
            CHECK(solve(x * 0.7 == 1.4) == 2.0);
            CHECK(solve(7.5 == x * 5) == 1.5);
            CHECK(solve(1 == x * 2) == 0.5);
            CHECK(solve(10 == x * 10) == 1.0);
            CHECK(solve(-10 == x * 10) == -1.0);
            CHECK(solve(10 == 10 * x) == 1.0);
            CHECK(solve(0 == 10 * x) == 0.0);
}

TEST_CASE("Test real equations /") {
    ComplexVariable x;
    std::complex<double> val;
    val.real(14);
    val.imag(0);
            CHECK(solve(x / 2 == 7) == val);
    val.real(0.5);
    val.imag(0);
            CHECK(solve(x / 10 == 0.05) == val);
    val.real(-20);
    val.imag(0);
            CHECK(solve(x / 2 == -10) == val);
    val.real(0.6);
    val.imag(0);
            CHECK(solve(x / 0.5 == 1.2) == val);
    val.real(14.5);
    val.imag(0);
            CHECK(solve(7.25 == x / 2) == val);
    val.real(2.0);
    val.imag(0);
            CHECK(solve(1 == x / 2) == val);
    val.real(80);
    val.imag(0);
            CHECK(solve(10 == x / 8) == val);
    val.real(-80);
    val.imag(0);
            CHECK(solve(-10 == x / 8) == val);
}


TEST_CASE("Test real equations both sides ^2") {
    ComplexVariable x;
    std::complex<double> val ,val2;
    val.real(0);
    val.imag(0);
            CHECK(solve(x + 1 == 2 * x + 1) == val);
            CHECK(solve(x - 1 == 2 * x - 1) == val);
    val.real(1.0);
    val.imag(0);
    val2.real(0.0);
    val2.imag(0);
            CHECK((solve((x ^ 2) == x ) == val || solve((x ^ 2) == x) == val2));
    val.real(2.0);
    val.imag(0);
    val2.real(-1.0);
    val2.imag(0);
            CHECK((solve((x^2)  ==  x +2) == val || solve((x ^ 2) == x + 2) == val2));
}

// TEST_CASE("exceptions"){
//     RealVariable x;
//     CHECK_THROWS(solve((x^3)==9));
//     CHECK_THROWS(solve((x^2)==-16));
//     CHECK_THROWS(solve(x*x==-16));
//     CHECK_THROWS(solve((x^2)+30==15));
//     CHECK_THROWS(solve((x^2)==4));
//     CHECK_THROWS(solve(x/0));
//     CHECK_THROWS(solve((x*x)/0));
//     CHECK_THROWS(solve((x^7)+40==10));
//     CHECK_THROWS(solve((x^2)*x==4*x-4));
//     //CHECK_THROWS(solve(4/x==(x^3)));
// }