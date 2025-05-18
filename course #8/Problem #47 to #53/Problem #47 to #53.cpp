// Problem #47 to #53.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#pragma warning(disable : 4996)
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
bool isLastDay(sDate date) {
    return date.day == DaysInMonth(date.year, date.month);
}
bool isLastMonth(short month) {
    return month == 12;
}
void SwapDates(sDate& date1, sDate& date2) {
    sDate tempDate;
    tempDate.year = date1.year;
    tempDate.month = date1.month;
    tempDate.day = date1.day;

    date1.year = date2.year;
    date1.month = date2.month;
    date1.day = date2.day;

    date2.year = tempDate.year;
    date2.month = tempDate.month;
    date2.day = tempDate.day;

}
sDate AddOneDay(sDate date) {
    if (isLastDay(date)) {
        if (isLastMonth(date.month)) {
            date.day = 1;
            date.month = 1;
            date.year++;
        }
        else {
            date.day = 1;
            date.month++;
        }
    }
    else
        date.day++;

    return date;
}
sDate MinusOneDay(sDate date) {
    if (date.day == 1 && date.month == 1) {
        date.year--;
        date.month = 12;
        date.day = 31;
    }
    else if (date.day == 1 && date.month != 1) {
        date.month--;
        date.day = DaysInMonth(date.year, date.month);
    }
    else {
        date.day--;
    }
    return date;
}
short DateDiff(sDate date1, sDate date2, bool lastDay = false) {
    short days = 1;
    short SwapFlagVal = 1;
    if (!isDate1LessThen2(date1, date2)) {
        SwapDates(date1, date2);
        SwapFlagVal = -1;
    }
    if (date2.year > date1.year) {
        while (date1.year < date2.year) {
            date1.year++;
            days += IsLeapYear(date1.year) ? 366 : 365;
        }
    }

    days += (DaysFromStart(date2.year, date2.month, date2.day) - DaysFromStart(date1.year, date1.month, date1.day));
    return lastDay ? ++days * SwapFlagVal : days * SwapFlagVal;
}
short DateDiff2(sDate date1, sDate date2, bool lastDay = false) {
    short days = 0;
    short SwapFlagVal = 1;
    if (!isDate1LessThen2(date1, date2))
    {
        SwapDates(date1, date2);
        SwapFlagVal = -1;

    }
    while (isDate1LessThen2(date1, date2)) {
        days++;
        date1 = AddOneDay(date1);
    }
    return lastDay ? ++days * SwapFlagVal : days * SwapFlagVal;


}
sDate GetSystemDate() {
    sDate date;
    time_t t = time(0);
    tm* now = localtime(&t);

    date.year = now->tm_year + 1900;
    date.month = now->tm_mon + 1;
    date.day = now->tm_mday;
    return date;
}

sDate IncreaseDateByXDays(sDate date, short numOfDays) {
    for (short i = 0; i < numOfDays; i++) {
        date = AddOneDay(date);
    }
    return date;
}

sDate IncreaseDateByOneWeek(sDate date) {
    for (short i = 0; i < 7; i++) {
        date = AddOneDay(date);
    }
    return date;
}
sDate IncreaseDateByXWeeks(sDate date, short numOfWeeks) {
    for (short i = 0; i < numOfWeeks; i++) {
        date = IncreaseDateByOneWeek(date);
    }
    return date;
}

sDate IncreaseDateByOneMonth(sDate date) {
    date.month++;
    if (date.month == 12) {
        date.month = 1;
        date.year++;
    }

    short maxDaysInMonth = DaysInMonth(date.year, date.month);
    if (date.day > maxDaysInMonth) {
        date.day = maxDaysInMonth;
    }
    return date;

}
sDate IncreaseDateByXMonths(sDate date, short numOfMonths) {
    for (short i = 0; i < numOfMonths; i++) {
        date = IncreaseDateByOneMonth(date);
    }
    return date;
}

sDate IncreaseDateByOneYear(sDate date) {
    date.year++;
    return date;
}
sDate IncreaseDateByXYear(sDate date, short numOfYears) {
    for (short i = 1; i <= numOfYears; i++) {
        date = IncreaseDateByOneYear(date);
    }
    return date;
}


sDate IncreaseDateByXYearFaster(sDate date, short numOfYears) {
    date.year += numOfYears;
    return date;
}

sDate IncreaseDateByOneDecade(sDate date) {
    date.year += 10;
    return date;
}

sDate IncreaseDateByXDecades(sDate date, short numOfDec) {
    for (short i = 1; i <= numOfDec; i++) {
        date = IncreaseDateByOneDecade(date);
    }
    return date;
}

sDate IncreaseDateByXDecadesFaster(sDate date, short numOfDec) {
    date.year += numOfDec * 10;
    return date;
}
sDate IncreaseDateByOneCentury(sDate date) {
    date.year += 100;
    return date;
}

sDate IncreaseDateByOneMillennium(sDate date) {
    date.year += 1000;
    return date;
}




///////////////////////////////////////////////////////////////////////////////
sDate DecreaseDateByXDays(sDate date, short numOfDays) {
    for (short i = 0; i < numOfDays; i++) {
        date = MinusOneDay(date);
    }
    return date;
}

sDate DecreaseDateByOneWeek(sDate date) {
    for (short i = 0; i < 7; i++) {
        date = MinusOneDay(date);
    }
    return date;
}
sDate DecreaseDateByXWeeks(sDate date, short numOfWeeks) {
    for (short i = 0; i < numOfWeeks; i++) {
        date = DecreaseDateByOneWeek(date);
    }
    return date;
}

sDate DecreaseDateByOneMonth(sDate date) {
    if (date.month == 1) {
        date.month = 12;
        date.year--;
    }
    else {
        date.month--;
    }

    short maxDaysInMonth = DaysInMonth(date.year, date.month);
    if (date.day > maxDaysInMonth) {
        date.day = maxDaysInMonth;
    }
    return date;

}
sDate DecreaseDateByXMonths(sDate date, short numOfMonths) {
    for (short i = 0; i < numOfMonths; i++) {
        date = DecreaseDateByOneMonth(date);
    }
    return date;
}

sDate DecreaseDateByOneYear(sDate date) {
    date.year--;
    return date;
}
sDate DecreaseDateByXYear(sDate date, short numOfYears) {
    for (short i = 1; i <= numOfYears; i++) {
        date = DecreaseDateByOneYear(date);
    }
    return date;
}


sDate DecreaseDateByXYearFaster(sDate date, short numOfYears) {
    date.year -= numOfYears;
    return date;
}

sDate DecreaseDateByOneDecade(sDate date) {
    date.year -= 10;
    return date;
}

sDate DecreaseDateByXDecades(sDate date, short numOfDec) {
    for (short i = 1; i <= numOfDec; i++) {
        date = DecreaseDateByOneDecade(date);
    }
    return date;
}

sDate DecreaseDateByXDecadesFaster(sDate date, short numOfDec) {
    date.year -= numOfDec * 10;
    return date;
}
sDate DecreaseDateByOneCentury(sDate date) {
    date.year -= 100;
    return date;
}

sDate DecreaseDateByOneMillennium(sDate date) {
    date.year -= 1000;
    return date;
}


//////////////////////////////////////////////////////////////////

short DayIndex(sDate date) {
    return DayIndex(date.year, date.month, date.day);
}

bool IsEndOfWeek(sDate date) {
    return DayIndex(date) == 6;
}

bool IsWeekEnd(sDate date) {
    return DayIndex(date) == 5 || DayIndex(date) == 6;
}
bool IsBusinessDay(sDate date) {
    return !IsWeekEnd(date);
}

short DaysUntilTheEndOfWeek(sDate date) {
    return 7 - (DayIndex(date) + 1);
}
short DaysUntilTheEndOfMonth(sDate date) {
    return DaysInMonth(date.year, date.month) - date.day;
}

short DaysUntilTheEndOfYear(sDate date) {
    short daysUntilNow = DaysFromStart(date.year, date.month, date.day);
    return IsLeapYear(date.year) ? 366 - daysUntilNow : 365 - daysUntilNow;
}

int main()
{
    sDate date;
    //cout << "Please enter your birth date : \n";
    date = GetSystemDate();
    cout << "Today is " << DayName(DayIndex(date)) << ", " << date.day << "/" <<
        date.month << "/" << date.year << "\n\n";

    cout << "Is it End of Week ? \n";
    if (IsEndOfWeek(date)) {
        cout << "Yea it is, the end of week. \n\n";
    }
    else
        cout << "No it is, not end of week. \n\n";

    cout << "Is it the Weekend ? \n";

    if (IsWeekEnd(date)) {
        cout << "Yea it is, weekend. \n";
    }
    else
        cout << "No it is, NOT weekend. \n\n";

    cout << "Is it a Business day ? \n";

    if (IsBusinessDay(date)) {
        cout << "Yea it is, Business day. \n\n";
    }
    else
        cout << "No it is, NOT a business day. \n\n";


    cout << "Days until end of Week : " << DaysUntilTheEndOfWeek(date) << " Day(s).\n";
    cout << "Days until end of Month : " << DaysUntilTheEndOfMonth(date) << " Day(s).\n";
    cout << "Days until end of Year : " << DaysUntilTheEndOfYear(date) << " Year(s).\n";

    //date = FillDate();

    //cout << "Date After : \n\n";
    //date = MinusOneDay(date);
    //cout << "01-Decreasing one day is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByXDays(date, 10);
    //cout << "02-Decreasing 10 days is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByOneWeek(date);
    //cout << "03-Decreasing one week is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByXWeeks(date, 10);
    //cout << "04-Decreasing 10 weeks is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByOneMonth(date);
    //cout << "05-Decreasing one month is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByXMonths(date, 5);
    //cout << "06-Decreasing 5 Months is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByOneYear(date);
    //cout << "07-Decreasing one year is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByXYear(date, 10);
    //cout << "08-Decreasing 10 years is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByXYearFaster(date, 10);
    //cout << "09-Decreasing 10 years faster is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByOneDecade(date);
    //cout << "10-Decreasing one Decade is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByXDecades(date, 10);
    //cout << "11-Decreasing 10 Decades is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByXDecadesFaster(date, 10);
    //cout << "12-Decreasing 10 Decades faster is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByOneCentury(date);
    //cout << "13-Decreasing one Century is: " << date.day << "/" << date.month << "/" << date.year << endl;
    //date = DecreaseDateByOneMillennium(date);
    //cout << "14-Decreasing one Millennium is: " << date.day << "/" << date.month << "/" << date.year << endl;


    //date2 = FillDate();

    //cout << "Your Age is = " << DateDiff2(date1, GetSystemDate(), true) << " day" << endl;
    //cout << "The Diffrence with last day = " << DateDiff(date1, date2, true) << endl;
    //cout << "The Diffrence with last day = " << DateDiff2(date1, date2, true) << endl;

    return 0;
}
