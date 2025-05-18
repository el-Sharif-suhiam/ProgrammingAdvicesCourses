#pragma once
#include <iostream>
using namespace std;
class clsMobile {
    virtual void Dialup(int phoneNumber) = 0;
    virtual void SendSMS(int phoneNumber, string text) = 0;
    virtual void VideoCall(int phoneNumber) = 0;
};

