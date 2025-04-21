#include <iostream>
#include <string>

class vehicle{
    protected:
    std::string brand;
    int year;

    public:
    vehicle(std::string br, int yr){
        brand=br;
        year=yr;
    }
    vehicle(){
        brand="Default";
        year=0;
    }
    void showinfo(){
        std::cout<<brand<<' '<<year<<std::endl;
    }
    void startEngine(){
        std::cout<<"Starting engine of the vehicle"<<std::endl;
    }
};

class car:public vehicle{
    private:
    int numDoors;
    public:

    car(std::string br, int yr, int nD):vehicle(br,yr){
        numDoors=nD;
    }
    car():vehicle(){
        numDoors=0;
    }
    void showinfo(){
        std::cout<<brand<<' '<<year<<' '<<numDoors<<std::endl;
    }
    void startEngine(){
        std::cout<<"Car engine is starting!"<<std::endl;
    }
    int get_nD(){
        return numDoors;
    }
};

class electric_car:public car{
    private:
    int battery_capacity;
    public:
    electric_car(std::string br, int yr, int nD,int bc):car(br,yr,nD){
        battery_capacity=bc;
    }
    electric_car():car(){
        battery_capacity=0;
    }
    void showinfo(){
        std::cout<<brand<<' '<<year<<' '<<get_nD()<<' '<<battery_capacity<<std::endl;
    }
    void startEngine(){
        std::cout<<"Electric engine is starting... Silent but powerful!"<<std::endl;
    }
};
int main(){
    /*
    vehicle* v1=new vehicle("Hitachi",2024);
    car* c1 = new car("Ford", 2007, 4);
    electric_car* ec1 =new electric_car("Mitsubishi", 2020, 4, 40000);

    v1->showinfo();
    v1->startEngine();
    c1->showinfo();
    c1->startEngine();
    ec1->showinfo();
    ec1->startEngine();
    delete v1;
    delete c1;
    delete ec1;
    */ //uncomment until here, comment latter part for initial task outputs, 
    electric_car* eCar = new electric_car("Nissan", 2022, 4, 40);
    eCar->showinfo();
    eCar->startEngine();
    delete eCar;
    return 0;
}