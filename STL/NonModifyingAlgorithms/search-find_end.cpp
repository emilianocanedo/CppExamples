/*
Both functions search a given range of elements (last, first) for the presence of sequence of elements 
specified by iterators s_first and s_last. search() algorithm will return an iterator to the first 
occurrence of the sequence s_first, s_last, whereas the find_end() function will return an iterator 
to the last occurrence of the mentioned sequence. This is the only difference between both algorithms.
As should be noticed, both functions come in two versions. The second version must be provided with a 
binary predicate used to perform a comparison between the two elements of the collection. The first 
version uses the equality operator (==) for the same purpose. Below you can see a possible header of 
such binary predicate:

template <class Element1, class Element2> bool f(Element1 e1, Element2 e2);

It can also be implemented as a functional object. It is important that this predicate does not 
perform any modifications to the collection element, as it would be a violation of STL policy towards 
the so-called non-modifying algorithms.
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

int main()
{
	int t[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 3, 4, 2};
	vector<int> v1(t, t+18);
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	int ts[] = {2, 3};
	
	cout << "Searching for the sequence 2, 3 from the beginning:" << endl;
	vector<int>::iterator found = search(v1.begin(), v1.end(), ts, ts+2);
	if (found != v1.end())
		cout << "Sequence 2, 3 has been found at position: " << distance(v1.begin(), found) << endl;
	else
		cout << "Sequence 2, 3 could not be found" << endl;
	cout << endl;

	cout << "Searching for sequence 2, 3 from the end" << endl;
	found = find_end(v1.begin(), v1.end(), ts, ts+2);
	if (found != v1.end())
		cout << "Sequence 2, 3 has been found at position: " << distance(v1.begin(), found) << endl;
	else
		cout << "Sequence 2, 3 could not be found" << endl;

	return 0;
}