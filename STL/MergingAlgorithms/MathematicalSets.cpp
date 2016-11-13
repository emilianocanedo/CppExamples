/*
Function set_XXX is a family of the following set algorithms:

    union – set_union(),
    intersection – set_intersection(),
    difference – set_difference(),
    symmetric difference – set_symmetric_difference().

These operations are performed in a mathematical sense of the set concept. All set_XXX functions 
have exactly the same signature, which allows for describing them together. These operations are 
not related or bound to the STL container set and they can be performed on any two sorted ranges 
of elements. The result is stored in the third range which starts with iterator d_first. It is also 
important to remember that input and output ranges cannot overlap. All set functions have two 
versions; the first version assumes that the input ranges were sorted using operator less, the 
second version assumes that they were sorted with the help of the external comparison function comp.

set_union()
Combines two input ranges in such a way that all elements from both ranges are stored inside the 
output range. Relative order of elements is preserved. If an element is found m times in [first1, last1) 
d n times in [first2, last2), then all m elements will be copied from [first1, last1) to d_first, 
preserving the order, and then exactly std::max(n-m, 0) elements will be copied from [first2, last2) 
to d_first, also preserving the order.

set_intersection()
Constructs a sorted range beginning at d_first consisting of elements that are found in both sorted 
ranges [first1, last1) and [first2, last2). The first version expects both input ranges to be sorted 
with operator less, the second version expects them to be sorted with the given comparison function 
comp. If an element is found m times in [first1, last1) and n times in [first2, last2), the first 
std::min(m, n) element will be copied from the first range to the destination range. The order of 
equivalent elements is preserved.

set_difference()
Copies the elements from the sorted range [first1, last1) which are not found in the sorted range 
[first2, last2) to the range beginning at d_first. The resulting range is also sorted. The first 
version expects both input ranges to be sorted with operator less, the second version expects them 
to be sorted with the given comparison function comp. Equivalent elements are treated individually, 
that is, if an element is found m times in [first1, last1) and n times in [first2, last2), it will 
be copied to d_first exactly std::min(m-n, 0) times.

set_symetric_difference()
Copies the elements from the sorted range [first1, last1) which are not found in the sorted range 
[first2, last2) and the elements from the sorted range [first2, last2) which are not found in the 
sorted range [first1, last1) to the range beginning at d_first. The resulting range is also sorted. 
The first version expects both input ranges to be sorted with operator less, the second version 
expects them to be sorted with the given comparison function comp. If an element is found m times 
in [first1, last1) and n times in [first2, last2), it will be copied to d_first exactly std::abs(m-n) 
times. If m>n, then the last m-n of those elements are copied from [first1,last1); otherwise the 
last n-m elements are copied from [first2,last2). 
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


int main()
{
	int t1[]={1, 10, 3, 4, 6, 8, 9, 2, 5, 7};
	int t2[]={8, 4, 5, 0};
	deque <int> d1(t1,t1+10);
	deque <int> d2(t2,t2+4);
	deque <int> d3(d1.size()+d2.size());

	cout<<"Source collections:" << endl;
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;
	cout<<"d2: "; 	
	print(d2.begin(), d2.end());
	cout<<endl;

	cout<<"Trying to perform set_intersection - with not sorted collections:" << endl; 
	//visual studio might rise an exception in debug mode
	deque<int>::iterator resultEnd = set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin());
	cout<<"d3: "; 	
	print(d3.begin(), resultEnd);
	cout<<endl<<endl;

	cout<<"Sorting is required - ascending order:" << endl;
	sort(d1.begin(), d1.end()); sort(d2.begin(), d2.end());
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;
	cout<<"d2: "; 	
	print(d2.begin(), d2.end());
	cout<<endl;

	cout<<"set operations:" << endl;
	resultEnd = set_union(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin());
	cout<<"union: "; 
	print(d3.begin(), resultEnd);
	cout<<endl;
	resultEnd = set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin());
	cout<<"intersection: "; 
	print(d3.begin(), resultEnd);
	cout<<endl;
	resultEnd = set_difference(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin());
	cout<<"difference: "; 
	print(d3.begin(), resultEnd);
	cout<<endl;
	resultEnd = set_symmetric_difference(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin());
	cout<<"symmetric difference: "; 
	print(d3.begin(), resultEnd);
	cout<<endl<<endl;

	cout<<"Sorting is required - descending order:" << endl;
	sort(d1.begin(), d1.end(), compare); sort(d2.begin(), d2.end(), compare);
	cout<<"d1: "; 	
	print(d1.begin(), d1.end());
	cout<<endl;
	cout<<"d2: "; 	
	print(d2.begin(), d2.end());
	cout<<endl;

	cout<<"set operations:" << endl;
	resultEnd = set_union(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin(), compare);
	cout<<"union: "; 
	print(d3.begin(), resultEnd);
	cout<<endl;
	resultEnd = set_intersection(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin(), compare);
	cout<<"intersection: "; 
	print(d3.begin(), resultEnd);
	cout<<endl;
	resultEnd = set_difference(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin(), compare);
	cout<<"difference: "; 
	print(d3.begin(), resultEnd);
	cout<<endl;
	resultEnd = set_symmetric_difference(d1.begin(), d1.end(), d2.begin(), d2.end(), d3.begin(), compare);
	cout<<"symmetric difference: "; 
	print(d3.begin(), resultEnd);
	cout<<endl<<endl;
	
	return 0;
}