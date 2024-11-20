#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>

float mag(float i, float j) {
    float sum = sqrt(i*i + (j*j));
    return sum;
}

int main()
{std:: cout << "Awrite mate!"<< std::endl;


//float x = 2.3;
//float y = 4.5;

float user_x;
std::cout << "gees yir x value:"<<std::endl;
std::cin >> user_x;

float user_y;
std::cout << "gees yir y value:"<<std::endl;
std::cin >> user_y;

std::vector<float> data= {user_x, user_y};

std::cout << "The magnitude of the vector with components x =" << user_x << "and y = " << user_y <<" is "<< mag(data[0], data[1])<< "."<<std::endl;
return 0;
}





















