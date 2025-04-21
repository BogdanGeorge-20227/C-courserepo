#include <iostream>
#include <string>

class student{
    private:
    std::string name;
    int age;
    char grade;
    std::string group="2025 group";

    public:
    void setName(std::string n){name=n;}
    void setAge(int a){age=a;}
    void setGrade(char g){grade=g;}

    std::string getName(){return name;}
    int getAge(){return age;}
    char getGrade(){return grade;}

    void displayinfo(){
        std::cout<<getName()<<' '<<getAge()<<' '<<getGrade();
    }
};
int main(){
    student student1;
    student1.setAge(20);
    student1.setGrade('2');
    student1.setName("Phil Stevenson");
    std::cout<<student1.getName()<<' '<<student1.getAge()<<' '<<student1.getGrade()<<std::endl;
    student1.displayinfo();
    return 0;
}