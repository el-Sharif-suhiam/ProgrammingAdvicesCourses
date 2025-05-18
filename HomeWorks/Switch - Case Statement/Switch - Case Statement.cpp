
#include <iostream>
using namespace std;

enum enDays { sunday = 1, monday,tuesday,wednesday,thursday,friday,saturday};
enum enMonths { junuary = 1, february, march, april,may,june ,july,auguest,september,octuber,november,december};
// #36
void SimpleCalc() {
    short num1, num2;
    char op;
    cout << "enter the first num: \n";
    cin >> num1;
    cout << "enter the second num: \n";
    cin >> num2;
    cout << "enter the the Operation (+,-,*,/): \n";
    cin >> op;

    switch (op) {
    case '+':
        cout << num1 + num2 << endl;

        break;
    case '-':
        cout << num1 - num2 << endl;

        break;
    case '*':
        cout << num1 * num2 << endl;

        break;
    case '/':
        cout << num1 / num2 << endl;

        break;

    default: 
        cout << "wrong operation;" << endl;

        break;

    }
}

//# 44
void dayOfwork() {
    short userInput;
    enDays day;
    cout << "please enter the day: \n";
    cin >> userInput;

    day = (enDays)userInput;

    switch (day)
    {
    case sunday:
        cout << "Sunday" << endl;
        break;
    case monday:
        cout << "Monday" << endl;

        break;
    case tuesday:
        cout << "Tuesday" << endl;

        break;
    case wednesday:
        cout << "Wednesday" << endl;

        break;
    case thursday:
        cout << "Thursday" << endl;

        break;
    case friday:
        cout << "Friday" << endl;

        break;
    case saturday:
        cout << "Saturday" << endl;

        break;
    default:
        cout << "Wrong Day" << endl;

        break;
    }

}

// #45


void theMonth() {
    short userInput;
    enMonths month;
    cout << "please enter the Month: \n";
    cin >> userInput;

    month = (enMonths)userInput;

    switch (month)
    {
    case junuary:  
        cout << "January" << endl;
        break;
    case february:
        cout << "february" << endl;
        break;
    case march:
        cout << "march" << endl;
        break;
    case april:
        cout << "april" << endl;
        break;
    case may:
        cout << "may" << endl;
        break;
    case june:
        cout << "june" << endl;
        break;
    case july:
        cout << "july" << endl;
        break;
    case auguest:
        cout << "auguest" << endl;
        break;
    case september:
        cout << "september" << endl;
        break;
    case octuber:
        cout << "octuber" << endl;
        break;
    case november:
        cout << "november" << endl;
        break;
    case december:
        cout << "december" << endl;
        break;
    default:
        cout << "Wrong Month" << endl;

        break;
    }

}
int main()
{
    //SimpleCalc();

    //dayOfwork();
    theMonth();
}
