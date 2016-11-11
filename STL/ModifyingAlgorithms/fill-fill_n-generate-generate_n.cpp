#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

template<class T>
void print(const T& value)
{
	cout << value << " ";
}

struct Generate
{
    int n;
    Generate():n(0){}
    int calculate(int number)
    {
        if (number == 0)
            return 0;
        if (number == 1)
            return 1;

        int n1 = 1, n2 = 0, nn = 0;

        for (int i = 2; i <= number; ++i)
        {
            nn = n1 + n2;
            n2 = n1;
            n1 = nn;
        }

        return nn;
    }
    int operator ()()
    {
        n++;
        return calculate(n-1);
    }
};

int main()
{
    deque<int> d1(10);
    cout << "Source collection - default values:" << endl;
    cout << "d1: ";
    for_each(d1.begin(), d1.end(), print<int>);
    cout << endl << endl;

    cout << "Filling collection with value 1" << endl;
    fill(d1.begin(), d1.end(), 1);
    cout << "d1: ";
    for_each(d1.begin(), d1.end(), print<int>);
    cout << endl << endl;
    
    cout << "Filling half of the collection with value 10" << endl;
    fill_n(d1.begin(), 5, 10);
    cout << "d1: ";
    for_each(d1.begin(), d1.end(), print<int>);
    cout << endl << endl;

    cout << "GENERATE!" << endl;
    cout << "Filling the whole collection with Fibonacci numbers:" << endl;
    generate(d1.begin(), d1.end(), Generate());
    cout << "d1: ";
    for_each(d1.begin(), d1.end(), print<int>);
    cout << endl << endl;

    cout << "Filling the whole collection with Fibonacci numbers - generate_n:" << endl;
    generate_n(d1.begin(), 10, Generate());
    cout << "d1: ";
    for_each(d1.begin(), d1.end(), print<int>);
    cout << endl << endl;

    return 0;
}
