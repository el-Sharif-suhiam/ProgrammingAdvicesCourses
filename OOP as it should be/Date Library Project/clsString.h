#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{
	string _value;
    vector<string> _stringVector;

    static char InvertChar(char letter) {
        return isupper(letter) ? tolower(letter) : toupper(letter);
    };
    static bool IsVowle(char letter) {
        letter = tolower(letter);
        return (letter == 'a' || letter == 'e' || letter == 'o' || letter == 'i' || letter == 'u');
    };
public:

	clsString() {

	};

	clsString(string newValue) {
		_value = newValue;
	}
    
    void SetValue(string val) {
        _value = val;
    }

    string GetValue() {
        return _value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;

    // methods 

    // change the first letter to upper case in every word
    static string UpFirstLetter(string sentence) {
        bool FirstL = true;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] != ' ' && FirstL) {
                sentence[i] = toupper(sentence[i]);
            }
            FirstL = (sentence[i] == ' ' ? true : false);
        }
        return sentence;
    }

    void UpFirstLetter() {
        _value = UpFirstLetter(_value);
    }

    // change the first letter to lower case 
    static string LowFirstLetter(string sentence) {
        bool FirstL = true;
        cout << "The First Letters is : \n";
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] != ' ' && FirstL) {
                sentence[i] = tolower(sentence[i]);
            }
            FirstL = (sentence[i] == ' ' ? true : false);
        }
        return sentence;
    }

    void LowFirstLetter() {
        _value = LowFirstLetter(_value);
    }
    // all word to lower and upper case 

    static string ToUpperCase(string sentence) {
        for (int i = 0; i < sentence.length(); i++) {

            sentence[i] = toupper(sentence[i]);
        }
        return sentence;
    }
    void ToUpperCase() {
        _value = ToUpperCase(_value);
    };

    static string ToLowerCase(string sentence) {
        for (int i = 0; i < sentence.length(); i++) {

            sentence[i] = tolower(sentence[i]);
        }
        return sentence;
    }

    void ToLowerCase() {
        _value = ToLowerCase(_value);
    }

    // invert case for all letters

    
    static string InvertCase(string sentence) {
        for (int i = 0; i < sentence.length(); i++) {

            sentence[i] = InvertChar(sentence[i]);
        }
        return sentence;
    };

    void InvertCase() {
        _value = InvertCase(_value);
    };
    // count vowels
    
    static short CountVowels(string msg) {
        short Counter = 0;
        for (short i = 0; i < msg.length(); i++) {
            if (IsVowle(msg[i])) {
                Counter++;
            }
        }
        return  Counter;
    };
    short CountVowels() {
        return CountVowels(_value);
    };
    // count words in string 

    static short CountWords(string txt) {
        string delmi = " ";
        short pos = 0;
        string subtxt;
        short count = 0;
        while ((pos = txt.find(delmi)) != std::string::npos) {
            subtxt = txt.substr(0, pos);
            if (subtxt != "") {
                count++;
            }

            txt.erase(0, pos + delmi.length());
        }
        if (txt != "") {

            count++;
        }
        return count++;
    }

    short CountWords() {
        return CountWords(_value);
    };

    // spilt words and return it as vector
    static vector<string> Split(string msg, string delmi) {
        vector<string> vcWords;
        short pos = 0;
        string subtxt;
        while ((pos = msg.find(delmi)) != std::string::npos) {
            subtxt = msg.substr(0, pos);
            if (subtxt != "") {
                vcWords.push_back(subtxt);
            }

            msg.erase(0, pos + delmi.length());
        }
        if (msg != "") {

            vcWords.push_back(msg);
        }
        return vcWords;
    };

    void Split(string delmi = " ") {
        _stringVector = Split(_value, delmi);
    };

    // trim

    static string Trim(string msg) {
        if (msg[0] == ' ') {
            short count = 0;
            while (msg[count] == ' ') {
                count++;
            }
            msg.erase(0, count);
        }
        if (msg[msg.size() - 1] == ' ') {
            short revrseCount = msg.size() - 1;
            while (msg[revrseCount - 1] == ' ') {
                revrseCount--;
            }
            msg.erase(revrseCount, (msg.size() - 1));
        }


        return msg;
    };

    string Trim() {
        return Trim(_value);
    };


    static string TrimLeft(string msg) {
        if (msg[0] == ' ') {
            short count = 0;
            while (msg[count] == ' ') {
                count++;
            }
            msg.erase(0, count);
        }
        return msg;

        for (short i = 0; i < msg.length(); i++) {
            if (msg[i] != ' ') {
                return msg.substr(i, msg.length() - 1);
            }
        }
    };

    string TrimLeft() {
        return TrimLeft(_value);
    }

    static string TrimRight(string msg) {

        if (msg[msg.size() - 1] == ' ') {
            short revrseCount = msg.size() - 1;
            while (msg[revrseCount - 1] == ' ') {
                revrseCount--;
            }
            msg.erase(revrseCount, (msg.size() - 1));
        }


        return msg;
    };

    string TrimRight() {
        return TrimRight(_value);
    };

    // join string 
    static string Join(vector<string> vcWords, string delmi) {
        string newString = "";
        for (string& word : vcWords) {
            newString = newString + word + delmi;
        };
        return newString.substr(0, newString.length() - delmi.length());
    };


    static string Join(string vcWords[], string delmi, short arrNum) {
        string newString = "";
        for (short i = 0; i < arrNum; i++) {
            newString = newString + vcWords[i] + delmi;
        };
        return newString.substr(0, newString.length() - delmi.length());
    };

    void Join(string delmi = " ") {
        _value = Join(_stringVector, delmi);
    };


    // reverse words in string 

    static string RevserseWords(string msg) {
        string newString = "";
        vector<string> vcWords = Split(msg, " ");
        vector<string>::iterator iter = vcWords.end();
        while (iter != vcWords.begin()) {
            --iter;
            newString += *iter + " ";
        }

        return newString.substr(0, newString.length() - 1);
    };

    void RevserseWords() {
        _value = RevserseWords(_value);
    };

    // replace word with another one

    static string ReplaceWord(string txt, string wantReplace, string toReplace, bool matchCase = false) {

        vector<string> vcString = Split(txt, " ");
        for (string& word : vcString) {
            if (matchCase) {
                if (word == wantReplace) {
                    word = toReplace;
                }
            }
            else {
                if (ToLowerCase(word) == ToLowerCase(wantReplace)) {
                    word = toReplace;
                }
            }
        }

        string newWord = Join(vcString, " ");

        return newWord;
    };

    void ReplaceWord(string WantReplace, string ToReplace, bool matchCase = false) {
        _value = ReplaceWord(_value, WantReplace, ToReplace, matchCase);
    };

    // remove punctions

    static string RemovePunct(string txt) {

        for (short i = 0; i < txt.length(); i++) {
            if (ispunct(txt[i])) {
                txt[i] = ' ';
            }
        }
        return txt;
    };

    string RemovePunct() {
        return RemovePunct(_value);
    };


};

