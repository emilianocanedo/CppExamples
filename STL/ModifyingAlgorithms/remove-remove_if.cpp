/*
Functions remove() and remove_if() remove elements from the collection. The first one removes all
elements which are equal to the given value value, the second version removes all elements for which 
the invocation of unary predicate p returns true. Both functions return the new end of the range 
(past-the-end element). The new range is defined as [first, return_value) and it does not contain 
elements doomed for removal.

Regardless of functions’ names, the elements are not in fact physically removed. The size of the 
original collection stays the same. remove() and remove_if() simply rearrange the input collections 
so all elements to be removed are overwritten by elements which follow them if there are any. This 
way, the new shorter range of elements is obtained, and its past-the-end element is returned.
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

struct Even
{
    bool operator()(const int& a)
    {
        return a % 2 == 0;
    }
};

int main()
{
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list<int> l1(t, t+10);
    cout << "Source collection:" << endl;
    cout << "l1: ";
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl << endl;

    cout << "Removing value 6:" << endl;
    list<int>::iterator newEnd = remove(l1.begin(), l1.end(), 6);
    cout << "Collection after removal - size did not change!" << endl;
    cout << "l1: ";
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl << endl;
    cout << "Displaying only elements up to the new logical end of the collection" << endl;
    cout << "l1: ";
    for_each(l1.begin(), newEnd, print<int>);
    cout << endl << endl;

    cout << "Removing all even values:" << endl;
    newEnd = remove_if(l1.begin(), l1.end(), Even());
    cout << "Collection after removal - size did not change!" << endl;
    cout << "l1: ";
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl << endl;
    cout << "Displaying only elements up to the new logical end of the collection" << endl;
    cout << "l1: ";
    for_each(l1.begin(), newEnd, print<int>);
    cout << endl << endl;

    return 0;
}
