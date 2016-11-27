#include <iostream>

using namespace std;

int main()
{
    int value = 65535;
    cout << "Default ios::basefield value - dec:" << endl;
    cout << nouppercase << value << endl;

    cout << "Setting ios::basefield to oct:" << endl;
    cout << oct << value << endl;

    cout << "Setting ios::basefield to hex:" << endl;
    cout << hex << value << endl;

    cout << "Setting uppercase flag when displaying value as hex:" << endl;
    cout << uppercase << value << endl << endl;

    cout << "Display above values using showbase flag:" << endl;
    cout.setf(ios::dec, ios::basefield);
    cout.setf(ios::showbase);
    cout << "Default ios::basefield value - dec:" << endl;
    cout << value << endl;

    cout << "Setting ios::basefield to oct:" << endl;
    cout.setf(ios::oct, ios::basefield);
    cout << value << endl; 

    cout << "Setting ios::basefield to hex:" << endl;
    cout.setf(ios::hex, ios::basefield);
    cout << value << endl;

    cout << "Setting uppercase flag when displaying value as hex:" << endl;
    cout.setf(ios::uppercase);
    cout << value << endl << endl;

    int v = 100;
    bool b = true;
    double d = 100;

    cout << "Without flags:" << endl;
    cout << v << endl;
    cout << b << endl;
    cout << d << endl << endl;

    cout << "Flags set:" << endl;
    cout.setf(ios::showpos);
    cout.setf(ios::boolalpha);
    cout.setf(ios::showpoint);
    cout << v << endl;
    cout << b << endl;
    cout << d << endl << endl;

    return 0;
}
