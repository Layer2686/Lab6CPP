#include "Phone.h"

int main() {
    Phone p1("Google pixel 8A", 2024, 0.368, "Android", 2);
    Phone p2 = p1;
    p1.ShowInfo();
    p1.Charge();

    p2.SetName("iPhone 13");
    p2.SetOS("iOS");
    p2.SetPhoneNumber("+380991234567");
    p2.SetPhoneApp("Telegram");
    p2.ShowInfo();
    p2.Charge();
    p2.Call();
    p2.InstallApp();
    p2.ClearRAM();
    p2.ShowInfo();

    return 0;
}
