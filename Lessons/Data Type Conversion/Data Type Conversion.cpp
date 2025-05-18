// Data Type Conversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int Num1;
    double Num2 = 18.99;

    //Num1 = round(Num2);
    Num1 = (int)round(Num2);
    //Num1 = int(Num2);
    cout << Num1 << endl;

    // homework
    string st1 = "43.22";
    int N1 = 20;
    double N2 = 33.5;
    float N3 = 55.23;

    cout << "st conversion: " << stod(st1) << " " << stof(st1) << " "
        << stoi(st1) << endl;
    cout << "N1 conversion: " << to_string(N1) << endl;
    cout << "N2 conversion: " << to_string(N2) << endl;
    cout << "N3 conversion: " << to_string(N3) << " " << int(N3) << endl;



}
