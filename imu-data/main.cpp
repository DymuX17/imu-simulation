#include "./include/data_read.h"

int main()
{
    int input;
    do
    {
        std::cout << "Press [1] imput data.csv and start simulation" << std::endl;
        std::cout << "Press [2] to start simulation" << std::endl;
        std::cout << "Press [0] to exit" << std::endl;
        std::cout << "Your choice: " << std::endl;
        std::cin >> input;
        switch (input)
        {
        case 1:
            read();
            break;

        case 2:
            simulation_process();
            break;

        default:
            break;
        }
    } while (input != 0);

    return 0;
}