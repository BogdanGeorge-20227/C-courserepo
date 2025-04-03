#include <iostream>

int main(){
    int n,s=0;
    std::cin>>n;
    for(char i=1;i<=20;i++){
        s+=n%10;
        n=n/10;
        if(n==0)break;
    }
    std::cout<<std::endl<<s;
    return 0;
}