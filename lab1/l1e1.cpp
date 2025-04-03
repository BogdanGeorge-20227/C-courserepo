#include <iostream>
#include <string>

namespace MathOperations{
    int add(int a, int b){
        return a+b;
    }
}

namespace TextOperations{
   std::string concat(std:: string a, std:: string b){
        return a+b;
    }
}

int main(){
   std::cout<<MathOperations::add(2,3)<<std::endl;
   std::cout<<TextOperations::concat("I want ","sweet chocolate")<<std::endl;
   return 0;
}