// Date Library Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;


int main()
{
    clsDate date1;
    date1.Print();

    clsDate date2("31/1/2022");
    date2.Print();

    clsDate date3(20, 12, 2022);
    date3.Print();

    clsDate date4(250, 2022);
    date4.Print();

    date4.PrintYearCalender();


}
