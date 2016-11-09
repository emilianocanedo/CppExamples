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
