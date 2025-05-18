// Destructors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class clsPerson {
private:
    string _Name;
    short _Age;
    char _Gender;
    static short counter;
public:
    clsPerson() {
        cout << "Hello from constructor \n";
        _Name = "Al";
        _Age = 28;
        _Gender = 'M';
        counter++;
    }
 /*   clsPerson(string name, short age,char gender) {
        cout << "Hello from constructor \n";
        _Name = name;
        _Age = age;
        _Gender = gender;
    }*/
    clsPerson(clsPerson& oldPerson) {
        _Name = oldPerson._Name;
        _Age = oldPerson._Age;
        _Gender = oldPerson._Gender;

    }

    ~clsPerson() {
        cout << "Hello form Destructor im deleting now!! \n";
    }

    string Name() {
        return _Name;
    }
    short Age() {
        return _Age;
    };
    char Gender() {
        return _Gender;
    }

    void PrintCounter() {
        cout << "counter is : " << counter << endl;
    }
};

short clsPerson::counter = 0;
void test1() {
//clsPerson person1("Alshrif", 27, 'M');
    //cout << person1.Name() << endl;
    clsPerson* person2 = new clsPerson;
    cout << "adress of ptr is : " << person2 << endl;
    delete person2;

}

int main()
{
    clsPerson p1, p2, p3, p4;

    p1.PrintCounter();
    p2.PrintCounter();
    //test1();
    return 1;
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
