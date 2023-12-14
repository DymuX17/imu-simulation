#include "../include/data_read.h"

std::string ConvertDecToBin(double num, int prec)
{
    std::string bin = "";

    int Integral = num;

    double fract = num - Integral;
    while (Integral)
    {
        int rem = Integral % 2;

        bin.push_back(rem + '0');

        Integral /= 2;
    }

    reverse(bin.begin(), bin.end());

    bin.push_back('.');

    while (prec--)
    {
        fract *= 2;
        int fract_bit = fract;

        if (fract_bit == 1)
        {
            fract -= fract_bit;
            bin.push_back(1 + '0');
        }
        else
            bin.push_back(0 + '0');
    }

    return bin;
}