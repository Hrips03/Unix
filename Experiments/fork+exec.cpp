#include <iostream>

double calculateAreaOfTriangle(double height, double base)
{
    return 0.5 * height * base;
}

int main()
{
    double height = 0;
    double base = 0;
    std::cout << "Enter a height of triangle: ";
    std::cin >> height;
    std::cout << "Enter a base of triangle: ";
    std::cin >> base;
    std::cout << "This is a child process after exec, and the area of triangle is: " << calculateAreaOfTriangle(height, base) << "\n";
    return 0;
}