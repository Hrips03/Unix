#include <iostream>

union U
{
    char p;
    int a;
    short b;

};

int main(){
    U ob;
    std::cout << sizeof(ob) <<std::endl;
}
