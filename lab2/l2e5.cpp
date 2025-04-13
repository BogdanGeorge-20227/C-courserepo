#include <iostream>

int main(){
    int ar[10]={1,2,3,4,5,6,7},arb[10];
    int* ptrar=ar;
    for(int i=0;i<=6;i++){
        arb[6-i]=*ptrar;
        ptrar++;
    }
    for(int i=0;i<=6;i++){
        std::cout<<arb[i]<<' ';
    }
}