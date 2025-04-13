#include <iostream>

int main(){
    int x = 100;
    int* p1 = &x; // Pointer 1 points to x
    int* p2 = p1; // Pointer 2 copies address (shallow copy)
    std::cout<<*p2<<' '<<p2;
    *p1=50;
    std::cout<<*p2<<' '<<p2;
    return 0;
}