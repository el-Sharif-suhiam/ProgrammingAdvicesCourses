// Problem #8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;


short ReadNum(string msg) {
    short num;
    do {
        cout << msg;
        cin >> num;
    } while (num > 3000);
    return num;
}

bool IsLeapYear(short Year) {
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}


short DayIndex(short year, short month, short day) {
    short a = (14 - month) / 12;
    int y = year - a;
    int m = month + (12 * a) - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayName(short index) {
    string days[7] = { "sun","mon","tue","wed","thu","fri","sat" };
    return days[index];
}

void DataFormat(short day, short month, short year) {
    cout << day << "/" << month << "/" << year << endl;
}
short DaysInMonth(short year, short month) {
    if (1 > month || month > 12) {
        return 0;
    }

    short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return month == 2 ? (IsLeapYear(year) ? 29 : 28) : arr[month - 1];

}
short HoursInMonth(short year, short month) {
    return DaysInMonth(year, month) * 24;
}
int MinInMonth(short year, short month) {
    return HoursInMonth(year, month) * 60;
}
int SecInMonth(short year, short month) {
    return MinInMonth(year, month) * 60;
}
string MonthName(short month) {
    const string months[13] = {
      "", "Jan", "Feb", "Mar", "Apr",
      "May", "Jun", "Jul", "Aug",
      "Sep", "Oct", "Nov", "Dec"
    };
    return months[month];
}

void PrintCalander(short month, short year) {
    short dayindex = DayIndex(year, month, 1);
    short NumOfDays = DaysInMonth(year, month);
    printf("  _______________ %s _______________\n\n", MonthName(month).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    short i;
    for (i = 0; i < dayindex; i++)
        printf("     ");

    for (short j = 1; j <= NumOfDays; j++) {
        printf("%5d", j);
        if (++i == 7 ) {
            printf("\n");
            i = 0;
        }

    }
    printf("\n\n  __________________________________\n\n");
    //cout << "  ------------" << months[month] << "--------------\n" << endl;
    /*
    cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat  " << endl;
    cout << setw(5 * dayindex) << "";

    for (short day = 1; day <= NumOfDays; day++) {
        cout << setw(5) << day;
        if (( dayindex + day) % 7 == 0) {
            cout << endl;
        }
    }
    cout << "\n\n  ------------------------------------\n\n";*/
}

void AllYearCalender(short year) {
    for (short month = 1; month <= 12; month++) {
        cout << endl;
        PrintCalander(month, year);
    }
}
int main()
{
    short year = ReadNum("Enter the Year : ");
    //short month = ReadNum("Enter the month : ");
    //PrintCalander(month, year);
    AllYearCalender(year);
    //cout << DayIndex(2025, 5, 1);
    //cout << DayName(DayIndex(2025, 5, 1));
    //short day = ReadNum("Enter the day : ");
    //short index = DayIndex(year, month, day);
    //DataFormat(day, month, year);
    //cout << "day index = " << index << endl;
    //cout << "day name = " << DayName(index) << endl;

    //cout << "\nNumber of Days    in month [" << month << "] is : " << DaysInMonth(year, month) << endl;
    //cout << "Number of Hours   in month [" << month << "] is : " << HoursInMonth(year, month) << endl;
    //cout << "Number of Minutes in month [" << month << "] is : " << MinInMonth(year, month) << endl;
    //cout << "Number of Seconds in month [" << month << "] is : " << SecInMonth(year, month) << endl;

    return 0;
}
