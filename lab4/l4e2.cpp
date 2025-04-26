#include <iostream>
#include <string>

class Book{
    private:
    std::string title;
    int pages;

    public:
    Book(std::string t,int p){
        title=t;
        pages=p;
        std::cout<<"Constructor: "<<title << " with "<<pages<<" pages"<<std::endl;
    }
    Book(){
        title="Untitled";
        pages=0;
    }
    ~Book(){
        std::cout<<"Destructor: "<<title<<" destroyed"<<std::endl;
    }
    void display(){
        std::cout<<"Title: "<<title<<", pages: "<<pages<<std::endl;
    }
};

class BookShelf{
    private:
    Book* books;
    int size;

    public:
    BookShelf(){
        size=3;
        books = new Book[size]{
            Book("C++ Fundamentals", 300),
            Book("Minigolf for real ones", 400),
            Book("HMS Belfast", 500)
        };
        std::cout<<"Bookshelf constructor: shelf has "<<size<<" books"<<std::endl;
    }
    ~BookShelf(){
        delete[] books;
        std::cout<<"Bookshelf destroyed"<<std::endl;
    }
    void displayBooks(){
        std::cout<<"Books currently on the shelf:"<<std::endl;
        for(int i=0;i<size;i++){
            books[i].display();
        }
    }
};

int main(){
    BookShelf* shelf =new BookShelf();
    shelf->displayBooks();
    delete shelf;
    std::cout<<"End";
    return 0;
}