#pragma once
#pragma warning(disable : 4996)
#include <ctime>
#include <iostream>
#include <string>
#include "clsString.h"
using namespace std;

class clsDate
{
	short year;
	short month;
	short day;

	void AddOneDay() {
		if (IsLastDay()) {
			if (isLastMonth(this->month)) {
				day = 1;
				month = 1;
				year++;
			}
			else {
				day = 1;
				month++;
			}
		}
		else
			day++;
	};
	void MinusOneDay() {
		if (day == 1 && month == 1) {
			year--;
			month = 12;
			day = 31;
		}
		else if (day == 1 && month != 1) {
			month--;
			day = DaysInMonth(year, month);
		}
		else {
			day--;
		}
	};

	 static bool IsLeapYear(short Year) {
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	};

	 static short DayIndex(short year, short month, short day) {
		short a = (14 - month) / 12;
		int y = year - a;
		int m = month + (12 * a) - 2;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	};

	 static short DayIndex(clsDate date) {
		 return DayIndex(date.year, date.month, date.day);
	 }
	 static bool isLastMonth(short &month) {
		 return month == 12;
	 }
	 string DayName(short index) {
		string days[7] = { "sun","mon","tue","wed","thu","fri","sat" };
		return days[index];
	}

	 void DataFormat(short day, short month, short year) {
		cout << day << "/" << month << "/" << year << endl;
	};

	 static short DaysInMonth(short year, short month) {
		if (1 > month || month > 12) {
			return 0;
		}

		short arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return month == 2 ? (IsLeapYear(year) ? 29 : 28) : arr[month - 1];

	};

	static string MonthName(short month) {
		const string months[13] = {
		  "", "Jan", "Feb", "Mar", "Apr",
		  "May", "Jun", "Jul", "Aug",
		  "Sep", "Oct", "Nov", "Dec"
		};
		return months[month];
	};


	 static short DaysFromStart(short year, short month, short day) {
		 short days = 0;
		 for (short i = 1; i <= (month - 1); i++) {
			 days += DaysInMonth(year, i);
		 }

		 days += day;

		 return days;
	 };

	

	 

	 static clsDate AddOneDay(clsDate date) {
		 if (IsLastDay(date)) {
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
	 static clsDate MinusOneDay(clsDate date) {
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
	 };

protected:
	enum enDateCompare { after = 1, before = -1, equal = 0 };
	static short CompareDates(clsDate date1, clsDate date2) {
		 return IsDate1AfterDate2(date1, date2) ? enDateCompare::after : IsDate1EqualDate2(date1, date2) ? enDateCompare::equal : enDateCompare::before;
	 };

public:

	clsDate() {
		GetSystemDate();
	};

	clsDate(string date) {
		StringToDate(date);
	};
	clsDate(short day, short month, short year) {
		this->day = day;
		this->month = month;
		this->year = year;
	};

	clsDate(int days, short year) {
		clsDate date = clsDate::DaysToDate(days, year);
		this->year = date.year;
		this->month = date.month;
		this->day = date.day;
	}

	void SetDay(short day) {
		if (day < DaysInMonth(year, month)) {
			this->day = day;
		};
	};

	short GetDay() {
		return day;
	}

	__declspec(property(get= GetDay, put = SetDay)) short day;

	
	void SetMonth(short m) {
		if (m <= 12) {
			this->month = m;
		};
	};

	short GetMonth() {
		return month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short month;

	void SetYear(short y) {
			this->year = y;
	};

	short GetYear() {
		return year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short year;




	static void SwapDates(clsDate& date1, clsDate& date2) {
		clsDate tempDate;
		tempDate.year = date1.year;
		tempDate.month = date1.month;
		tempDate.day = date1.day;

		date1.year = date2.year;
		date1.month = date2.month;
		date1.day = date2.day;

		date2.year = tempDate.year;
		date2.month = tempDate.month;
		date2.day = tempDate.day;

	};
	void GetSystemDate() {
		time_t t = time(0);
		tm* now = localtime(&t);

		this->year = now->tm_year + 1900;
		this->month = now->tm_mon + 1;
		this->day = now->tm_mday;
	}

	void StringToDate(string strDate) {
		vector<string> vcStrDate = clsString::Split(strDate, "/");
		day = stoi(vcStrDate[0]);
		month = stoi(vcStrDate[1]);
		year = stoi(vcStrDate[2]);
	}

	static string DateToString(clsDate Date)
	{
		return  to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
	}

	string DateToString()
	{
		return  DateToString(*this);
	}
	static clsDate DaysToDate(short days, short year) {
		clsDate date;
		date.month = 1, date.day = days;
		while (DaysInMonth(year, date.month) < date.day) {
			date.day -= DaysInMonth(year, date.month);
			date.month++;
		};
		date.year = year;
		return date;
	}
	
	void Print() {
		cout << to_string(day) << "/" << to_string(month) << "/" << to_string(year) << endl;
	}

	static bool IsValidDate(clsDate date) {
		if (date.day > DaysInMonth(date.year, date.month) || (date.month > 12 && date.month < 1)) {
			return false;
		}
		else {
			return true;
		}

	};
	bool IsValidDate() {
		return IsValidDate(*this);
	};
	
	static string FormatDate(clsDate date, string DateFromat = "dd/mm/yyyy") {
		string FormatedDate = "";
		FormatedDate = clsString::ReplaceWord(DateFromat, "dd", to_string(date.day));
		FormatedDate = clsString::ReplaceWord(FormatedDate, "mm", to_string(date.month));
		FormatedDate = clsString::ReplaceWord(FormatedDate, "yyyy", to_string(date.year));

		return FormatedDate;
	};
	string FormatDate(string DateFormat = "dd/mm/yyyy") {
		return FormatDate(*this, DateFormat);
	};


	// Print Calander
	static void PrintMonthCalender(short year, short month) {
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

	};

	void PrintMonthCalender() {
		PrintMonthCalender(year, month);
	};

	static void PrintYearCalender(short year) {
		for (short month = 1; month <= 12; month++) {
			cout << endl;
			PrintMonthCalender(year, month);
		}
	};
	void PrintYearCalender() {
		PrintYearCalender(year);
	};

	// Date Comparison 
	static bool IsDate1BeforeDate2(clsDate date1, clsDate date2) {
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
	};
	bool IsDateBeforeDate2(clsDate date2) {
		return IsDate1BeforeDate2(*this, date2);
	};
	static bool IsDate1EqualDate2(clsDate date1, clsDate date2) {
		return date1.year == date2.year && date1.month == date2.month && date1.day == date2.day;
	};
	bool IsDateEqualDate2(clsDate date2) {
		return IsDate1EqualDate2(*this, date2);
	};
	static short DaysDifference(clsDate date1, clsDate date2, bool lastDay = false) {
		short days = 0;
		short SwapFlagVal = 1;
		if (!IsDate1BeforeDate2(date1, date2)) {
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
	};

	short DaysDifference(clsDate date2, bool lastDay = false) {

		return DaysDifference(*this, date2, lastDay);
	}

	static short CalculateMyAgeInDays(clsDate myBirthDate) {
		clsDate nowDate;
		return DaysDifference(nowDate, myBirthDate);
	};


	static bool IsLastDay(clsDate date) {
		return date.day == DaysInMonth(date.year, date.month);
	}
	bool IsLastDay() {
		return IsLastDay(*this);
	}
	// Add Days to class date 

	void AddDaysToDate(short addedDays) {
		short remainingDays = addedDays + DaysFromStart(year, month, day);
		month = 1;
		short daysOfMon = 0;
		while (true) {
			daysOfMon = DaysInMonth(year, month);
			if (remainingDays > daysOfMon) {
				remainingDays -= daysOfMon;
				month++;
				if (month > 12) {
					year++;
					month = 1;
				}
			}
			else {
				day = remainingDays;
				break;
			}

		}
	};


	// increase date but certin amount : 


	void IncreaseDateByXDays(short numOfDays) {
		for (short i = 0; i < numOfDays; i++) {
			AddOneDay();
		}
	};

	void IncreaseDateByOneWeek() {
		for (short i = 0; i < 7; i++) {
			AddOneDay();
		}
	};
	void IncreaseDateByXWeeks(short numOfWeeks) {
		for (short i = 0; i < numOfWeeks; i++) {
			IncreaseDateByOneWeek();
		}
	};

	void IncreaseDateByOneMonth() {
		month++;
		if (month == 12) {
			month = 1;
			year++;
		}

		short maxDaysInMonth = DaysInMonth(year, month);
		if (day > maxDaysInMonth) {
			day = maxDaysInMonth;
		}
	};

	void IncreaseDateByXMonths(short numOfMonths) {
		for (short i = 0; i < numOfMonths; i++) {
			IncreaseDateByOneMonth();
		}
	};

	void IncreaseDateByOneYear() {
		year++;
	};


	void IncreaseDateByXYear(short numOfYears) {
		year += numOfYears;
	};

	void IncreaseDateByOneDecade() {
		year += 10;
	};


	void IncreaseDateByXDecades(short numOfDec) {
		year += numOfDec * 10;
	};
	void IncreaseDateByOneCentury() {
		year += 100;
	};

	void IncreaseDateByOneMillennium() {
		year += 1000;
	};

	// decrease date by certin amount 

	void DecreaseDateByXDays(short numOfDays) {
		for (short i = 0; i < numOfDays; i++) {
			MinusOneDay();
		}
	};

	void DecreaseDateByOneWeek() {
		for (short i = 0; i < 7; i++) {
			MinusOneDay();
		}
	};
	void DecreaseDateByXWeeks(short numOfWeeks) {
		for (short i = 0; i < numOfWeeks; i++) {
			DecreaseDateByOneWeek();
		}
	};

	void DecreaseDateByOneMonth() {
		if (month == 1) {
			month = 12;
			year--;
		}
		else {
			month--;
		}

		short maxDaysInMonth = DaysInMonth(this->year, this->month);
		if (day > maxDaysInMonth) {
			day = maxDaysInMonth;
		}

	};
	void DecreaseDateByXMonths(short numOfMonths) {
		for (short i = 0; i < numOfMonths; i++) {
			DecreaseDateByOneMonth();
		}

	};

	void DecreaseDateByOneYear() {
		year--;
	};


	void DecreaseDateByXYear(short numOfYears) {
		year -= numOfYears;
	};

	void DecreaseDateByOneDecade() {
		year -= 10;
	};

	void DecreaseDateByXDecades(short numOfDec) {
		year -= numOfDec * 10;
	};
	void DecreaseDateByOneCentury() {
		year -= 100;
	};

	void DecreaseDateByOneMillennium() {
		year -= 1000;
	};


	// checking the date


	static bool IsEndOfWeek(clsDate date) {
		return DayIndex(date) == 6;
	};
	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	};

	static bool IsWeekend(clsDate date) {
		return DayIndex(date) == 5 || DayIndex(date) == 6;
	};
	bool IsWeekend() {
		return IsWeekend(*this);
	};

	static bool IsBusinessDay(clsDate date) {
		return !IsWeekend(date);
	};

	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	};

	static short DaysUntilTheEndOfWeek(clsDate date) {
		return 7 - (DayIndex(date) + 1);
	};
	short DaysUntilTheEndOfWeek() {
		return DaysUntilTheEndOfWeek(*this);
	};

	static short DaysUntilTheEndOfMonth(clsDate date) {
		return DaysInMonth(date.year, date.month) - date.day;
	};
	short DaysUntilTheEndOfMonth() {
		return DaysUntilTheEndOfMonth(*this);
	};

	static short DaysUntilTheEndOfYear(clsDate date) {
		short daysUntilNow = DaysFromStart(date.year, date.month, date.day);
		return IsLeapYear(date.year) ? 366 - daysUntilNow : 365 - daysUntilNow;
	};

	short DaysUntilTheEndOfYear() {
		return DaysUntilTheEndOfYear(*this);
	};

	static short VactionsPeriod(clsDate DateFrom, clsDate DateTo) {
		short days = 0;
		while (!IsDate1EqualDate2(DateFrom, DateTo)) {
			if (IsBusinessDay(DateFrom)) {
				days++;
			}
			DateFrom = AddOneDay(DateFrom);

		}
		return days;
	};
	short VactionsPeriod(clsDate DateTo) {
		return VactionsPeriod(*this, DateTo);
	};
	static clsDate ReturnFromVacationDate(clsDate DateFrom, short VacationDays) {
		short weekendDays = 0;
		while (IsWeekend(DateFrom)) {
			DateFrom = AddOneDay(DateFrom);
		}

		for (short i = 1; i <= VacationDays + weekendDays; i++) {

			if (IsWeekend(DateFrom)) {
				weekendDays++;
			}
			DateFrom = AddOneDay(DateFrom);
		}
		while (IsWeekend(DateFrom)) {
			DateFrom = AddOneDay(DateFrom);
		}

		return DateFrom;

	};

	clsDate ReturnFromVacationDate(short vactionDays) {
		return ReturnFromVacationDate(*this, vactionDays);
	};


	static bool IsDate1AfterDate2(clsDate date1, clsDate date2) {
		return !IsDate1BeforeDate2(date1, date2) && !IsDate1EqualDate2(date1, date2);
	};
	bool IsDateAfterDate2(clsDate date2) {
		return IsDate1AfterDate2(*this, date2);
	};

	


};

class clsPeriod : private clsDate{
	clsDate _FromPeriod;
	clsDate _ToPeriod;

public:
	clsPeriod() {};
	clsPeriod(clsDate from, clsDate to) {
		_FromPeriod = from;
		_ToPeriod = to;
	};

	void SetFromPeriod(clsDate From) {
		_FromPeriod = From;
	};
	clsDate GetFromPeriod() {
		return _FromPeriod;
	};

	void SetToPeriod(clsDate To) {
		_ToPeriod = To;
	};
	clsDate GetToPeriod() {
		return _ToPeriod;
	};


	static bool IsPeriodsOverlap(clsPeriod period1, clsPeriod period2) {
		if (clsDate::CompareDates(period1._FromPeriod, period2._ToPeriod) == enDateCompare::after || CompareDates(period1._ToPeriod, period2._FromPeriod) == enDateCompare::before) {
			return false;
		}
		else {
			return true;
		}

	};

	bool IsPeriodsOverlap(clsPeriod period2) {
		return IsPeriodsOverlap(*this, period2);
	};

	static short PeriodsInDays(clsPeriod period1, bool LastDay = false) {
		return DaysDifference(period1._FromPeriod, period1._ToPeriod, LastDay);
	};

	short PeriodsInDays(bool LastDay = false) {
		return PeriodsInDays(*this, LastDay);
	};

	static bool IsDateInPeriod(clsPeriod per, clsDate date) {
		return !(CompareDates(date, per._ToPeriod) == enDateCompare::after ||
			CompareDates(date, per._FromPeriod) == enDateCompare::before);
	}
	bool IsDateInPeriod(clsDate date) {
		return IsDateInPeriod(*this, date);
	};

	static short CountOverlapDays(clsPeriod per1, clsPeriod per2) {
		if (!IsPeriodsOverlap(per1, per2))
			return 0;

		clsDate MaxStart = CompareDates(per1._FromPeriod, per2._FromPeriod) == enDateCompare::after ? per1._FromPeriod : per2._FromPeriod;
		clsDate MinEnd = CompareDates(per1._ToPeriod, per2._ToPeriod) == enDateCompare::before ? per1._ToPeriod : per2._ToPeriod;

		return DaysDifference(MaxStart, MinEnd);
	};

	short CountOverlapDays(clsPeriod per2) {
		return CountOverlapDays(*this, per2);
	};

};