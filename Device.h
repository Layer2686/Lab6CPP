#pragma once
#include <iostream>
using namespace std;

class Device {
protected:
    string name;
    int year;
    double weight;
    string* os;

public:
    Device();
    Device(const string& name, int year, double weight, const string& os);
    Device(const Device& other);
    Device& operator=(const Device& other);
    virtual ~Device();

    void SetName(const string& name);
    void SetYear(int year);
    void SetWeight(double weight);
    void SetOS(const string& os);

    string GetName() const;
    int GetYear() const;
    double GetWeight() const;
    string GetOS() const;

    virtual void ShowInfo() const = 0;
    virtual void Charge() = 0;
};
