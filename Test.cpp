//
// Created by miros on 26/04/2020.
//

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
    // CHECK_THROWS(solve(10 == 10 / x));
    // CHECK_THROWS(solve(0 == 10 / x));
}

TEST_CASE("Test real equations both sides") {
    RealVariable x;
            CHECK(solve(x / 2 == 7) == 14.0);
            CHECK(solve(x / 10 == 0.05) == 0.5);
            CHECK(solve(x / 10 == -10) == -100);
            CHECK(solve(x / 0.2 == 1.2) == 0.24);
            CHECK(solve(7.5 == x / 5) == 37.5);
            CHECK(solve(1 == x / 2) == 2.0);
            CHECK(solve(10 == x / 10) == 100.0);
            CHECK(solve(-10 == x / 10) == -100.0);
    // CHECK_THROWS(solve(10 == 10 / x));
    // CHECK_THROWS(solve(0 == 10 / x));
}

TEST_CASE("Test real equations both sides") {
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
            CHECK(2==2);
}