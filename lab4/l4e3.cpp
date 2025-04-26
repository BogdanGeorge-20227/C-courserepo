#include <iostream>
#include <string>

class Car{
    private:
    std::string m_name;
    int year, price;

    public:
    Car(std::string mn,int y,int p){
        m_name=mn;
        year=y;
        price=p;
        std::cout<<"Car constructor: "<<m_name << " from "<<year<<" costs "<<price<<std::endl;
    }
    Car(){
        m_name="Nullbrand";
        year=0;
        price=0;
    }
    ~Car(){}
    void display(){
        std::cout<<"Model: "<<m_name<<", from: "<<year<<", that costs: "<<price<<std::endl;
    }
};

class CarCollection{
    private:
    Car* cars;
    int nr_cars;

    public:
    CarCollection(){
        std::string constr_model;
        int constr_year, constr_price;
        std::cout<<"Input nr of cars: "<<std::endl;
        std::cin>>nr_cars;
        std::cin.ignore(); //comment for task 4 output
        cars=new Car[nr_cars];

        for(int i=0;i<nr_cars;i++){         //we read the car data one by one
            std::cout<<"Input model, year and price of car "<<i+1<<':'<<std::endl;
            std::getline(std::cin,constr_model);
            std::cin>>constr_year;
            std::cin>>constr_price;
            std::cin.ignore(); //comment for task 4 output
            cars[i]= Car(constr_model,constr_year,constr_price);
        }
        std::cout<<"Car collection constructor: collection has "<<nr_cars<<" cars"<<std::endl;
    }
    ~CarCollection(){
        delete[] cars;
        std::cout<<"Car collection destroyed"<<std::endl;
    }
    void displaycars(){
        std::cout<<"Cars currently in the collection:"<<std::endl;
        for(int i=0;i<nr_cars;i++){
            cars[i].display();
        }
    }
};

int main(){
    CarCollection* collection =new CarCollection();
    collection->displaycars();
    delete collection;
    std::cout<<"End";
    return 0;
}