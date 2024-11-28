

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
vector<vector<float>> errors = read();
cout << "Which function would you like to perform?"<< endl;
cout << "1) Obtain and save the equation of the line,"<< endl;
cout << "2) Obtain and save the Chi squared of the fit, or" << endl;
cout << "3) Obtain and save the x^y for each datapoint?,"<< endl;
string option;
cin >> option;
int choice = std::stoi(option);
switch (choice){

case 1:{
        ofstream f;
        f.open("line_eq.txt");
        if (f.good()){
            f<< "The equation of the line is given by"<<endl;
            f<< "y="<<plot(values,24)[0] <<"x + "<< plot(values,24)[1]<< std::endl;};
        f.close(); 
        cout<< "The equation of the line is given by y = "<< plot(values,24)[0] <<"x + "<< plot(values,24)[1]<< std::endl;
        break;}
case 2:{
    fstream f;
    f.open("ch_sq.txt");
    if (f.good()){
            f<< "The equation of the line is given by"<<endl;
            f<< "y="<<plot(values,24)[0] <<"x + "<< plot(values,24)[1]<< std::endl;};
            f.close();
    cout << "Chi squared value for the plot: "<< chi(values, errors) << endl;
    break;}
case 3:{
    ofstream f;
    f.open("xtoy.txt");
    if (f.good()){
            f<< "values of x^y for each consecutive row:"<<endl;
            for(int j = 0; j<=24; ++j ){
            f<< xtoy(values)[j] << endl;
            cout << "value of x^y for line " << j+1 <<" is " << xtoy(values)[j]<<". "<<endl;};
            f.close();}
            break;}
default:{
cout << "Reload this file and try again!!"<<endl;}
}
}