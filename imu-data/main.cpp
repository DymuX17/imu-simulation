#include "./include/data_read.h"

int main()
{
    int a, b;
    std::cout << "Podaj wartosc a: ";
    std::cin >> a;
    std::cout << "wartosc a wynosi: " << a << std::endl;

    std::cout << "Podaj wartosc b: ";
    std::cin >> b;
    std::cout << "wartosc b wynosi: " << b << std::endl;

    licz(a, b);

    return 0;
}