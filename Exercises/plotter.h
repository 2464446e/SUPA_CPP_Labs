#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <fstream>
#include<cstdlib>
#include <sstream>
using namespace std; 

vector<float> plot(std::vector<std::vector<float>> vect, int r){
    float sumx =0;
    float sumy =0;
    float sumxy=0;
    float sumxsq =0;
    for( int i =0; i <= r; i++){
        sumx +=vect[i][0];
        sumy +=vect[i][1];
        sumxy += vect[i][0]*vect[i][1]; 
        sumxsq += vect[i][0]*vect[i][0];}
    float grad = (r*sumxy - sumx*sumy)/(r*sumxsq - sumx*sumx);
    float intercept = (sumy -grad*sumx)/r;
    vector<float> linear = {grad, intercept};
return linear;
}