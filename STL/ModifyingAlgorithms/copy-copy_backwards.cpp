/*
The function copy_backward() copies all elements from the source range [first, last) starting 
with element last-1 and puts them into the destination range starting at position d_last-1. 
With each copy the operation source and target collection iterators are decreased.
This function does not add or insert values into the destination collection (range), it only 
assigns values, so the destination range must have enough space allocated. The source and target 
ranges should not overlap in such a way that a particular element would be written before being read.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

void print(const int& value)
{
	cout << value << " ";
}

int main()
{
	int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	cout << "Copy:" << endl;
	vector<int> v1(t, t+10);
	cout << "Source collection:" << endl;
	for_each(v1.begin(), v1.end(), print);
	cout << endl;
	deque<int> d1(10); //list for 10 elements
	cout << "Target collection before copy:" << endl;
	for_each(d1.begin(), d1.end(), print);
	cout << endl;
	copy(v1.begin(), v1.end(), d1.begin());
	cout << "Target collection after copy:" << endl;
	for_each(d1.begin(), d1.end(), print);
	cout << endl << endl;

	cout << "Copy backward" << endl;
	vector<int> v2(t, t+10);
	cout << "Source collection:" << endl;
	for_each(v2.begin(), v2.end(), print);
	cout << endl;
	deque<int> d2(10); //list for 10 elements
	cout << "Target collection before copy:" << endl;
	for_each(d2.begin(), d2.end(), print);
	cout << endl;
	copy(v2.begin(), v2.end(), d2.begin());
	cout << "Target collection after copy:" << endl;
	for_each(d2.begin(), d2.end(), print);
	cout << endl << endl;
}
