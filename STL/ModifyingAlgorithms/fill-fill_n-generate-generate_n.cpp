/*
                    const value    generated value    range (iterators)    count
fill                   x                                     x   
fill_n                 x                                                     x
generate                               x                     x   
generate_n                             x                                     x

All the above functions are used for filling elements of collections. Each of them does it in a 
slightly different way. It is best to put them together and emphasize the differences.

fill and fill_n assign the same value value to all elements specified either by range [first, last) 
or by output iterator ofirst and the count of elements to fill.

generate and generate_n work in a very similar manner, but instead of assigning the same value to 
each of the elements, they assign value provided by a special function p which is called generator. 
This function can return a different value each time it is invoked or might as well always return 
the same value. In the second case it would then operate exactly as fill/fill_n. The table above 
compares all the four filling functions.
*/

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
