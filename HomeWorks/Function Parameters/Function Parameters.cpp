// Function Parameters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


float Pi = 3.14;

// #1

void printN() {
    cout << "Alshrif Suhaim" << endl;
}

// #2
void printName(string name) {
    cout << "Hello " << name << endl;
}


// #14

void swapNum(int &num1, int &num2 ) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// #15 
int  RectangleArea(int a, int b) {
    return a * b;
}

float RectangleAreaThroughDiagonal(int a, int d)
{
    return a * sqrt(pow(d, 2) - pow(a, 2));
}

// #18
float CircleArea(int r) {
    return Pi * pow(r, 2);
}
//# 19
float CircleAreaWithD(int D) {

    return (Pi * pow(D, 2)) / 4;
}

// #21
float  CircleAreaByL(float l) {
    return pow(l, 2) / (4 * Pi);
}

// #22
float CircleAreaInTriangle( float a, float b) {

    return Pi * (pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
}

// # 23

float  CircleAreaInArbitraryTriangle(float a, float b, float c) {
    float P = (a + b + c) / 2;
    float d = (a * b * c) / (4 * sqrt(P * (P - a) * (P - b) * (P - c)));
    return Pi * pow(d, 2);
}

// # 31 
void pows(int num) {
    cout << "result is: \n" << endl;
    cout << pow(num, 2) << endl;
    cout << pow(num, 3) << endl;
    cout << pow(num, 4) << endl;

}
int toSec(int days, int hours, int min, int sec) {

    int result = (days * 24 * 60 * 60) + (hours * 60 * 60) + (min * 60) + sec;
    return result;
}

void fromSeconds(int sec) {

    int remainOfSeconds = sec % 60;
    int minutes = (sec- remainOfSeconds) / 60, remainOfMin = minutes % 60;
    int hours = (minutes - remainOfMin) / 60, remainOfHours = hours % 24;
    unsigned short days = (hours - remainOfHours) / 24;

    cout << "Result is = " << round(days) << ":" << round(remainOfHours) << ":" << round(remainOfMin) << ":"
        << round(remainOfSeconds) << endl;
}

void test(int &num) {
    num = 50;
    
}

int main() 
{
  /*  printN();
    string name;
    cout << "Enter your name ?" << endl;
    getline(cin, name);
    printName(name);*/

    //int num1, num2;
    //cout << "enter the first number?" << endl;
    //cin >> num1;
   /* cout << "enter the second number ?" << endl;
    cin >> num2;*/

    // #14 
   /* cout << "result : \n" << endl;
    cout << num1 << endl;
    cout << num2 << endl;

    swapNum(num1, num2);
    cout << num1 << endl;
    cout << num2 << endl;*/

    // #15 
    //cout << "The Area = " << RectangleArea(num1, num2) << endl;

    // #16
    //cout << "The Area = " << RectangleAreaThroughDiagonal(num1, num2) << endl;

   // #18
   /* int c;
    cout << "Enter the c?" << endl;
    cin >> c;*/
   // cout << "The Area = " << CircleArea(r) << endl;

   // #19
    //cout << "The Area = " << CircleAreaWithD(r) << endl;
    
    
    // #21 
    //cout << "The Area = " << CircleAreaByL(float(r)) << endl;

    // #22
    //cout << "The Area = " << CircleAreaInTriangle(float(num1), float(num2)) << endl;

    //# 23 
    //cout << "The Area = " << CircleAreaInArbitraryTriangle(float(num1), float(num2), float(c)) << endl;

    // #31

    //pows(num1);
    
    // #42
   /* short days, hours, minutes, seconds;

    cout << "Calculate Task Duration In Seconds, enter days :" << endl;
    cin >> days;
    cout << "hours :" << endl;
    cin >> hours;
    cout << "mintues :" << endl;
    cin >> minutes;
    cout << "seconds :" << endl;
    cin >> seconds;

    int secs = toSec(days, hours, minutes, seconds);
    cout << "Result: " << secs << endl;*/

    //#43
    /*int seconds;
    cout << "program to take seconds and turn it into days, hours, minutes, seconds \n"
        << "enter the seconds : " << endl;
    cin >> seconds;
    fromSeconds(seconds);*/
     int Pi = 11;
     cout << &Pi << endl;
     cout << Pi << endl;

     test(Pi);
     cout << Pi << endl;

}
