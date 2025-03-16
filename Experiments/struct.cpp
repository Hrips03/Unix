#include <iostream>

struct S1
{
    char p;
    short b;
    int a;
};

struct S2
{
    char p;
    int a;
    short b;

};

int main(){
    S1 ob1;
    std::cout << sizeof(ob1) <<std::endl;

    S2 ob2;
    std::cout << sizeof(ob2) <<std::endl;
}
