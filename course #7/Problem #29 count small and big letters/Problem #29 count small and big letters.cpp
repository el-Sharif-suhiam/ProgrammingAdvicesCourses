// Problem #29 count small and big letters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


enum enWhatToCount { lowerLetter = 0, upperLetter = 1 };

short CountLetters(string msg, enWhatToCount whatToCount) {
    short counter = 0;
    for (short i = 0; i < msg.length(); i++) {
        if (whatToCount == enWhatToCount::lowerLetter && islower(msg[i]))
            counter++;
        if (whatToCount == enWhatToCount::upperLetter && isupper(msg[i]))
            counter++;
    }
    return counter;
}
string ReadMsg() {
    string msg;
    cout << "Enter you sentence : \n";
    getline(cin, msg);

    return msg;
}

short countSmallLetters(string msg) {
    short Counter = 0;
    for (short i = 0; i < msg.length(); i++) {
        if (islower(msg[i])) {
            Counter++;
        }
    }
    return  Counter;
}


short countUpperLetters(string msg) {
    short Counter = 0;
    for (short i = 0; i < msg.length(); i++) {
        if (isupper(msg[i])) {
            Counter++;
        }
    }
    return  Counter;
}

int main()
{
    string msg = ReadMsg();
    cout << "Total Count is: " << msg.length() << "\n";
    cout << "Upper Letters Count is: " << CountLetters(msg, enWhatToCount::upperLetter) << "\n";
    cout << "Lower Letters Count is: " << CountLetters(msg, enWhatToCount::lowerLetter) << "\n";



    return 0;
}
