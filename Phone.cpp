#include "Phone.h"
#include <iostream>
#include <algorithm>
using namespace std;

Phone::Phone() : Device(), simCount(1), batteryLevel(0), phoneNumber(""), phoneApp("")
{
    os = new string("Unknown");
}

Phone::Phone(const char* name, int year, double weight, const string& osStr, int simCount)
    : Device(name, year, weight), simCount(simCount), batteryLevel(0), phoneNumber(""), phoneApp("")
{
    os = new string(osStr);
}

Phone::Phone(const Phone& other)
    : Device(other), simCount(other.simCount), batteryLevel(other.batteryLevel),
      phoneNumber(other.phoneNumber), phoneApp(other.phoneApp), os(new string(*other.os)) {}

Phone& Phone::operator=(const Phone& other)
{
    if (this != &other)
    {
        Device::operator=(other);
        simCount = other.simCount;
        batteryLevel = other.batteryLevel;
        phoneNumber = other.phoneNumber;
        phoneApp = other.phoneApp;

        delete os;
        os = new string(*other.os);
    }
    return *this;
}

Phone::~Phone()
{
    delete os;
}

void Phone::SetSimCount(int count) { simCount = count; }
int Phone::GetSimCount() const { return simCount; }

void Phone::SetPhoneNumber(const string& number) { phoneNumber = number; }
void Phone::SetPhoneApp(const string& app) { phoneApp = app; }

void Phone::SetOS(const string& o)
{
    delete os;
    os = new string(o);
}

string Phone::GetOS() const { return *os; }

void Phone::DrainBattery(int percent)
{
    batteryLevel = max(0, batteryLevel - percent);
}

void Phone::Call() {
    if (phoneNumber.empty())
    {
        cout << GetName() << " has no phone number set!" << endl;
        return;
    }
    cout << GetName() << " is calling " << phoneNumber << "..." << endl;
    DrainBattery();
}

void Phone::InstallApp()
{
    if (phoneApp.empty())
    {
        cout << GetName() << " has no app name set!" << endl;
        return;
    }
    cout << GetName() << " is installing " << phoneApp << "..." << endl;
    DrainBattery();
}

void Phone::ClearRAM()
{
    cout << GetName() << " is clearing RAM..." << endl;
    DrainBattery();
}

void Phone::Charge()
{
    batteryLevel = 100;
    cout << GetName() << " charged to 100%." << endl;
}

void Phone::ShowInfo() const
{
    cout << "--- Phone Info ---" << endl;
    cout << "Name: " << GetName() << endl;
    cout << "Year: " << year << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "OS: " << *os << endl;
    cout << "SIMs: " << simCount << endl;
    cout << "Battery: " << batteryLevel << "%" << endl;
}
