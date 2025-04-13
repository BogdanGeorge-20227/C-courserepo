#include <iostream>

int main(){
    int n;
    std::cin>>n;
    while (n>=0){
        if(n!=0){
            std::cout<<n*n<<std::endl;
        }
        std::cin>>n;
    }
    return 0;
}