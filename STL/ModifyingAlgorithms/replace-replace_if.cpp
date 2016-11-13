/*
Both functions replace elements which they find fitting with new_value. The difference between 
them is related to searching for values to be replaced. The first version (replace) simply compares 
the given old_value with elements inside the range. If they are equal, the old value is replaced 
by the new one. The second version (replace_if) replaces all elements for which a given predicate p 
returns true. Both functions will find and replace all matching elements.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template<class T>
void print(const T& value)
{
	cout << value << " ";
}

struct Odd
{
    bool operator()(const int& a)
    {
        return a % 2 != 0;
    }
};

int main()
{
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> l1(t, t+10);
    
    cout << "Source collection:" << endl;
    cout << "l1:";
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl << endl;

    cout << "Replacing value 5 with 15:" << endl;
    replace(l1.begin(), l1.end(), 5, 15);
    cout << "l1:";
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl << endl;
    
    cout << "Replacing all odd numbers with value 13:" << endl;
    replace_if(l1.begin(), l1.end(), Odd(), 13);
    cout << "l1:";
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl << endl;    

    return 0;
}
