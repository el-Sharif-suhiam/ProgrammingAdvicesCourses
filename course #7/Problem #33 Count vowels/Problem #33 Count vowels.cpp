// Problem #33 Count vowels.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


string ReadMsg() {
    string msg;
    cout << "Enter you sentence : \n";
    getline(cin, msg);

    return msg;
}
char ReadLetter() {
    char letter;
    cout << "Enter your letter : \n";
    cin >> letter;

    return letter;
}

bool isVowle(char letter) {
    letter = tolower(letter);
    return (letter == 'a' || letter == 'e' || letter == 'o' || letter == 'i' || letter == 'u');
}
short countVowels(string msg) {
    short Counter = 0;
    for (short i = 0; i < msg.length(); i++) {
        if (isVowle(msg[i])){
            Counter++;
        }
    }
    return  Counter;
}


int main()
{
    string msg = ReadMsg();
    //char letter = ReadLetter();
    
    cout << "\nNumber of vowels is: " << countVowels(msg) << endl;

    return 0;
}
