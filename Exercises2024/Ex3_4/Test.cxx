#include <filesystem>
#include "FiniteFunctions.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include<cstdlib>
#include <sstream>
#pragma once
#include "gnuplot-iostream.h"


//Now, we wish to create some inheritence classes for myfunction which set new values for the function i.e.
double func1(double x, double sig, double nu){
    return exp(-((x - nu)/(2*sig))*((x - nu)/(2*sig)))/((sig)* sqrt(2*acos(0)))
;}
double func2(double x, double gam, double xo){ 
    if( gam > 0){return 1/(acos(0)*gam*(1+((x-xo)/(gam))*((x-xo)/(gam)))) ;}
    else{return -1;}
}
double func3(double x,double xm, double sig, double n, double alph){

double C = n/((alph)*(n-1))*exp(-(abs(alph)*(alph))/sqrt(2)) ;
double D = sqrt(acos(0)/2)*(1+erf(abs(alph)/sqrt(2)));
double B = (n/abs(alph))-abs(alph);
double A = pow(n/abs(alph),n)*exp(-(abs(alph)*(alph))/sqrt(2));
double N = 1/(sig*(C+D));
if ((x-xm)/sig > -alph){ return exp(-(pow(x-xm, 2))/(2*sig*sig));

}
else{ return  A*pow(B-((x-xm)/sig), -n);
}
}

class Test: public FiniteFunction{public:
using FiniteFunction::FiniteFunction;
double callFunction(double x) {return func3(x, 50,6,29,3);}};

//Test::Test(){
  //m_RMin = -5.0;
 // m_RMax = 5.0;
 // this->checkPath("DefaultFunction");
 // m_Integral = NULL;
//}

//Test::Test(double range_min, double range_max, std::string outfile){
 // m_RMin = range_min;
 // m_RMax = range_max;
 // m_Integral = NULL;
 // this->checkPath(outfile); //Use provided string to name output files
//}


//double FiniteFunction::callFunction(double x){FiniteFunction::callFunction(x);{return this->func2(x, 5, 6);}};
int main(){

// need to read in mystery data:
std::ifstream mystdata;
mystdata.open("Outputs/data/MysteryData13346.txt");
if(mystdata.is_open()){
std::cout << "mystdata successfully opened"<< std::endl;};
std::string line;
std::vector<double> mystvec;
while(std::getline(mystdata, line)){
    std::stringstream ss(line);
    std::string string_point;
    while(std::getline(ss, string_point)){
                    double point = std::stod(string_point);
                    mystvec.push_back(point);}};

std::cout << mystvec[2] << std::endl;
    
// creating an instance of FiniteFunction with initialised constructors -5, 5 and a file name.
// Then, from the class, calling a function which plots a particular function based on random data.
//here, this is the default function. 
Test myfunction(-10, 10, "SecondFunction");
myfunction.plotFunction();
myfunction.printInfo();
//plotdata takes mystertdata x values, assigns them to one of n bins (specidied by the Nbins object), and
//plots these bins (y's are the density of the bin)
myfunction.plotData(mystvec, 250, true); 
//now need to redefine the integration function to output correctly normalised plot. 
//std::cout << func3(1, 0,3,4,5) <<std::endl;
return 0;

}


