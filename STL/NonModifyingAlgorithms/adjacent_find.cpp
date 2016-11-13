/*
The adjacent_find() function searches the range of elements first, last in order to find the first 
pair of equal consecutive elements. If such a pair is found, the iterator to the first element is 
returned. In the event of the search being unsuccessful the last value is returned. The second 
version of the function uses a binary predicate instead of the equality operator (==) to perform 
a comparison between two elements. Such a predicate might look as follows:

template <class Element1, class Element2> bool f(Element1 e1, Element2 e2);

It can also be implemented as a functional object. It is important that this predicate does not 
perform any modifications to the collection element, as it would be a violation of STL policy 
towards the so-called non-modifying algorithms.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void print(const int& value)
{
	cout << value << " ";
}

int main()
{
	int t[] = {1, 2, 3, 4, 5, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4};
	vector<int> v1(t, t+18);
	for_each(v1.begin(), v1.end(), print);
	cout << endl << endl;

	cout << "Searching for a pair of elements:" << endl;
	vector<int>::iterator found = adjacent_find(v1.begin(), v1.end());
	if (found != v1.end())
		cout << "Pair of elements " << *found << " has been found at position: " << distance(v1.begin(), found) << endl;
	else
		cout << "Pair of the same elements could not be found" << endl;

	return 0;
}
