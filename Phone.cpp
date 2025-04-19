#include "Phone.h"

Phone::Phone() : Device(), simCount(1), batteryLevel(0), phoneNumber(""), phoneApp("") {}

Phone::Phone(const string& name, int year, double weight, const string& os, int simCount)
    : Device(name, year, weight, os), simCount(simCount), batteryLevel(0), phoneNumber(""), phoneApp("") {}

Phone::Phone(const Phone& other)
    : Device(other), simCount(other.simCount), batteryLevel(other.batteryLevel),
      phoneNumber(other.phoneNumber), phoneApp(other.phoneApp) {}

Phone& Phone::operator=(const Phone& other)
{
    if (this != &other)
    {
        Device::operator=(other);
        simCount = other.simCount;
        batteryLevel = other.batteryLevel;
        phoneNumber = other.phoneNumber;
        phoneApp = other.phoneApp;
    }
    return *this;
}

Phone::~Phone() {}

void Phone::SetSimCount(int count) { simCount = count; }
int Phone::GetSimCount() const { return simCount; }

void Phone::SetPhoneNumber(const string& number) { phoneNumber = number; }
void Phone::SetPhoneApp(const string& app) { phoneApp = app; }

void Phone::DrainBattery(int percent)
{
    batteryLevel = max(0, batteryLevel - percent);
}

void Phone::Call()
{
    if (phoneNumber.empty())
    {
        cout << name << " has no phone number set!" << endl;
        return;
    }
    cout << name << " is calling " << phoneNumber << "..." << endl;
    DrainBattery();
}

void Phone::InstallApp()
{
    if (phoneApp.empty())
    {
        cout << name << " has no app name set!" << endl;
        return;
    }
    cout << name << " is installing " << phoneApp << "..." << endl;
    DrainBattery();
}

void Phone::ClearRAM()
{
    cout << name << " is clearing RAM..." << endl;
    DrainBattery();
}

void Phone::Charge()
{
    batteryLevel = 100;
    cout << name << " charged to 100%." << endl;
}

void Phone::ShowInfo() const
{
    cout << "--- Phone Info ---" << endl;
    cout << "Name: " << name << endl;
    cout << "Year: " << year << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "OS: " << *os << endl;
    cout << "SIMs: " << simCount << endl;
    cout << "Battery: " << batteryLevel << "%" << endl;
}
