/*
Function min returns the smaller of the two values. Function max returns the greater of the two 
values. Both functions have two versions. The first version uses operator less for  the comparison 
of elements, the second version uses the given comparison function comp instead.

Function min_element() returns the smallest element in the given range of elements. Function 
max_element() returns the greatest element in the given range of elements. If there is more than 
one min/max value,  the first found is always returned. Both functions have two versions. The 
first version uses operator less for the comparison of elements, the second version uses the given 
comparison function comp instead.
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

int main()
{
	int t1[]={1, 10, 3, 4, 6, 8, 9, 2, 5, 7};
	
	deque <int> d1(t1,t1+10);
	cout<<"Min/Max element:" << endl;
	cout<<"min: "<< min(4,3)<<endl;
	cout<<"max: "<< max(4,3)<<endl<<endl;

	cout<<"Min and max element:" << endl;
	cout<<"Source collections:" << endl;
	cout<<"d1: "; 
	print(d1.begin(), d1.end());
	cout<<endl;
	cout<<"Finding min element of the collection d1: "<< *(min_element(d1.begin(), d1.end()))<<endl;
	cout<<"Finding max element of the collection d1: "<< *(max_element(d1.begin(), d1.end()))<<endl;
	
	return 0;
}