#include "../include/data_read.h"

class Imu_sim
{
private:
    double randomAcc()
    {
        return ((std::rand() % (20000 - 10000) + 1) / 10000.0);
    }
    double randomGyro()
    {
        return (std::rand() % (70000 - (-50000) + 1) + (-15000)) / 1000.0;
    }

public:
    Imu_sim()
    {
        std::srand(std::time(NULL));
    }

    void acc(double &aX, double &aY, double &aZ)
    {
        aX = randomAcc();
        aY = randomAcc();
        aZ = randomAcc();
    }

    void gyro(double &gX, double &gY, double &gZ)
    {
        gX = randomGyro();
        gY = randomGyro();
        gZ = randomGyro();
    }
};

int simulationTime()
{
    int a;
    std::cout << "Enter wanted simulation time: ";
    std::cin >> a;
    if (a < 0)
    {
        a = a * (-1);
    }
    return a;
}

void simulation_process()
{
    Imu_sim imu;

    int k = 0;
    int z;
    bool value = true;
    const int prec = 10;
    double aX, aY, aZ;
    double gX, gY, gZ;

    int t = simulationTime();
    const int sampleAmount = t * HZ;
    const int col_num = 6;

    double **arrS;
    arrS = new double *[sampleAmount];

    for (int i = 0; i < sampleAmount; i++)
    {
        arrS[i] = new double[col_num];
    }

    double **arrData;
    arrData = new double *[col_num];
    for (int i = 0; i < col_num; i++)
    {
        arrData[i] = new double[col_num];
    }

    for (int j = 0; j < sampleAmount; j++)
    {
        imu.acc(aX, aY, aZ);
        imu.gyro(gX, gY, gZ);
        k = 0;

        for (int i = 0; i < col_num; i++)
        {

            switch (i)
            {
            case 0:
                arrData[k][i] = aX;
                arrS[j][i] = arrData[k][i];
                k++;
                break;
            case 1:
                arrData[k][i] = aY;
                arrS[j][i] = arrData[k][i];
                k++;
                break;
            case 2:
                arrData[k][i] = aZ;
                arrS[j][i] = arrData[k][i];
                k++;
                break;
            case 3:
                arrData[k][i] = gX;
                arrS[j][i] = arrData[k][i];
                k++;
                break;
            case 4:
                arrData[k][i] = gY;
                arrS[j][i] = arrData[k][i];
                k++;
                break;
            case 5:
                arrData[k][i] = gZ;
                arrS[j][i] = arrData[k][i];
                k++;
                break;
            }
            std::cout << arrS[j][i] << "\t";
        }
        k = 0;
        std::cout << "row num: " << j << "\n";
    }

    do
    {
        if (value == true)
        {
            std::cout << "\t\tSIMULATION SUCCESFUL!\n"
                      << std::endl;
            std::cout << "Press [1] to convert to binary: " << std::endl;
            std::cout << "Press [0] to return to menu" << std::endl;
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
            for (int j = 0; j < sampleAmount; j++)
            {
                for (int i = 0; i < col_num; i++)
                {
                    std::cout << ConvertDecToBin(arrS[j][i], prec) << "\t";
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
