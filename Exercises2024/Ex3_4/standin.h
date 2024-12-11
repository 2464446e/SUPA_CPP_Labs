#include <string>
#include <vector>
#include "gnuplot-iostream.h"
#pragma once
#include "FiniteFunctions.h"

class Test: public FiniteFunction { 
    public:
    Test(); //Empty constructor
    Test(double range_min, double range_max, std::string outfile);
    double callFunction(double x);

    
    protected:
    double func1(double x, double sig, double nu);
    double func2(double x, double gam, double xo);
    double func3(double x,double xm, double sig, double n, double alph);

};