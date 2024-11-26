#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <fstream>
#include<cstdlib>
#include <sstream>

float mag(std::vector<std::vector<float>> vect, int r){
    
    float k = vect[r][0];
    float j = vect[r][1];

    float sum = sqrt(k*k + (j*j));
    return sum;
}

