// Nested classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include "clsPerson.h"
using namespace std;

int main()

{
    clsPerson Person1("Alsharif Suhaim", "100 st", "3rd place", "Ojla","libya");

    Person1.Address.Print();

    system("pause>0");
    return 0;
}