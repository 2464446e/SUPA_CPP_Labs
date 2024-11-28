#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <fstream>
#include<cstdlib>
#include <sstream>
#include "plotter.h"
#include "file_reader.h"
using namespace std; 

float mag(std::vector<std::vector<float>> vect, int r){
    float k = vect[r][0]; 
    float j = vect[r][1];

    float sum = sqrt(k*k + (j*j));
    return sum;
}

// what I want to do, is extract all the lines of the
// file without knowing the no. of rows, and then split 
// each column inti x and y i.e. separate vectors.

int Loading(std::vector<vector<float>> vecofvecs){
    //std::cout<< "The equation of the line is given by y = "<< plot(vecofvecs,24)[0] <<"x + "<< plot(vecofvecs,24)[1]<< std::endl;
    std::cout <<"Now, select an action to perform on the data: print or magnitude?"<<std::endl;
    string command;
    std::cin >> command;
    string outcome  = command;
    std::cout << "You have chosen to get "<< outcome <<"."<<std::endl;
    if(outcome == "print"){
        std::cout<< "Select highest row number (from 1 to 25)."<< std::endl;
        string n;
        std::cin >> n; 
        bool ValidValue =false;
        if (std::stoi(n)-1> 24){
       do{std::cout<< "Please enter integer number from 1 to 25."<<std::endl;
       std::cin >> n;
       ValidValue= std::stoi(n)-1<=25;}
       while(!ValidValue);{
            std::cout << "You have chosen to get "<< n <<" rows."<<std::endl;
                for (int j =0; j <= std::stoi(n)-1; j++){
                     cout << vecofvecs[j][0]<<", "<< vecofvecs[j][1] <<endl;
                     };
        }
    }
    else{std::cout << "You have chosen to get "<< n <<" rows."<<std::endl;
                for (int i =0; i <= std::stoi(n)-1; i++){
                     cout << vecofvecs[i][0]<<", "<< vecofvecs[i][1] <<endl;
                     };

    }
    }
     else{ if(outcome == "magnitude"){ 
        cout<< "Enter max row number:"<<endl;
        string n; 
        cin >> n ;
        cout<< "You entered "<< std::stod(n)-1 <<"."<<endl;
        for (int i =0; i <= std::stod(n)-1 ; i++){
        std::cout << "The magnitude of row "<< i+1 << " is " << mag(vecofvecs, i) << "."<<std::endl; };
    // checking that the vectors has been correctly assigned. 
    //std::cout << "sanity check, finding row 6 column 1 in vecofvecs: " << vecofvecs[6][1] <<std::endl;
    
     }
    else{
        std::cout<<"Wrong commmand. Reload the file and choose from the two options."<<std::endl;
        return -1;
    }
    }
cout << "File has completed its function, continue with compiling..."<<endl;
return 0;
}
// moving forward: make this more functional for any file e.g. error file too. Try to make generic function which reads size of string and converts to vecofvecs.
//defining the form of chi for each element of the sum:
float enter(float o, float t, float e){
float result =(o- t)*(o-t)/(e*e);
return result;
}
//defining the final chi squared value, calling plot() for the expected value and mag() to
//get magnitude of the errors:
float chi(vector<vector<float>> vals, vector<vector<float>> errors){
    float tot_chi =0;

    for(int i =0; i<=24 ;++i ){
        float t = plot(vals,24)[0]*vals[i][0] +plot(vals,24)[1];
        tot_chi =+ enter(vals[i][1], t, mag(errors, i));};
    return tot_chi;
}
//defining the x^y function:
float xuparrowy(float x, float y){
   if (std::round(y) == 0)
   return 1;
   else
   return (x* xuparrowy(x, std::round(y)-1));}
// defining function to write full xtoy file:
vector<float> xtoy(vector<vector<float>> vals){
vector<float> empty;
for(int i=0; i <= 24 ;++i ){
empty.push_back(xuparrowy(vals[i][0], vals[i][1]));
};
return empty;
}