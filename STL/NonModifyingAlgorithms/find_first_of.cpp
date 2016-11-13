/*
This function searches the range of elements first, last for the presence of any (single) element 
from range s_first, s_last. If such a value is found in range first, last the iterator to it is 
returned. If search is unsuccessful, then the function returns the last iterator. It is important 
to understand that each value from the range s_first, s_last is treated independently; therefore 
the order of elements in that sequence has no influence on the search result. Binary predicate is 
used for comparing elements in ranges. It should return true if two elements are considered equal. 
The first version of the function uses the equality operator (==) for the same purpose. Below you 
can see a possible header of such a binary predicate:

template <class Element1, class Element2> bool f(Element1 e1, Element2 e2);

It can also be implemented as a functional object. It is important that this predicate does not 
perform any modifications to the collection element, as it would be a violation of STL policy 
towards the so-called non-modifying algorithms.
*/

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