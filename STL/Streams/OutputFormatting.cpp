#include <iostream>

using namespace std;

int main()
{
    cout << "Current fill character: " << cout.fill() << ", code: " << (int)cout.fill() << endl;
    cout << "Current field width: " << cout.width() << endl << endl;

    //changing width
    cout.width(3);
    cout << "Field width after change: " << cout.width() << endl;
    cout << 1 << 2 << 3 << endl;
    cout << "Width after output: " << cout.width() << endl << endl;

    //changing width and fill
    cout.width(3);
    cout.fill('_');
    cout << "Current fill character: " << cout.fill() << ", code: " << (int)cout.fill() << endl;
    cout << 1 << 2 << 3 << endl << endl;

    cout << "Setting width before each write: " << endl;
    cout << "adjustfield - not set/default" << endl;
    for (unsigned i = 1; i <= 3; ++i) {
        cout.width(3);
        cout << i;
    }
    cout << endl;

    cout << "adjustfield - left:" << endl;
    cout.setf(ios::left, ios::adjustfield);
    for (unsigned i = 1; i <= 3; ++i) {
        cout.width(3);
        cout << i;
    }
    cout << endl;

    cout << "adjustfield - internal" << endl;
    cout.setf(ios::internal, ios::adjustfield);
    for (unsigned i = 1; i <= 3; ++i) {
        cout.width(3);
        cout << i;
    }
    cout << endl;

    cout << "adjustfield - right" << endl;
    cout.setf(ios::right, ios::adjustfield);
    for (unsigned i = 1; i <= 3; ++i) {
        cout.width(3);
        cout << i;
    }
    cout << endl << endl;

    cout << "Precision example" << endl;

    double d1 = 123.45555556;
    unsigned p = cout.precision();

    cout << "Mode: default" << endl;
    cout.precision(p);
    cout << "Precision: " << cout.precision() << endl;
    cout << "d1: " << d1 << endl;
    cout.precision(4);
    cout << "Precision: " << cout.precision() << endl;
    cout << "d1: " << d1 << endl;
    cout.precision(2);
    cout << "Precision: " << cout.precision() << endl;
    cout << "d1: " << d1 << endl << endl;

    
    cout << "Mode: fixed" << endl;
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(p);
    cout << "Precision: " << cout.precision() << endl;
    cout << "d1: " << d1 << endl;
    cout.precision(4);
    cout << "Precision: " << cout.precision() << endl;
    cout << "d1: " << d1 << endl;
    cout.precision(2);
    cout << "Precision: " << cout.precision() << endl;
    cout << "d1: " << d1 << endl << endl;
    
    
    cout << "Mode: scientific" << endl; 
    cout.setf(ios::scientific, ios::floatfield);
    cout.precision(p);
    cout << "Precision: " << cout.precision() << endl;
    cout << "d1: " << d1 << endl;
    cout.precision(4);
    cout << "Precision: " << cout.precision() << endl;
    cout << "d1: " << d1 << endl;
    cout.precision(2);
    cout << "Precision: " << cout.precision() << endl;
    cout << "d1: " << d1 << endl << endl;

    return 0;
}
