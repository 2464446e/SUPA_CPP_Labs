#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <fstream>
#include<cstdlib>
#include <sstream>
#include"CustomFunctions.h"

int main(){

vector<vector<float>>values = read();
//Loading(values);
vector<vector<float>> errors = read();
//Loading(errors);
cout << "Chi squared value for the plot: "<< chi(values, errors) << endl;
for(int i=0; i<=24; ++i){
cout << "value of x^y for line " << i +1 <<" is " << xtoy(values)[i]<<". "<<endl;}
}