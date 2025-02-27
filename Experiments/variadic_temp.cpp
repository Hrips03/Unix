#include <iostream>

// Fold expressions
template <typename... args>
void print(args... arguments)
{
    // Unary: (op ... args) - katarvum operacian yuraqanchyur elementi het
    (std::cout << ... << arguments) << std::endl;
}

template <typename... Args>
auto sum(Args... args)
{
    // Binary ( args op ... ), ( ... op args ) - katarvuma operacian sksac amena dzax/aj elementic minchev verj, iranc mijev
    return (args + ...);
}

int main()
{
    print(3, 12, "Hello", 3.14f);
    std::cout << sum(1, 2, 3, 4) << std::endl;
}
