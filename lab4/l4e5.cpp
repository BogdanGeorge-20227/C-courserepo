#include <iostream>
#include <string>

class Car{
    protected:
    std::string m_name;
    int year;
    float price;

    public:
    Car(std::string mn,int y,float p){
        m_name=mn;
        year=y;
        price=p;
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

class ECar:public Car{
    private:
    float battery_cap;
    public:
    ECar(std::string model, int year, float price, float bat_cap):Car(model,year,price){
        battery_cap=bat_cap;
    }
    ECar():Car(){
        battery_cap=0;
    }
    void display(){
        std::cout<<"Model: "<<m_name<<", from: "<<year<<", costs "<<price<<"$, has battery capacity: "<<battery_cap<<" KWh"<<std::endl;
    }
    ~ECar(){}
    static void input_car_parameters(std::string &model, int &year, float &price, float &bat_cap){
        std::cout<<"Model: "<<std::endl;
        std::getline(std::cin,model);
        std::cout<<"Year: ";
        std::cin>>year;
        std::cout<<"Price: ";
        std::cin>>price;
        std::cout<<"Battery capacity (KWh): ";
        std::cin>>bat_cap;
    }
};
class GasCar:public Car{
    private:
    float fuel_cap;
    public:
    GasCar(std::string model, int year, float price, float f_cap):Car(model,year,price){
        fuel_cap=f_cap;
    }
    GasCar():Car(){
        fuel_cap=0;
    }
    void display(){
        std::cout<<"Model: "<<m_name<<", from: "<<year<<", costs "<<price<<"$, has fuel tank capacity "<<fuel_cap<<" l"<<std::endl;
    }
    ~GasCar(){}
    static void input_car_parameters(std::string &model, int &year, float &price, float &f_cap){
        std::cout<<"Model: "<<std::endl;
        std::getline(std::cin,model);
        std::cout<<"Year: ";
        std::cin>>year;
        std::cout<<"Price: ";
        std::cin>>price;
        std::cout<<"Fuel tank capacity (l): ";
        std::cin>>f_cap;
    }
};
class HyCar:public Car{
    private:
    float hbattery_cap,hfuel_cap;
    public:
    HyCar(std::string model, int year, float price, float bat_cap,float f_cap):Car(model,year,price){
        hbattery_cap=bat_cap;
        hfuel_cap=f_cap;
    }
    HyCar():Car(){
        hbattery_cap=0;
        hfuel_cap=0;
    }
    void display(){
        std::cout<<"Model: "<<m_name<<", from: "<<year<<", costs "<<price<<"$, has battery capacity "<<hbattery_cap<<" KWh,"<<" fuel tank capacity "<<hfuel_cap<<" l"<<std::endl;
    }
    ~HyCar(){}
    static void input_car_parameters(std::string &model, int &year, float &price, float &f_cap, float &bat_cap){
        std::cout<<"Model: "<<std::endl;
        std::getline(std::cin,model);
        std::cout<<"Year: ";
        std::cin>>year;
        std::cout<<"Price: ";
        std::cin>>price;
        std::cout<<"Fuel tank capacity (l): ";
        std::cin>>f_cap;
        std::cout<<"Battery capacity (KWh): ";
        std::cin>>bat_cap;
    }
};
class CarCollection{
    private:
    Car** cars;
    int nr_cars;
    int* cars_type;

    public:
    CarCollection(){
        std::string constr_model;
        int constr_year;
        float constr_price,constr_bat_cap, constr_fuel_cap;
        std::cout<<"Input nr of cars: "<<std::endl;
        std::cin>>nr_cars;
        std::cin.ignore();
        cars_type= new int[nr_cars];
        cars=new Car*[nr_cars];

        for(int i=0;i<nr_cars;i++){         //we read the car data one by one
            std::cout<<"Input type of car "<<i+1<< " (1-electric, 2-gasoline, 3-hybrid):"<<std::endl;
            std::cin>>cars_type[i];
            std::cin.ignore();
            if(cars_type[i] == 1) {
                ECar::input_car_parameters(constr_model,constr_year,constr_price,constr_bat_cap);
                cars[i] = new ECar(constr_model, constr_year, constr_price, constr_bat_cap);
            } else if(cars_type[i] == 2) {
                GasCar::input_car_parameters(constr_model,constr_year,constr_price,constr_fuel_cap);        //the functions return the paramaters via reference
                cars[i] = new GasCar(constr_model, constr_year, constr_price, constr_fuel_cap);             //the returned parameters are used for the constructors
            } else if(cars_type[i] == 3) {
                HyCar::input_car_parameters(constr_model,constr_year,constr_price,constr_fuel_cap,constr_bat_cap);
                cars[i] = new HyCar(constr_model, constr_year, constr_price, constr_bat_cap, constr_fuel_cap);
            }
        }
        std::cout<<"Car collection constructor: collection has "<<nr_cars<<" cars"<<std::endl;
    }
    ~CarCollection(){
        delete[] cars_type;
        for (int i = 0; i < nr_cars; i++) {
            delete cars[i];  // delete each individual car
            std::cout<<"Car "<<i+1<<" destroyed"<<std::endl;
        }
        delete[] cars;      // then delete the array
        std::cout<<"Car collection destroyed"<<std::endl;
    }
    void displaycars(){
        std::cout<<"Cars currently in the collection:"<<std::endl;
        for(int i=0;i<=nr_cars;i++){
        if(cars_type[i] == 1) {
            static_cast<ECar*>(cars[i])->ECar::display();
        } else if(cars_type[i] == 2) {
            static_cast<GasCar*>(cars[i])->GasCar::display();   //casting is done for the pointer to be able to call upon the member function of the right class
        } else if(cars_type[i] == 3) {                          //without casting, the base class Car display() function is called
            static_cast<HyCar*>(cars[i])->HyCar::display();
        }
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