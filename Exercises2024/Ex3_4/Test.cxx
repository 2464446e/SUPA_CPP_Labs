#include <filesystem>
#include "FiniteFunctions.h"
#include <map>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include<cstdlib>
#include <random>
#include <sstream>
#pragma once
#include "gnuplot-iostream.h"
using namespace std;

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

class Test1: public FiniteFunction{public:
using FiniteFunction::FiniteFunction;
double callFunction(double x) {
    return func1(x,1.5,0.05);}};
class Test2: public FiniteFunction{public:
using FiniteFunction::FiniteFunction;
double callFunction(double x) {
    return func2(x, 1.75,0.05);}};
// This ^^ function is likely the most accurate fit to this data. 
class Test3: public FiniteFunction{public:
using FiniteFunction::FiniteFunction;
double callFunction(double x) {
    return func3(x, 50,30,29,50);}};


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

//Now, wish to impliment this such that we generate an arbitrarily long set of data (vector)
// which can be our x:
vector<double> generator(int size){
    cout << "running function"<<endl;
   vector<double> vectobject;
   int shape = size;
   std::random_device genx{};
   std::mt19937 distrx{genx()};
   std::uniform_real_distribution<float> arb{-10, 10};
   std::uniform_real_distribution<float> STD{0, 10};
   float val = arb(distrx);
   float std = STD(distrx);
   float initialx = func2(val, 1.75, 0.05);
   for(int i =0; i <= shape; ++i){
std:random_device geny{};
std::mt19937 distry{geny()};
std::normal_distribution<float> d{val,std};
float y = func2(d(geny) ,1.75,0.05);
float x;
if(i <1){x = initialx;}else{x= vectobject[i-1];};
double div = y/x;
double comp = 1;
float Amin = std::min(div, comp);
 // Now, generating T:
std::random_device Tgen{};
std::mt19937 creating{Tgen()};
std::uniform_real_distribution<float> arb{0, 1};
float T = arb(creating);
if(T<Amin){
    vectobject.push_back(y); }
    //cout <<y <<endl;}
    else{vectobject.push_back(x);};}
    //cout<< x<< endl;}
return vectobject;}

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
Test2 myfunction(-10, 10, "SecondFunction");
myfunction.plotFunction();
myfunction.printInfo();
//plotdata takes mystertdata x values, assigns them to one of n bins (specidied by the Nbins object), and
//plots these bins (y's are the density of the bin)
myfunction.plotData(mystvec, 250, true); 
//now need to redefine the integration function to output correctly normalised plot. 
//std::cout << func3(1, 0,3,4,5) <<std::endl;;

// Now, attempt to create random numbers:
unsigned int seed = 86;
unsigned int nut = 5;
std::mt19937 mtEngine{seed};
std::uniform_real_distribution<float> uniform{-10, 10};
std::uniform_real_distribution<float> STD{0, 10};
float randx = uniform(mtEngine);
float std = STD(mtEngine);
cout << "this: " <<randx << " and this: "<< std << "." << endl;
std:random_device rd{};
std::mt19937 gen{rd()};
std::normal_distribution<float> d{randx,std };
float randy = d(gen);
std::cout << randy << std::endl;
float y = func2(randy ,1.75,0.05);
float x = func2( randx,1.75,0.05);
double div =  y/x;
double comp = 1;
cout << y/x <<endl;
float Amin = std::min(div, comp);
cout << Amin << endl;
 // Now, generating T:
std::random_device Tgen{};
std::mt19937 creating{Tgen()};
std::uniform_real_distribution<float> arb{0, 1};
float T = arb(creating);
cout << "T = "<< T <<endl;
float xi;
if(T<Amin){
    xi = y; }
    else{xi = x;};
cout <<x<<", " << ", "<< y<< ", "<< xi <<endl;


//Have created a function called generator which creates a double of length (), using the function we specified
vector<double> metropolis = generator(1000);
//Final task is to try and impliment this sampled data (y values for the function and their corresponding x's
//i.e. random numbers suupplied, to get a sample trendline. )
return 0; 
}





