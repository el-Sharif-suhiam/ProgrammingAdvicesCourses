#include "iostream";

using namespace std;

int main() {
	//short firstNum;
	//short secondNum;
	//cout << "Please enter the first number ?" << endl;
	//cin >> firstNum;

	//cout << "Please enter the second number ?" << endl;
	//cin >> secondNum;

	//cout << firstNum << " + " << secondNum << " = " << firstNum + secondNum << endl;
	//cout << firstNum << " - " << secondNum << " = " << firstNum - secondNum << endl;
	//cout << firstNum << " * " << secondNum << " = " << firstNum * secondNum << endl;
	//cout << firstNum << " / " << secondNum << " = " << firstNum / secondNum << endl;
	//cout << firstNum << " % " << secondNum << " = " << firstNum % secondNum << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////
	////  start to solve proplems form algorithms and problem sovling #1 /////////////////////////////

	//// #7

	//unsigned short num;
	// 
	//cout << "\n" << "Enter the number that you want to get it's half ?" << endl;
	//cin >> num;
	//short halfNum = num / 2;
	//cout << "the half of number " << num << " is " << halfNum << endl;

	////////////////////////////////////////////////////////////////////////

	//// #9
	//unsigned short num1, num2, num3;
	//cout << "\n" << "sum three numbers, please enter first number ?" << endl;
	//cin >> num1;
	//cout << "second number ?" << endl;
	//cin >> num2;

	//cout << "third number ?" << endl;
	//cin >> num3;

	//cout << "the sum is  = " << num1 + num2 + num3 << endl;


	///////////////////////////////////////////////////////////////////////////////
	//// #10
	//unsigned short mark1, mark2, mark3;
	//cout << "\n" << "Average of three marks, please enter first marks ?" << endl;
	//cin >> mark1;
	//cout << "second marks ?" << endl;
	//cin >> mark2;

	//cout << "third marks ?" << endl;
	//cin >> mark3;
	//unsigned average = (mark1 + mark2 + mark3) / 3;
	//cout << "the average is  = " << average << endl;

	/////////////////////////////////////////////////////////////////////////////////////////
	//// #14 
	//short swapNum;
	//cout << "this program is to make swap between two numbers, enter the first :" << endl;
	//cin >> num1;
	//cout << "the second" << endl;
	//cin >> num2;

	//cout << "The Result is : \n" << num1 << "\n" << num2 << endl;
	//swapNum = num1;
	//num1 = num2;
	//num2 = swapNum;
	//cout << "The Result is : \n" << num1 << "\n" << num2 << endl;

	/////////////////////////////////////////////////////////////////////////////////////////////
	////# 15
	//short a, b;
	//cout << "Rectangle area enter a number and then b : " << endl;
	//cin >> a;
	//cout << "now the second : " << endl;
	//cin >> b;

	//short area = a * b;
	//cout << "the Area is : " << area << endl;

	///////////////////////////////////////////////////////////////////////////////////////////////
	//// #17
	//cout << "Triangle area enter a number and then b : " << endl;
	//cin >> a;
	//cout << "now the second : " << endl;
	//cin >> b;

	//area = (a/2) * b;
	//cout << "the Area is : " << area << endl;

	//////////////////////////////////////////////////////////////////////
	//// #19
	//float Pi = 3.14;
	//short D;
	//cout << "Circle Area Through Diameter enter D : " << endl;
	//cin >> D;

	//float CircleArea = (Pi * D * D) / 4;
	//cout << "The Area is : " << CircleArea << endl;
	/////////////////////////////////////////////////////////////////////
	//// #21
	//short l;
	//cout << "Circle Area Along the Circumference enter l : " << endl;
	//cin >> l;

	//float CircleAreaL = (l * l) / (4 * Pi);
	//cout << "The Area is : " << CircleAreaL << endl;
	///////////////////////////////////////////////////////////////////////
	//// #22
	//cout << " Circle Area Inscribed in an Isosceles Triangle enter a : " << endl;
	//cin >> a;
	//cout << "now the b : " << endl;
	//cin >> b;

	//float CircleAreaIso = Pi * ((b * b) / 4) * ((2.0 * a - b) / (2.0 * a + b));
	//cout << "The Area is : " << CircleAreaIso << endl;
	//////////////////////////////////////////////////////////////////////
	//// #31
	//cout << "Power of 2,3,4, enter the number : " << endl;
	//cin >> num1;
	//unsigned short power2 = num1 * num1, power3 = power2 * num1, power4 = power3 * num1;

	//cout << "Result is :" << power2 << "\n" << power3 << "\n" << power4 << endl;
	/////////////////////////////////////////////////////////////////////////////////

	// #35

	//short pennies, nickels, dimes, quarters;
	//float dollar;
	//cout << "piggy bank enter Pennies " << endl;
	//cin >> pennies;
	//cout << "piggy bank enter nickel s" << endl;
	//cin >> nickels;
	//cout << "piggy bank enter dimes " << endl;
	//cin >> dimes;
	//cout << "piggy bank enter quarters " << endl;
	//cin >> quarters;
	//cout << "piggy bank enter dollar " << endl;
	//cin >> dollar;
	//nickels = nickels * 5;
	//dimes = dimes * 10;
	//quarters = quarters * 25;
	//dollar = dollar * 100;
	//short totalPennies = pennies + nickels + dimes + quarters + dollar;
	//float totalDollar = static_cast<float>(totalPennies) / 100;
	//cout << totalPennies << " Pennies " << totalDollar << " Dollar" << endl;

	/////////////////////////////////////////////////////////////////////////

	// #39
	//short TotalBill, CashPaid, result;

	//cout << "Remainder Calculater, enter total bill : " << endl;
	//cin >> TotalBill;
	//cout << "enter Paid Cash : " << endl;
	//cin >> CashPaid;

	//result = CashPaid - TotalBill;

	//cout << "result is = " << result << endl;

	/////////////////////////////////////////////////////////////////
	// #40 
	/*float BillValue , Total;
	cout << "Calculate the Service Fee and Sales Tax , please enter the bill : " << endl;
	cin >> BillValue;
	Total = BillValue * 1.1 * 1.16;
	cout << "Result is = " << Total << endl;*/
	////////////////////////////////////////////////////////////////////////
	// #42
	/*short days, hours, minutes, seconds;
	
	cout << "Calculate Task Duration In Seconds, enter days :" << endl;
	cin >> days;
	cout << "hours :" << endl;
	cin >> hours;
	cout << "mintues :" << endl;
	cin >> minutes;
	cout << "seconds :" << endl;
	cin >> seconds;

	int result = (days * 24 * 60 * 60) + (hours * 60 * 60) + (minutes * 60) + seconds;
	
	cout << result << " seconds " << endl;*/
	////////////////////////////////////////////////////////////////////////////////
	// #43
	//int seconds;
	//cout << "program to take seconds and turn it into days, hours, minutes, seconds \n"
	//	<< "enter the seconds : " << endl;
	//cin >> seconds;

	//int remainOfSeconds = seconds % 60;
	//int minutes = (seconds - remainOfSeconds ) / 60, remainOfMin = minutes % 60;
	//int hours = (minutes -remainOfMin ) / 60, remainOfHours = hours % 24;
	//unsigned short days = (hours - remainOfHours ) / 24;

	//cout << "Result is = " << days << ":" << remainOfHours << ":" << remainOfMin << ":"
	//	<< remainOfSeconds << endl;
	////////////////////////////////////////////////////////////////////////////////////////
	//// #47
	//unsigned int LoanAmount, MonthlyPayment;
	//cout << "program to calculate the months do you need to pay your loan\n" <<
	//	"Enter your LoanAmount: " << endl;
	//cin >> LoanAmount;
	//cout << "MonthlyPayment : " << endl;
	//cin >> MonthlyPayment;

	//unsigned short result = LoanAmount / MonthlyPayment;

	//cout << result << " Months" << endl;
	//////////////////////////////////////////////////////////////////////////////////////

	//unsigned short Time;
	//cout << "program to calculate how much do you need to pay every months for your loan\n" <<
	//	"Enter your LoanAmount: " << endl;
	//cin >> LoanAmount;
	//cout << "Months : " << endl;
	//cin >> Time;

	//unsigned short MonthlyBill = LoanAmount / Time;

	//cout << MonthlyBill << " $" << endl;


	return 0;
}