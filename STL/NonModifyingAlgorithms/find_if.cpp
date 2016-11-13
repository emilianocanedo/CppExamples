/*
Algorithms find() and find_if() are used to search collections (expressed as a range of elements) 
in order to find a particular element. This search can be performed by:

    simply comparing all values in range with the given searched value (find) – the function will 
    return the element which compares equal to a given value,
    checking all elements against some unary predicate stated as a function or functional 
    object (find_if) – the function will return the element for which the given predicate 
    returns true.

Regardless of the function some behaviors are common:

    both functions will only return the first matching element,
    if an element could not be found, both algorithms will return the last element.
*/

#include <iostream>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

bool odd(const int& value)
{
	return value % 2 != 0;
}

struct Even
{
	bool operator()(const int& value)
	{
		return value % 2 == 0;
	}
};

int main()
{
	int t[] = {10, 2, 4, 3, 5, 6, 7, 8, 9, 1};
	deque<int> d(t, t+10);
	
	cout << "Look for the first odd element in the container:" << endl;
	deque<int>::iterator found = find_if(d.begin(), d.end(), odd);
	
	if (found != d.end())
		cout << "Found odd element: " << *found << endl; 
	else
		cout << "Odd element not found" << endl;
	cout << endl;

	cout << "Look for the first even element in the container:" << endl;
	found = find_if(d.begin(), d.end(), Even());

	if (found != d.end())
		cout << "Found even element: " << *found << endl; 
	else
		cout << "Even element not found" << endl;
	cout << endl;

	return 0;
}