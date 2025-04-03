#include <iostream>

#define Iter_max 50

int main(){
    for(char iter_count=2;iter_count<=Iter_max; iter_count++){
        std::cout<<((int)iter_count)<<' ';
    }
    return 0;
}