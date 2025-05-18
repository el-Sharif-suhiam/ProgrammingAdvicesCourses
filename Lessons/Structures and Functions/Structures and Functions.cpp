// Structures and Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;


struct stInfo {
    string FName;
    string LName;
    short Age;
    unsigned long long Phone;
};

void ReadInfo(stInfo &info) {
    cout << "Enter your first name ?\n";
    cin >> info.FName;
    cout << "Enter your last name ?\n";
    cin >> info.LName;
    cout << "Enter your Age ?\n";
    cin >> info.Age;
    cout << "Enter your Phone number ?\n";
    cin >> info.Phone;

}

void ShowInfo(stInfo info) {
    cout << "****************************" << endl;
    cout << "Your First Name is: " << info.FName << endl;
    cout << "Your Last Name is: " << info.LName << endl;
    cout << "Your Age is: " << info.Age << endl;
    cout << "Your Phone number is: " << info.Phone << endl;
    cout << "****************************" << endl;


}
int main()
{
    stInfo user1;
    ReadInfo(user1);
    ShowInfo(user1);

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
