#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

void print(const int& value)
{
	cout << value << " ";
}

int main()
{
	int t1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int t2[] = {1, 2, 4, 6, 7, 3, 5, 9, 10, 8};

	vector<int> v1(t1, t1+10);
	list<int> l1(t2, t2+10);

	cout << "v1: ";
	for_each(v1.begin(), v1.end(), print);
	cout << endl;

	cout << "l1: ";
	for_each(l1.begin(), l1.end(), print);
	cout << endl;

	pair<vector<int>::iterator, list<int>::iterator> p1 = mismatch(v1.begin(), v1.end(), l1.begin());
	if (p1.first == v1.end() && p1.second == l1.end()) {
		cout << "Collections v1 & l1 are equal!" << endl;
	} else {
		cout << "Collections v1 & l1 are NOT equal!" << endl;
		cout << "Mismatch at position: " << distance(v1.begin(), p1.first) << endl;
		cout << "First not matching element - v1: " << *(p1.first) << " l1: " << *(p1.second) << endl;
	}
	
	return 0;
}
