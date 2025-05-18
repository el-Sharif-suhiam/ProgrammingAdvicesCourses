// Problem #1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int ReadNum() {
    int num;
    cout << "Enter the Number : ";
    cin >> num;
    return num;
}

string NumToText(int num) {
    string text = "";
    if (num == 0) {
        return "";
    }
    else if (1 <= num && num <= 19) {
        string arr[] = { "","one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen",
        "sixteen", "seventeen", "eighteen", "nineteen" };
        return arr[num] + " ";
    }
    else if (20 <= num && num <= 99) {
        string arr[] = {
            "","",
     "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety"
        };
        return arr[num / 10] + " " + NumToText(num % 10);
    }
    else if (100 <= num && num <= 999) {
        string arr[] = {
    "",
    "one hundred",
    "two hundred",
    "three hundred",
    "four hundred",
    "five hundred",
    "six hundred",
    "seven hundred",
    "eight hundred",
    "nine hundred"
        };
        return  arr[num / 100] + " " + NumToText(num % 100);
    }
    else if (1000 <= num && num <= 9999) {
        string arr[] = {
    "",
    "one thousand",    
    "two thousand",    
    "three thousand",  
    "four thousand",   
    "five thousand",   
    "six thousand",    
    "seven thousand",  
    "eight thousand",  
    "nine thousand",   
    "ten thousand"     
        };

        return arr[num / 1000] + " " + NumToText(num % 1000);
    }
    else if (10000 <= num && num <= 999999) {
        return NumToText(num / 1000) + "thousand, " + NumToText(num % 1000);
    }
    else if (1000000 <= num && num <= 999999999) {
        return NumToText(num / 1000000) + "million, " + NumToText(num % 1000000);
    }
}

int main()
{
    int num = ReadNum();
    cout << NumToText(num) << endl;

    return 0;
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
