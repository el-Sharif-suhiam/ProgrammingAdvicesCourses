


#include <iostream>
#include <string>
using namespace std;


void printLetters() {
    for (short i = 65; i <= 90; i++) {
        for (short j = 65; j <= 90; j++) {
            cout << char(i) << char(j) << endl;
        }
    }
}
// correct

void starsDes() {
    for (short i = 10; i >= 1; i--) {
        for (short j = i; j >= 1; j--) {
            cout << "*";
        }
        cout << endl;
    }
}

// correct

void NumsDes() {
    for (short i = 10; i >= 1; i--) {
        for (short j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// correct

void NumsAsc() {
    for (short i = 1; i <= 10; i++) {
        for (short j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void LettersAsc() {
    for (short i = 65; i <= 70; i++) {
        for (short j = 65; j <= i; j++) {
            cout << char(j) << " ";
        }
        cout << endl;
    }
}
//corrct

void lastOne() {
    for (short i = 1; i <= 10; i++) {
        for (short j = i; j <= 10; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{
    

    //printLetters();
    //starsDes();
    //NumsDes();
    //NumsAsc();
    //LettersAsc();
    lastOne();
}
