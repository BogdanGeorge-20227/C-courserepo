#include <iostream>
#include <cmath>
class complex{
    public:
    float a,b,mod,phi;

    complex(){
        a=0;
        b=0;
        mod=0;
        phi=0;
    }
    complex(float real, float img){
        a=real;
        b=img;
        mod=find_magnitude(real, img);
        phi=find_phase(real,img);
    }

    private:
    float find_magnitude(float a, float b){
        return sqrt(a*a +b*b);
    }
    float find_phase(float a, float b){
        return atan(b/a);
    }
    public:
    friend std::ostream& operator<<(std::ostream& os, const complex& c);

    complex operator+(const complex& second_nr){
        return complex(a+second_nr.a,b+second_nr.b);
    }
    complex operator-(const complex& second_nr){
        return complex(a-second_nr.a,b-second_nr.b);
    }
    complex operator/(const complex& second_nr){
        return complex(mod/second_nr.mod*cos(phi-second_nr.phi),mod/second_nr.mod*sin(phi-second_nr.phi));
    }
};

std::ostream& operator<<(std::ostream& os, const complex& c){
    if(c.b>0)os<<c.a<<" + "<<c.b<<'i';
    else os<<c.a<<' '<<c.b<<'i';
    return os;
}

int main(){
    complex c1(4, 5), c2(2, -3);
    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "Sum = " << c1 + c2 << std::endl;
    std::cout << "Difference = " << c1 - c2 << std::endl;
    std::cout << "Quotient = " << c1 / c2 << std::endl;
return 0;
}