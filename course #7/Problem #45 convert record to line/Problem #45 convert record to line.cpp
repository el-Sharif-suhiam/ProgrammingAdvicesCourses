// Problem #45 convert record to line.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct sClient {
    string accountNumber;
    string PinCode;
    string name;
    string phone;
    double accountBalance;
};

sClient ReadClientData() {
    sClient data;
    cout << "Enter Account Number: ";
    getline(cin, data.accountNumber);
    cout << "Enter Pin Code: ";
    getline(cin, data.PinCode);
    cout << "Enter Name: ";
    getline(cin, data.name);
    cout << "Enter Phone Number: ";
    getline(cin, data.phone);
    cout << "Enter Account Balance: ";
    cin >> data.accountBalance;

    return data;
}

string RecordToLine(sClient data, string sprt) {
    string line = "";
    line += data.accountNumber + sprt;
    line += data.PinCode + sprt;
    line += data.name + sprt;
    line += data.phone + sprt;
    line += to_string(data.accountBalance) + sprt;

    return line;

}
int main()
{
    cout << RecordToLine(ReadClientData(), "#//#") << endl;
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
