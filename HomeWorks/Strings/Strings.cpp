
#include <iostream>
#include <string>
using namespace std;


int main()
{
    string st1, st2, st3;
    cout << "Please enter String1?" << endl;
    getline(cin, st1);
    cout << "\nPlease Enter String2? " << endl;
    cin >> st2;
    cout << "\nPlease Enter String3?" << endl;
    cin >> st3;

    cout << "**************************" << endl;
    cout << "The Length of String is: " << st1.length() << endl;
    cout << "Charecters of 0,2,4,7 are: " << st1[0] << " " << st1[2] << " " << st1[4]
        << " " << st1[7] << endl;
    cout << "Concatenating String2 and String3 = " << (st2 + st3) << endl;
    cout << st2 << " * " << st3 << " = " << (stoi(st2) * stoi(st3)) << endl;
}
