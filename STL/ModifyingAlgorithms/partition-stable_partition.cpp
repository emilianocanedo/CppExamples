/*
The functions partition() and stable_partition() reorganize elements of the collection in 
such a way that all elements for which predicate p returns true will precede all those for 
which p returns false. It means that the elements will be divided into two ranges:

    [first, return_value),
    [return_value, last),

where return_value is the iterator returned by either of functions.

The sequence of elements in the resulting groups is where partition() and stable_partition() 
differ. The first function does not guarantee any particular order within the ranges; the 
second one will keep a relative order of elements before the split. It means that if there 
are two elements a and b, and a precedes b, and if they both belong to the same group after 
the split, element a will still precede element b.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<class T>
void print(const T& value) 
{
	cout<<value<<" ";
}

struct Pred
{
	int value;
	Pred(const int & v):value(v){}
	bool operator()(const int & a)
	{
		return a < value;
	}
};

int main()
{
	int t[]={1, 10, 8, 4, 5, 6, 7, 3, 9, 2};
	vector<int> v1(t, t+10);
	cout<<"Source collection:" << endl;
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<int>); 
	cout<<endl<<endl;
	
	cout<<"Normal partitioning:" << endl;
	vector<int>::iterator it = partition(v1.begin(), v1.end(), Pred(5));
	cout<<"Partitioning into two groups: < 5 and > 5:" << endl;
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<int>); 
	cout<<endl;
	cout<<"The first group: "; 
	for_each(v1.begin(), it, print<int>); 
	cout<<endl;
	cout<<"The second group: "; 
	for_each(it, v1.end(), print<int>); 
	cout<<endl<<endl;

	cout<<"Stable partitioning:" << endl;
	copy(t, t+10, v1.begin()); //reinitializing collection;
	it = stable_partition(v1.begin(), v1.end(), Pred(5));
	cout<<"Partitioning into two groups: < 5 and > 5:" << endl;
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<int>); 
	cout<<endl;
	cout<<"The first group: "; 
	for_each(v1.begin(), it, print<int>); 
	cout<<endl;
	cout<<"The second group: "; 
	for_each(it, v1.end(), print<int>); 
	cout<<endl;

	return 0;
}