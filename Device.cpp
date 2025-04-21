#include "Device.h"
#include <cstring>

Device::Device() : name(nullptr), year(0), weight(0.0)
{
    name = new char[1];
    name[0] = '\0';
}

Device::Device(const char* name, int year, double weight)
    : year(year), weight(weight)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Device::Device(const Device& other)
    : year(other.year), weight(other.weight)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

Device& Device::operator=(const Device& other)
{
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        year = other.year;
        weight = other.weight;
    }
    return *this;
}

Device::~Device()
{
    delete[] name;
}

void Device::SetName(const char* n)
{
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

void Device::SetYear(int y) { year = y; }
void Device::SetWeight(double w) { weight = w; }

string Device::GetName() const { return string(name); }
int Device::GetYear() const { return year; }
double Device::GetWeight() const { return weight; }
