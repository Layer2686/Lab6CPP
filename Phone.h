#pragma once
#include "Device.h"

class Phone : public Device {
private:
    int simCount;
    int batteryLevel;
    string phoneNumber;
    string phoneApp;
    string* os;

    void DrainBattery(int percent = 2);

public:
    Phone();
    Phone(const char* name, int year, double weight, const string& os, int simCount);
    Phone(const Phone& other);
    Phone& operator=(const Phone& other);
    ~Phone();

    void SetSimCount(int count);
    int GetSimCount() const;

    void SetPhoneNumber(const string& number);
    void SetPhoneApp(const string& app);
    void SetOS(const string& os);
    string GetOS() const;

    void Call();
    void InstallApp();
    void ClearRAM();

    void Charge() override;
    void ShowInfo() const override;
};
