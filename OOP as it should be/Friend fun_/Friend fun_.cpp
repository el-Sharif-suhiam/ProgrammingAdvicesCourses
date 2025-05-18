// Friend fun_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Interface {
    virtual void Test() = 0;
    virtual void Nothing() = 0;
};


class First {
private:
    int _a;
    int _b;
    string _name;
    struct Name1 {
        string firstName;
        string lastName;
        short age;
    };
public :
    Name1 name;
    First() {
        _a = 20;
        _b = 30;
        _name = "LOQ";
        name.age = 28;
        name.firstName = "Alsharif";
        name.lastName = "Suhaim";
    }


    friend class Second;
    friend void GoodMan(First f);
};


class Second {
public:
    void show(First f ) {
        cout << " what inside First is : " << f._a << " ," << f._b << " and " << f._name << endl;
        cout << f.name.firstName << " " << f.name.lastName;
    }
};

void GoodMan(First f) {
    cout << "i can get into First class as i want: " << f._a + f._b << " " << f._name << endl;
}
int main()
{
    
    First f;
    Second S;

    S.show(f);

    cout << "\n\n";

    GoodMan(f);
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
