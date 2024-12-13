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
    std::cout << "running function"<<endl;
   vector<double> vectobject;
   int shape = size;
   std::random_device genx{};
   std::mt19937 distrx{genx()};
   std::uniform_real_distribution<float> arb{-10, 10};
   std::uniform_real_distribution<float> STD{0, 10};
   float val = arb(distrx);
  //cout << val << endl;
   float stand= STD(distrx);
   for(int i =1; i <= shape; ++i){
std::random_device geny{};
std::mt19937 distry{geny()};
std::normal_distribution<float> d{val,stand};
float y = d(geny);
float funcy = func2(y ,1.75,0.05);
float funcx;
//if(i <1)
//{float x = val;}
//else{
float x = vectobject[i-1];
funcx= func2(x, 1.75, 0.05);
double div = funcy/funcx;
double comp = 1;
float Amin = std::min(div, comp);
 // Now, generating T:
std::random_device Tgen{};
std::mt19937 creating{Tgen()};
std::uniform_real_distribution<float> arbit{0, 1};
float T = arbit(creating);
if(T<Amin){
    vectobject.push_back(y);}
   else{vectobject.push_back(x);}}
return vectobject ;
}

float init(int size){
int shape = size;
   std::random_device genx{};
   std::mt19937 distrx{genx()};
   std::uniform_real_distribution<float> arb{-10, 10};
   float val = arb(distrx);
   return val;}

float generation(float initial, int size, int i){
    std::random_device genx{};
   std::mt19937 distrx{genx()};
    std::uniform_real_distribution<float> STD{0, 10};
   int shape = size;
   float val = initial;
   float stand= STD(distrx);
std::random_device geny{};
std::mt19937 distry{geny()};
float funcx;
float x;
if(i <1){ x = val;}
else{ x = generation(initial, size,i-1);}
std::normal_distribution<float> d{x,stand};
float y = d(geny);
float funcy = func2(y ,1.75,0.05);
//having trouble with recursion!!
funcx= func2(x, 1.75, 0.05);
double div = funcy/funcx;
double comp = 1;
float Amin = std::min(div, comp);
 // Now, generating T:
std::random_device Tgen{};
std::mt19937 creating{Tgen()};
std::uniform_real_distribution<float> arbit{0, 1};
float T = arbit(creating);
if(T<Amin){return y;}
   else{return x;}
}
;
vector<double> combine(int size, int i){
    vector<double> into;
    float val = init(size);
    into.push_back(generation(val, 30, 30));
    return into;

}
float recur(int size, int i){
    int minus= abs(size-i);
    cout << minus<< endl;
    if(minus=size){return 6;}
    else{cout << recur(size, i-1) <<endl;
        return recur(size, i-1);};

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

//std::cout << mystvec[2] << std::endl;
//vector<double> metropolis = generator(10000);
    
// creating an instance of FiniteFunction with initialised constructors -5, 5 and a file name.
// Then, from the class, calling a function which plots a particular function based on random data.
//here, this is the default function. 
Test2 myfunction(-10, 10, "SecondFunction");
myfunction.plotFunction();
myfunction.printInfo();
myfunction.plotData(mystvec, 250, true); 

vector<double> vectobject =combine(100000, 100000);

//Now, plotting with the "sampled" data...
Test2 myfunctionagain(-10, 10, "SampledData");
myfunctionagain.plotFunction();
myfunctionagain.printInfo();
myfunctionagain.plotData(mystvec, 250, true); 
myfunctionagain.plotData(vectobject, 250, false);


cout << recur(5,5) <<endl;
//now need to redefine the integration function to output correctly normalised plot. 
//std::cout << func3(1, 0,3,4,5) <<std::endl;;

// Now, attempt to create random numbers:
//unsigned int seed = 86;
//unsigned int nut = 5;
//std::mt19937 mtEngine{seed};
//std::uniform_real_distribution<float> uniform{-10, 10};
//std::uniform_real_distribution<float> STD{0, 10};
//float randx = uniform(mtEngine);
//float std = STD(mtEngine);
//cout << "this: " <<randx << " and this: "<< std << "." << endl;
//std:random_device rd{};
//std::mt19937 gen{rd()};
//std::normal_distribution<float> d{randx,std };
//float randy = d(gen);
//std::cout << randy << std::endl;
//float y = func2(randy ,1.75,0.05);
//float x = func2(randx,1.75,0.05);
//double div =  y/x;
//double comp = 1;
//cout << y/x <<endl;
//float Amin = std::min(div, comp);
 // Now, generating T:
//std::random_device Tgen{};
//std::mt19937 creating{Tgen()};
//std::uniform_real_distribution<float> arb{0, 1};
//float T = arb(creating);
//cout << "T = "<< T <<endl;
//float xi;
//if(T<Amin){
//    xi = y; }
//    else{xi = x;};
//cout <<x<<", " << ", "<< y<< ", "<< xi <<endl;

//Have created a function called generator which creates a double of length (), using the function we specified
//Final task is to try and impliment this sampled data (y values for the function and their corresponding x's
//i.e. random numbers suupplied, to get a sample trendline. )


return 0;
}





