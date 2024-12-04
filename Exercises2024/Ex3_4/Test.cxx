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

//Now, we whish to create some inheritence classes for myfunction which set new values for the function i.e.
double func1(double x, double sig, double nu){
    return exp(-((x - nu)/(2*sig))*((x - nu)/(2*sig)))/((sig)* sqrt(2*acos(0)))
;}
double func2(double x, double gam, double xo){ 
    if( gam > 0){return 1/(acos(0)*gam*(1+((x-xo)/(gam))*((x-xo)/(gam)))) ;}
    else{return -1;}
}
double func3(double x, double sig, double nu){
    
}


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
FiniteFunction myfunction(-10, 10, "SecondFunction");
myfunction.plotFunction();
myfunction.printInfo();
myfunction.integral(250);
//plotdata takes mystertdata x values, assigns them to one of n bins (specidied by the Nbins object), and
//plots these bins (y's are the density of the bin)
myfunction.plotData(mystvec, 250, true); 
//now need to redefine the integration function to output correctly normalised plot. 

std::cout << func2(0.1,2, 0.05) << std::endl;
return 0;

}


