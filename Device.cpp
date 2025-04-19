#include "Device.h"

Device::Device() : name(""), year(0), weight(0.0), os(new string("Unknown")) {}

Device::Device(const string& name, int year, double weight, const string& os)
    : name(name), year(year), weight(weight), os(new string(os)) {}

Device::Device(const Device& other)
    : name(other.name), year(other.year), weight(other.weight), os(new string(*other.os)) {}

Device& Device::operator=(const Device& other)
{
    if (this != &other)
    {
        name = other.name;
        year = other.year;
        weight = other.weight;
        delete os;
        os = new string(*other.os);
    }
    return *this;
}

Device::~Device()
{
    delete os;
}

void Device::SetName(const string& n) { name = n; }
void Device::SetYear(int y) { year = y; }
void Device::SetWeight(double w) { weight = w; }
void Device::SetOS(const string& o)
{
    delete os;
    os = new string(o);
}

string Device::GetName() const { return name; }
int Device::GetYear() const { return year; }
double Device::GetWeight() const { return weight; }
string Device::GetOS() const { return *os; }
