#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

void print(const int& value)
{
	cout << value << " ";
}

struct Compare
{
	bool operator()(const char& f, const char& s)
	{
		return tolower(f) == tolower(s);
	}
};

int main()
{
	char t1[] = {'a', 'b', 'c', 'd', 'A', 'D', 'A', 'b', 'C', 'a', 'f'};
	vector<int> v2(t1, t1+12);
	for_each(v2.begin(), v2.end(), print);
	cout << endl << endl;
	char ts1[] = {'a', 'b'};

	cout << "Searching for the any of elements 'a', 'b' from the beginning" << endl;
	vector<int>::iterator found1 = find_first_of(v2.begin(), v2.end(), ts1, ts1+2, Compare());
	if (found1 != v2.end()) {
		cout << "Found value: " << *found1 << " at position: " << distance(v2.begin(), found1) << endl;
		cout << "Looking for any other element with value 'a' or 'b'" << endl;
		++found1; //skip element already found if any
		while ((found1 = find_first_of(found1, v2.end(), ts1, ts1+2, Compare())) != v2.end()) {
			cout << "Found value: " << char(*found1) << " at position: " << distance(v2.begin(), found1) << endl;
			++found1;
		}
	} else {
		cout << "No elements with value 'a' or 'b'!" << endl;
	}

	return 0;
}