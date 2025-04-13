#include <iostream>

int main(){
    int a = 100;
    int& refA = a; // Reference to a
    std::cout<<a<<' ';
    refA = 30; // Modifying refA modifies a
    std::cout<<a<<' ';
    return 0;
}