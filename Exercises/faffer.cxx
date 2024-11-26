#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <fstream>
#include<cstdlib>
#include <sstream>
#include"CustomFunctions.h"

int main(){
std::vector<float> col1 = {1.1, 1.2, 1.3, 1.4};
std::vector<float> col2 = {2.1, 2.4, 4.5, 18.4};
float nsum =0;
for(int i = 0; i <=3; i++){
      nsum += col1[i];
}
cout << nsum << endl;
Loading();
}