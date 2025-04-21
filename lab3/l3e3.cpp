#include <iostream>
#include <string>

class car{
    private:
    std::string brand;
    int year;

    public:
    car(std::string br, int yr){
        brand=br;
        year=yr;
        std::cout<<"Car "<<brand<<" from "<<year<<" created."<<std::endl;
    }
    ~car(){
        std::cout<<"Car "<<brand<<" destroyed"<<std::endl;
    }

    void showinfo(){
        std::cout<<brand<<' '<<year<<std::endl;
    }
};
int main(){
    car* car1= new car("Nissan", 2009);
    car1->showinfo();
    delete car1;
    return 0;
}