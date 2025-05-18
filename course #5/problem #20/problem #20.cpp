// problem #20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharType { smallLetter = 1, capital, special, digit};


int RandomNumber(int from, int to) {

    int randomNum = rand() % (to - from + 1) + from;

    return randomNum;
}

char GetRandomCharacter(enCharType  value) {
    switch (value)
    {
    case smallLetter:
        return char(RandomNumber(97, 122));
        break;
    case capital:
        return char(RandomNumber(65, 90));

        break;
    case special:
        return char(RandomNumber(33, 47));

        break;
    case digit:
        return char(RandomNumber(48, 57));
        break;
    default:
        break;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cout << GetRandomCharacter(enCharType::smallLetter) << endl;
    cout << GetRandomCharacter(enCharType::capital) << endl;
    cout << GetRandomCharacter(enCharType::special) << endl;
    cout << GetRandomCharacter(enCharType ::digit) << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
