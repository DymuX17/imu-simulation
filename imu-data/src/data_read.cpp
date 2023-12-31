#include "../include/data_read.h"

void read()
{
    int i = 0, j = 0;
    int pom;

    int z;
    bool value = true;
    const int prec = 10;

    std::string dane;
    std::string dane_pom;
    std::string dane_pom2;

    std::fstream file;
    file.open("../data.csv", std::ios::in);

    std::cout << "Podaj ile sekund chcesz symulowac: ";
    std::cin >> pom;

    const int col_num = 6;
    const int row_num = pom * HZ;
    const int arr_num = col_num * row_num;

    double **arr;
    arr = new double *[row_num];

    for (i = 0; i < row_num; i++)
    {
        arr[i] = new double[col_num];
    }

    std::cout << "Liczba wierszy do symulacji to: " << row_num << "\n\n";

    if (file.good() == true)
    {
        std::cout << "Udalo sie otworzyc plik do odczytu\n\n";

        getline(file, dane_pom2, '\n');

        for (j = 0; j < row_num; j++)
        {

            for (i = 0; i < col_num; i++)
            {

                if (i < 5)
                {
                    getline(file, dane, ',');
                    arr[j][i] = stod(dane);
                }
                else if (i == 5)
                {
                    getline(file, dane, '\n');
                    arr[j][i] = stod(dane);
                }
                else
                {
                    std::cout << "Blad!!!";
                    file.close();
                }

                std::cout << "[" << j << "][" << i << "]: " << arr[j][i] << "\t";
            }
            std::cout << "\n";
        }
        file.close();
    }

    do
    {
        if (value == true)
        {
            std::cout << "\t\tSIMULATION SUCCESFUL!\n"
                      << std::endl;
            std::cout << "Press [1] to convert to binary: " << std::endl;
            std::cout << "Press [0] to exit" << std::endl;
            value = false;
        }
        else
        {
            std::cout << "\tCONVERSION SUCCESFUL!\n"
                      << std::endl;
            std::cout << "Press any key to exit:";
            std::cin >> z;
            break;
        }

        std::cin >> z;
        switch (z)
        {
        case 1:
            for (int j = 0; j < row_num; j++)
            {
                for (int i = 0; i < col_num; i++)
                {
                    std::cout << ConvertDecToBin(arr[j][i], prec) << "\t";
                }
                std::cout << "\n";
            }
        case 0:
            break;

        default:
            break;
        }

    } while (z != 0);
}
