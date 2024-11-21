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
 

int main (){
    using namespace std;


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
// what I want to do, is extract all the lines of the file without knowing the no. of rows, and then split each column inti x and y i.e. separate vectors
else{cout<< "File has been successfully opened."<<endl;
}

std::vector<string> rows;
std::vector<int> data;
std::string line;
int n = 25;
string x;
//for (int i =1; i <= 26; i++){
 // MyInput >> x;
  // cout <<" " << x << "; "<<endl;
   //rows.push_back(x);
  // }
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
        std::cout << string_point << std::endl;
        float float_point = std::stod(string_point);
        points.push_back(float_point);}
vecofvecs.push_back(points);

}

// checking that the vectos has been correctly assigned. 
std::cout << "sanity check for random float in vecofvecs:" << vecofvecs[6][1] <<std::endl; 

// Now, have defined a vector we can call that includes all of the data!! Want to clear the cycling of MyInput so as to read and print the rows.   
std::vector<float> magnitudes;
for(int i =0; i <= 25; i++){
    if(i <= 24){
   magnitudes.push_back(mag(vecofvecs, i));
   std::cout <<"Entry number " << i+1 << " is "<< magnitudes[i] <<"."<<std::endl;}
   // outstream object here to write to new string file.
 else{
    std::cout << "Vector of magnitudes succesfully created."<< std::endl; 
 }
}
}

//for (int i=1; i<=25; i++){std::cout << "line " << i << " contains the string " << rows[i] << "." << std::endl;}