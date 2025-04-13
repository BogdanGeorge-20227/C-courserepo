#include <iostream>

struct Student{
    char name[50];
    int stud_ID;
    float grade;
}Student_register[50];

void displayAll(int n){
    for (int i=0;i<=n;i++){
        std::cout<<Student_register[i].name<<std::endl;
    }
}
void search(int ID, int n){
for(int i=0;i<=n;i++){
if(Student_register[i].stud_ID==ID)std::cout<<"Student found: "<<Student_register[i].name<<std::endl;
}
}
int main(){
    int select=0,n=0;
    while(select>=0){
    std::cout<<"Choose (1:add, 2:display all, 3:search, -1:exit): "<<std::endl;
    std::cin>>select;
    switch(select){
        case 1:
        std::cout<<"Name, ID, grade: "<<std::endl;
        std::cin>>Student_register[n].name>>Student_register[n].stud_ID>>Student_register[n].grade;
        n++;
        break;

        case 2:
        displayAll(n);
        break;

        case 3:
        std::cout<<"Enter ID to be searched: "<<std::endl;
        int ID_search;
        std::cin>>ID_search;
        search(ID_search,n);
        break;
    }
}
}