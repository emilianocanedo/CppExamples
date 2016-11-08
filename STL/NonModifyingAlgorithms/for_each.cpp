#include <iostream>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

void print(const int& value)
{
	cout << value << " ";
}

//OR

struct Print
{
	void operator()(const int& value)
	{
		print(value);
	}
};

int main()
{
	int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	list<int> l(t, t+10);

	cout << "Print all elements of the container - using function" << endl;
	for_each(l.begin(), l.end(), print);
	cout << endl << endl;

	cout << "Print all elements of the container - using function object" << endl;
	for_each(l.begin(), l.end(), Print());
	cout << endl << endl;

	//!! Be aware of sets and maps !!
	// change arguments of function print and function object must be const

	set<int> s(t, t+10);

	cout << "Print all elements of the set - using function" << endl;
	for_each(s.begin(), s.end(), print);
	cout << endl << endl;

	cout << "Print all elements of the set - using function object" << endl;
	for_each(s.begin(), s.end(), Print());
	cout << endl << endl;

	return 0;
}