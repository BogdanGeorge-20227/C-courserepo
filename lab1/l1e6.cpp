#include <iostream>

int main(){
    int n,rev=0;
    std::cin>>n;
    for(char i=1;i<=20;i++){
        rev=rev*10+n%10;
        n=n/10;
        if(n==0)break;
    }
    std::cout<<std::endl<<rev;
    return 0;
}