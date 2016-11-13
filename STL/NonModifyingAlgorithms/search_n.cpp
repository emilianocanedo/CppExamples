/*
This function searches the range first,last for the first sequence of count identical elements, 
each equal to the given value value. The first version uses the equality operator to compare the 
elements, the second version uses the given binary predicate p.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

void print(const int& value)
{
	cout << value << " ";
}

int main()
{
	int t[] = {1, 2, 3, 4, 1, 1, 1, 2, 3, 3, 3, 5, 6, 7, 7, 7, 2, 3, 4};
	vector<int> v1(t, t+18);
	for_each(v1.begin(), v1.end(), print);
	cout << endl << endl;

	cout << "Searching for the following sequence: 7 7 7" << endl;
	vector<int>::iterator found = search_n(v1.begin(), v1.end(), 3, 7);
	if (found != v1.end())
		cout << "Sequence: 7 7 7 has been found at position: " << distance(v1.begin(), found) << endl;
	else
		cout << "Sequence 7 7 7 could not be found" << endl;

	return 0;
}
