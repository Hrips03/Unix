#include <iostream>
#include <string>
//stack and heap are not visiable in nm

int *pointer = new int[10];         // B - BSS, no name mangling
int *init = nullptr;                // B - BSS, no name mangling
char c = 'c';                       // D - data segment, no name mangling
const char *ptr = "Hripsime";       // D - data segment, no name mangling
const char *ptr2;                   // B - BSS, no name mangling
static int number = 12;             // d - data segment for static's, _ZL6number
static double no;                   // b - BSS for static's, _ZL2no
const int initnum = 27;             // r - read-only data segment, _ZL7initnum
int* uninit;                        // B - BSS, no name mangling
const int* constUninit;             // B - BSS, no name mangling
const int* constInit = nullptr;     // B - BSS, no name mangling
const int* constINIT = &initnum;    // D - data segment, no name mangling
std::string name = "Hripsime";      // B - BSS,  _Z4nameB5cxx11 (B5cxx11) - shows that it belongs to std::stiring, it's in a BSS because it initilaizes at runtime
std::string surname;                // B - BSS, _Z7surnameB5cxx11 (C++ 11 standardic ka sa dra hamar cxx11, B - binary/ABI, 5 length of cxx11)
static std::string sname;           // b - BSS for static's, _ZL5sname
std::string* ptrsurname;            // B - BSS, _Z10ptrsurnameB5cxx11
std::string* sptr = new std::string("Hello, Hripsime!"); // B - BSS, _Z4sptrB5cxx11
const std::string* csptr = new std::string("Hello!");    // B - BSS, _Z5csptrB5cxx11
//_Z - indicates that the following name is mangled and it's a C++ symbol. It distinguishes C++ names from C names.
// L - indicates that these symbols are local to the translation unit, because they are static.


void print(const char *msg = "hello") // T - text segment, _Z5printPKc, P -pointer, K - constant, c - char
{
    int var; //not visible for nm
    std::cout << "Char*: " << msg << std::endl;
}

void print(int msg) // T - text segment, _Z5printi, i - int
{
    std::cout << "Int: " << msg << std::endl;
}

void print(int* msg) // T - text segment, T _Z5printPi, P -pointer,i - int
{
    std::cout << "Int*: " << *msg << std::endl;
}

void print(const int* msg) // T - text segment, _Z5printPKi, P -pointer, K - constant, i - int
{
    std::cout << "Const int*: " << *msg << std::endl;
}

void print(double msg) // T - text segment, _Z5printd, d - double
{
    std::cout << "Double: " << msg << std::endl;
}

int main() // T - text segment, no name mangling
{
    const int a = 22;
    int b = 10;
    print();
    print("Hello World!");
    print(111);
    print(&b);
    print(&a);
    print(22.5);
}

// t - text segment (the segment where the executable code resides). It typically refers to functions. ???
// T - text segment, but it’s a global symbol (visible outside the current translation unit).
// r - read-only data segment. It usually refers to global constants.
// R - read-only data segment, but this indicates a global read-only symbol.
// w - writable data segment, which contains global variables that can be modified.
// W - similar to w, but this indicates a global writable symbol.
// U - undefined symbol. It is used for symbols that are referenced but not defined in the current object file.