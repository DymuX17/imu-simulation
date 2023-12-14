#include "../include/data_read.h"

int input()
{
    int a;
    char c;
    bool war = false;
    do
    {
        if (war == true)
        {
            std::cout << "Podaj poprawna wartosc liczby: ";
        }
        std::cin >> a;

        std::cout << "Wprowadzona liczba: " << a << std::endl;
        std::cout << "Czy poprawna? [t/n] ";
        std::cin >> c;
        war = true;
    } while ((c != 't') && (c != 'T'));
    return a;
}