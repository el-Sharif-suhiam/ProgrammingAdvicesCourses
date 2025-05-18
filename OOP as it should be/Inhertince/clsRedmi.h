#pragma once
#include <iostream>
#include "clsMobile.h"
using namespace std;
class clsRedmi : public clsMobile {
public:
    void Dialup(int num) {
        cout << "Calling : " << num << endl;
    };

    void SendSMS(int phoneNum, string text) {
        cout << "SMS to: " << phoneNum << endl;
        cout << "Text is: " << text << endl;
    }

    void VideoCall(int num) {

    };
};

