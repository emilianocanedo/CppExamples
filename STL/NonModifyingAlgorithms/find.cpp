#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	int t[] = {10, 2, 4, 3, 5, 6, 10, 8, 9, 10};
	deque<int> d(t, t+10);
	
	cout << "Look for the first e element in the container:" << endl;
	deque<int>::iterator found = find(d.begin(), d.end(), 10);	
	
	if (found != d.end()) {
		cout << "Value 10 found at position: " << distance(found, d.begin()) << endl;
		cout << endl;
		cout << "Founding all remaining elements of value 10" << endl;
		++found; //skip element already found if any;
		while ((found = find(found, d.end(), 10)) != d.end()) {
			cout << "Value 10 found at position: " << distance(d.begin(), found) << endl;
			++found;
		}
	} else {
		cout << "Value 10 not found" << endl;	
	}

	return 0;
}