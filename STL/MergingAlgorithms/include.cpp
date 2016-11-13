/*
This functions checks if every element of the second range is present in the first range and if so, 
it will return true.  Both ranges must be sorted for this function to work as expected. The first 
version of the function uses operator less to compare the elements, the second version uses the 
provided external comparison function comp.
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

void printMessage(bool value)
{
	if (value)
	{
		cout<<"Collection d1 contains all elements from collection d2!" << endl;
	}
	else
	{
		cout<<"Collection d1 does not contain all elements from collection d2!" << endl;
	}
}

int main()
{
	int t1[]={1, 10, 3, 4, 6, 8, 9, 2, 5, 7};
	int t2[]={8, 4, 5, 6};
	deque <int> d1(t1,t1+10);
	deque <int> d2(t2,t2+4);

	cout<<"Source collections:" << endl;
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;
	cout<<"d2: "; 	
	print(d2.begin(), d2.end());
	cout<<endl;

	cout<<"Trying to perform lookup with not sorted collections:" << endl; 
	//visual studio might rise an exception in debug mode
	printMessage(includes(d1.begin(), d1.end(), d2.begin(), d2.end())); 
	cout<<endl;

	cout<<"Sorting is required - ascending order:" << endl;
	sort(d1.begin(), d1.end()); sort(d2.begin(), d2.end());
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;
	cout<<"d2: "; 	
	print(d2.begin(), d2.end());
	cout<<endl;
	cout<<"Performing lookup:" << endl;
	printMessage(includes(d1.begin(), d1.end(), d2.begin(), d2.end())); 
	cout<<endl;


	cout<<"Sorting is required - descending order:" << endl;
	sort(d1.begin(), d1.end(), compare); sort(d2.begin(), d2.end(), compare);
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;
	cout<<"d2: "; 	
	print(d2.begin(), d2.end());
	cout<<endl;
	cout<<"Performing lookup:" << endl;
	printMessage(includes(d1.begin(), d1.end(), d2.begin(), d2.end(), compare)); 
	cout<<endl;
	
	return 0;
}