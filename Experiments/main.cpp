#include <iostream>

class A{
    public:
    A(){
        std::cout << "print befor main: A()\n";
    }
    ~A(){
        std::cout << "print after main: ~A()\n";
    }
};

A obj;

int main(){
    std::cout << "print in main\n";
}