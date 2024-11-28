#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <fstream>
#include<cstdlib>
#include <sstream>
using namespace std; 

vector<vector<float>> read(){
    std::cout << "write file path here:"<<std::endl;
    string name;
    std::cin >> name;
    string filename = name;
    std::cout << "You have chosen to access the following directory: "<< filename <<". "<<std::endl;
    std::ifstream MyInput;
    MyInput.open(filename);
    if(MyInput.fail()){
         std::cout<< "failure"<<std::endl; }
         else{std::cout<< "File has been successfully opened."<<std::endl;
         };
    std::vector<string> rows;
    std::vector<int> data;
    std::string line;
    std::vector<std::vector<float>> vecofvecs;
     bool fstline = true;
        while(std::getline(MyInput, line)){
            if(fstline == true){
                fstline =false;
                continue;}
                std::vector<float> points;
                std::stringstream ss(line);
                std::string string_point;
                while(std::getline(ss, string_point, ',' )){
                    float float_point = std::stod(string_point);
                    points.push_back(float_point);}
                    vecofvecs.push_back(points);};
        
            return vecofvecs;}
