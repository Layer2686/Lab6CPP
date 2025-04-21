#pragma once
#include <iostream>
using namespace std;

class Device {
protected:
    char* name;
    int year;
    double weight;

public:
    Device();
    Device(const char* name, int year, double weight);
    Device(const Device& other);
    Device& operator=(const Device& other);
    virtual ~Device();

    void SetName(const char* name);
    void SetYear(int year);
    void SetWeight(double weight);

    string GetName() const;
    int GetYear() const;
    double GetWeight() const;

    virtual void ShowInfo() const = 0;
    virtual void Charge() = 0;
};
