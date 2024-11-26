#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <fstream>
#include<cstdlib>
#include <sstream>
#include "plotter.h"
using namespace std; 

float mag(std::vector<std::vector<float>> vect, int r){
    std::cout << "Calling mag from an extrernal file..."<< std::endl;
    float k = vect[r][0]; 
    float j = vect[r][1];

    float sum = sqrt(k*k + (j*j));
    return sum;
}

// what I want to do, is extract all the lines of the
// file without knowing the no. of rows, and then split 
// each column inti x and y i.e. separate vectors.

int Load(){
    std::cout << "write file path here:"<<std::endl;
    string name;
    std::cin >> name;
    string filename = name;
    std::cout << "You have chosen to access the following directory: "<< filename <<". "<<std::endl;
    std::ifstream MyInput;
    MyInput.open(filename);
    if(MyInput.fail()){
         std::cout<< "failure"<<std::endl;
         return -1; }
         else{std::cout<< "File has been successfully opened. Now, select an action to perform on the data: print or magnitude?"<<std::endl;
         };
    std::vector<string> rows;
    std::vector<int> data;
    std::string line;
    std::vector<std::vector<float>> vecofvecs;
    string command;
    std::cin >> command;
    string outcome  = command;
    std::cout << "You have chosen to get "<< outcome <<"."<<std::endl;
    if(outcome == "print"){
        std::cout<< "Select highest row number (from 1 to 25)."<< std::endl;
        string n;
        std::cin >> n; 
        int size = std::stoi(n) +1;
        bool NotValidValue =false;
        if (size >= 26){
       do{std::cout<< "Please enter integer number from 1 to 25."<<std::endl;
       std::cin >> n;
       int size = std::stoi(n) +1;
       NotValidValue= size <=26;}
       while(!NotValidValue);{
                std::cout << "You have chosen to get "<< n <<" rows."<<std::endl;
                string x;
                for (int i =1; i <= size; i++){
                     MyInput >> x;
                     cout <<" " << x << "; "<<endl;
                     rows.push_back(x);
                     };
        }
    }
    else{std::cout << "You have chosen to get "<< n <<" rows."<<std::endl;
                string x;
                for (int i =1; i <= size; i++){
                     MyInput >> x;
                     cout <<" " << x << "; "<<endl;
                     rows.push_back(x);
                     };

    }
    }
     else{ if(outcome == "magnitude"){
        bool fstline = true;
        while(std::getline(MyInput, line)){
            if(fstline == true){
                fstline =false;
                continue;}
                std::vector<float> points;
                std::stringstream ss(line);
                std::string string_point;
                while(std::getline(ss, string_point, ',' )){
                    std::cout << string_point << std::endl;
                    float float_point = std::stod(string_point);
                    points.push_back(float_point);}
                    vecofvecs.push_back(points);};
        std::cout<< "The equation of the line is given by y = "<< plot(vecofvecs,24)[0] <<"x + "<< plot(vecofvecs,24)[1]<< std::endl;
    // checking that the vectors has been correctly assigned. 
    //std::cout << "sanity check, finding row 6 column 1 in vecofvecs: " << vecofvecs[6][1] <<std::endl;
    }
    else{
        std::cout<<"wrong commmand."<<std::endl;
        return -1;
    }
    }
}

