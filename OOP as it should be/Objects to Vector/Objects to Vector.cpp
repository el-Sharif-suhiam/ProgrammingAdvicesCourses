// Objects to Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class clsTest {
private:
    int _num;
public:
    clsTest() {};
    clsTest(int num) {
        _num = num;
    }

    void PrintValue() {
        cout << "the value of = " << _num << endl;
    }
};


int main()
{
    //vector<clsTest> v;
    const int maxNum = 3000000;
    clsTest* classArr = new clsTest[maxNum];
    //clsTest classA[maxNum];
    for (int i = 0; i < maxNum; i++) {
        //v.push_back(clsTest(i));
        classArr[i] = clsTest(i + 1);
        //classA[i] = clsTest(i + 1);

    }

    for (int i = 0; i < maxNum; i++) {
        //v[i].PrintValue();
        classArr[i].PrintValue();
        //classA[i].PrintValue();
    }

    system("pause > 0");
    return 0;
}
