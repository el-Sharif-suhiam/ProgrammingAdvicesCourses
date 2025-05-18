// Problem #14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct sDate {
    short year;
    short month;
    short day;
};

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
        if (++i == 7) {
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

short DaysFromStart(short year, short month, short day) {
    short days = 0;
    for (short i = 1; i <= (month - 1); i++) {
        days += DaysInMonth(year, i);
    }

    days += day;

    return days;
}

sDate FillDate() {
    sDate date;
    date.year = ReadNum("Enter the Year : ");
    date.month = ReadNum("Enter the month : ");
    date.day = ReadNum("Enter the day : ");
    return date;
}
sDate DaysToDate(short days, short year) {
    sDate date;
    date.month = 1, date.day = days;
    while (DaysInMonth(year, date.month) < date.day) {
        date.day -= DaysInMonth(year, date.month);
        date.month++;
    };
    date.year = year;
    return date;
}

sDate AddedDaysToDate(short days, sDate& date) {
    short remainingDays = days + DaysFromStart(date.year, date.month, date.day);
    date.month = 1;
    short daysOfMon = 0;
    while (true) {
        daysOfMon = DaysInMonth(date.year, date.month);
        if (remainingDays > daysOfMon) {
            remainingDays -= daysOfMon;
            date.month++;
            if (date.month > 12) {
                date.year++;
                date.month = 1;
            }
        }
        else {
            date.day = remainingDays;
            break;
        }

    }
    return date;

}
bool isDate1LessThen2(sDate date1, sDate date2) {
    /* return date1.year < date2.year ? true : (date1.year == date2.year ?
         date1.month < date2.month ? true : (date1.month == date2.month ?
         date1.day < date2.day : false) : false);*/

         // best optimized code
    if (date1.year < date2.year) {
        return true;
    }
    else if (date1.year == date2.year) {
        if (date1.month < date2.month) {
            return true;
        }
        else if (date1.month == date2.month) {
            return date1.day < date2.day;
        }
    }
    return false;
    /*if (date1.year < date2.year) {
        return true;
    }
    else if (date1.year == date2.year) {
        return DaysFromStart(date1.year, date1.month, date1.day) < DaysFromStart(date2.year, date2.month, date2.day);
    }
    return false;*/
}
bool isDate1EqualDate2(sDate date1, sDate date2) {
    return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
}
int main()
{
    sDate date1, date2;
    date1 = FillDate();
    cout << "Now Enter date 2 : \n\n";
    date2 = FillDate();
    if (isDate1EqualDate2(date1, date2)) {
        cout << "\nYes Date1 is Equal date2 \n";
    }
    else {
        cout << "\nNo it's not equal..\n";
    }

    return 0;
}
