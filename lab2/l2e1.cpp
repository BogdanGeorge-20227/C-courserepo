#include <iostream>
#include <cmath>

int prod(int a, int b){
    return a*b;
}

double prod(double a,double b){
    return a*b;
}

double prod(int a, double b, bool mode){
if(mode) return ((double)a)*b;
else return floor(((double)a)*b);
}

int main(){
    std::cout<<"integer product: "<<prod(2,3)<<std::endl;
    std::cout<<"double product: "<<prod(-2.2,3.33)<<std::endl;
    std::cout<<"int and double product, cast to double: "<<prod(2,3.23,true)<<std::endl;
    std::cout<<"int and double product, floored: "<<prod(2,3.23, false)<<std::endl;
    return 0;
}