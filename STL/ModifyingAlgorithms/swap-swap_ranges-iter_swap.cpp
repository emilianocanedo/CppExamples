#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

template<class T>
void print(const T& value)
{
	cout << value << " ";
}

int main()
{
	cout << "Simple swap of values:" << endl;
	int a = 10, b = 100;
	cout << "a: " << a << " b: " << b << endl;
	swap(a, b);
	cout << "After swap:" << endl;	
	cout << "a: " << a << " b: " << b << endl;
	cout << endl;

	cout << "Simple iterator swap:" << endl;
	int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	list<int> l1(t, t+10);
	for_each(l1.begin(), l1.end(), print<int>);
	cout << endl;
    
    cout << "Swapping first and last elements:" << endl;
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl;
    list<int>::iterator it = l1.end();
    advance(it, -1);
    iter_swap(l1.begin(), it);
    cout << "After swap:" << endl;
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl << endl;

    cout << "Swapping iterator ranges - switching halves of the list:" << endl;
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl;
    advance(it, -4);
    swap_ranges(l1.begin(), it, it);
    cout << "After swap:" << endl;
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl;

    return 0;
}
