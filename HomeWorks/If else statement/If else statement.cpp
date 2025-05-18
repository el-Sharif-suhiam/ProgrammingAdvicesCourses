

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct stUser {
    short age;
    bool hasDriverLicense;
    short mark;
};

void ReadUserInfo(stUser &user) {
    string temp;
    cout << "please enter your age ?" << endl;
    cin >> user.age;
    cout << "Do you have a driver license (yes, no) ?" << endl;
    cin >> temp;
    if (temp == "yes" || temp == "Yes") {
        user.hasDriverLicense = 1;
    }
    else {
        user.hasDriverLicense = 0;
    };
}

void checkUser(stUser user) {
    if (user.age > 21 && user.hasDriverLicense == true) {
        cout << "\nHired\n";
    }
    else {
        cout << "Rejected; \n";
    }
}

void readUserMark(stUser &user) {
    cout << "please enter your mark ?\n";
    cin >> user.mark;
}
void checkMark(short mark) {
    cout << endl;
    if (mark >= 50) {
        cout << mark;
        cout << "\nPASS";
    }
    else {
        cout << mark;
        cout << "\nFail";
    }
}
short getAvg() {
    short n1, n2, n3;
    cout << "enter the mark number 1 ?\n";
    cin >> n1;
    cout << "enter the mark number 2 ?\n";
    cin >> n2;
    cout << "enter the mark number 3 ?\n";
    cin >> n3;

    return (n1 + n2 + n3) / 3;
}
void readAge(stUser& user) {
    cout << "enter your age ?\n";
    cin >> user.age;
}
void checkAge(short age) {
    if (age > 18 && age < 45) {
        cout << "\nVaild Age" << endl;
    }
    else {
        cout << "\nInvaild Age" << endl;
     }
}
short getPin() {
    short userPin;
    cout << "enter your pin code : " << endl;
    cin >> userPin;
    return userPin;
}

void getGrade() {
    short grade;
    cout << "enter your grade : \n";
    cin >> grade;

    if (grade <= 100 && grade >= 90) {
        cout << "A" << endl;
    }
    else if (grade <= 89 && grade >= 80) {
        cout << "B" << endl;

    }
    else if (grade <= 79 && grade >= 70) {
        cout << "C" << endl;

    }
    else if (grade <= 69 && grade >= 60) {
        cout << "D" << endl;

    }
    else if (grade <= 59 && grade >= 50) {
        cout << "E" << endl;

    }
    else {
        cout << "F" << endl;

    }
  
}

void Commission() {
    int totalSales;
    cout << "enter your sales : \n";
    cin >> totalSales;

    if (totalSales > 1000000 ) {
        cout << totalSales * 0.1 << endl;
    }
    else if (totalSales <= 1000000 && totalSales > 500000) {
        cout << totalSales * 0.2 << endl;

    }
    else if (totalSales <= 500000 && totalSales > 100000) {
        cout << totalSales * 0.3 << endl;

    }
    else if (totalSales <= 100000 && totalSales > 50000) {
        cout << totalSales * 0.5 << endl;

    }
    else {
        cout << totalSales * 0 << endl;

    }
}
void SimpleCalc() {
    short num1, num2; 
    char op;
    cout << "enter the first num: \n";
    cin >> num1;
    cout << "enter the second num: \n";
    cin >> num2;
    cout << "enter the the Operation (+,-,*,/): \n";
    cin >> op;

    if (op == '+' ) {
        cout << num1 + num2 << endl;
    }
    else if (op == '-') {
        cout << num1 - num2 << endl;
    }
    else if (op == '*') {
        cout << num1 * num2 << endl;

    }
    else if (op == '/') {
        cout << num1 / num2 << endl;

    }
    else {
        cout << "wrong operation;" << endl;
    }
}

void dayOfwork() {
    short day;
    cout << "please enter the day: \n";
    cin >> day;
    if (day == 1) {
        cout << "Sunday" << endl;
    }
    else if (day == 2) {
        cout << "Monday" << endl;
    }
    else if (day == 3) {
        cout << "Tuesday" << endl;

    }
    else if (day == 4) {
        cout << "Wednesday" << endl;

    }
    else if (day == 5) {
        cout << "Thursday" << endl;

    }
    else if (day == 6) {
        cout << "Friday" << endl;

    }
    else if (day == 7) {
        cout << "Saturday" << endl;

    }
    else {
        cout << "Wrong Day" << endl;
    }

}




void theMonth() {
    short month;
    cout << "please enter the Month: \n";
    cin >> month;
    if (month == 1) {
        cout << "January" << endl;
    }
    else if (month == 2) {
        cout << "February" << endl;
    }
    else if (month == 3) {
        cout << "March" << endl;

    }
    else if (month == 4) {
        cout << "April" << endl;

    }
    else if (month == 5) {
        cout << "May" << endl;

    }
    else if (month == 6) {
        cout << "June" << endl;

    }
    else if (month == 7) {
        cout << "July" << endl;

    }
    else if (month == 8) {
        cout << "Auguest" << endl;

    }
    else if (month == 9) {
        cout << "September" << endl;

    }
    else if (month == 10) {
        cout << "Octuber" << endl;

    }
    else if (month == 11) {
        cout << "November" << endl;

    }
    else if (month == 12) {
        cout << "December" << endl;

    }
    else {
        cout << "Wrong Month" << endl;
    }

}
int main()
{
    // #4
    stUser user;
    short pin = 1234, balance = 7500;
    
    //ReadUserInfo(user);
    //checkUser(user);
    // #8
    //readUserMark(user);

    //#11
    //checkMark(getAvg());

    //#24
    //readAge(user);
    //checkAge(user.age);
    
    // #49
   /* if (getPin() == pin) {
        cout << "Your Balance is: " << balance << endl;
    }
    else {
        cout << "Wrong Pin";
    }*/
   

    //// else if home work

    // #33
    //getGrade();
    // #34
    //Commission();
    // #36
    //SimpleCalc();

    // #44
    //dayOfwork();

    // #45
    theMonth();
}   
