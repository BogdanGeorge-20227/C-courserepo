#include <iostream>

#define swap1(a,b) (c=a, a=b,b=c)
float a=2,b=3,c;
void swapUsingRef(float &a, float &b){
    float c;
    c=a;
    a=b;
    b=c;
}

void swapUsingPointers(float *a, float *b){
    float c;
    c=*a;
    *a=*b;
    *b=c;
}

int main(){
    float* ptra =&a;
    float* ptrb=&b;

    std::cout<<"no swap:"<<a<<' '<<b<<std::endl;
    swapUsingRef(a,b);
    std::cout<<"1st swap:"<<a<<' '<<b<<std::endl;
    swap1(a,b);
    std::cout<<"2nd swap:"<<a<<' '<<b<<std::endl;
    swapUsingPointers(ptra,ptrb);
    std::cout<<"3rd swap:"<<a<<' '<<b<<std::endl;
    return 0;
}