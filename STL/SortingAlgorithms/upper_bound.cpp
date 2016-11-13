/*
upper_bound() returns an iterator to the first element in the sorted range [first, last) 
which is greater than the value value, or if there is no such element, 
last is returned. In order to do so, the function compares the elements 
using either the less operator (<) or the provided comparison function comp. 
For this function to work as expected it is required that the range of 
elements is sorted.
*/

#include <deque>
#include <string>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

template <class T> 
void print(T start, T end) 
{
    for ( ;start != end; ++start) {
        std::cout << *start << " "; 
    }
}

int compare(int a, int b)
{
	return b < a;
}

void printMessage(bool value, int element)
{
	if (value)
	{
		cout<<"Element "<<element<<" has been found!" << endl;
	}
	else
	{
		cout<<"Element "<<element<<" could not be found!" << endl;
	}
}

int main()
{
	int t[]={1, 10, 8, 4, 5, 6, 3, 9, 7, 2};
	deque <int> d1(t,t+10);
	
	cout<<"Source collection:" << endl;
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;
	
	cout<<"Sorting is required - ascending order:" << endl;
	sort(d1.begin(), d1.end());
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;

	cout<<"Finding element [5]:" << endl;
	printMessage(binary_search(d1.begin(), d1.end(), 5), 5);

	cout<<"--------------------------------------------------" << endl;
	cout<<"Searching for element in the collection which is not sorted properly" << endl;
	cout<<"Finding element [5] - assuming descending order of elements:" << endl;
	printMessage(binary_search(d1.begin(), d1.end(), 5, compare), 5); 
	cout<<endl;

	cout<<"--------------------------------------------------" << endl;
	cout<<"Sorting is required - descending order:" << endl;
	sort(d1.begin(), d1.end(), compare);
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;

	cout<<"Finding element  [5]:" << endl;
	printMessage(binary_search(d1.begin(), d1.end(), 5, compare), 5);
	
	return 0;
}
