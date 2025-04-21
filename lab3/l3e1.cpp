#include <iostream>
#include <string>

class book{
    private:

    std::string title;
    int pagenr;
    std::string author="Peter";
    protected:

    float price;
    public:

    std::string publisher;

    //private:
    void displayAuthorInfo(){
        std::cout<<author<<std::endl;
    }
};

int main(){
    book book1;
    book1.displayAuthorInfo();
    return 0;
}