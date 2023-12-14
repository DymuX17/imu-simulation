#ifndef DATA_READ_H
#define DATA_READ_H

#endif

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>
#include <bits/stdc++.h>

#define HZ 50

void read();

void convert();

std::string ConvertDecToBin(double num, int prec);

class Imu_sim;

int simulationTime();

void simulation_process();