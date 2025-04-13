#include <iostream>

float calculation(float a, float b, char operand){
    switch (operand){
        case '+':
        return a+b;
        break;
        case '-':
        return a-b;
        break;
        case  '*':
        return a*b;
        break;
        case '/':
        return a/b;
        break;
    }
    return 0; //in case of error or erroneous input
}
int main(){
    int a,b;
    char op;
    std::cin>>a>>b>>op;
    std::cout<<"result: "<<calculation(a,b,op);
    return 0;
}