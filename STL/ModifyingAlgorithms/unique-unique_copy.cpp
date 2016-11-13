/*
The functions unique() and unique_copy() remove duplicated consecutive elements from the 
source range of elements. By doing so, they create a new and shorter version of range of 
elements, and they both return the end (past-the-end element) to it. The difference is 
that unique() stores this collection in the source collection [first, last), whereas 
unique_copy() saves it in the output range which starts with d_first().
Duplicates are found by comparing consecutive elements:

    using the equality operator (==),
    using the provided predicate p.

Please remember that only consecutive duplicates will be removed.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template<class T>
void print(const T& value) 
{
	cout<<value<<" ";
}

struct Equal
{
	//elements are equal if they are both odd or even
	bool operator()(const int& a, const int& b)
	{
		return a % 2 == b % 2;
	}
};

int main()
{
	int t[]={1, 1, 2, 3, 3, 1, 6, 7, 8, 2};
	list <int> l1(t, t+10);
	cout<<"Source collection:\n";
	cout<<"l1: "; 
	for_each(l1.begin(), l1.end(), print<int>); 
	cout<<endl<<endl;
	
	cout<<"Removing duplicate values - copy version:\n";
	vector<int> v1(l1.size());
	vector<int>::iterator newEnd = unique_copy(l1.begin(), l1.end(), v1.begin());
	cout<<"Collection after removal - size did not change!:\n";
	cout<<"l1: "; 
	for_each(l1.begin(), l1.end(), print<int>); 
	cout<<endl;
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<int>); 
	cout<<endl;
	cout<<"Displaying only valid elements:\n";
	cout<<"v1: "; 
	for_each(v1.begin(), newEnd, print<int>); 
	cout<<endl<<endl;

	cout<<"Removing duplicate values:\n";
	list<int>::iterator newEnd1 = unique(l1.begin(), l1.end());
	cout<<"Collection after removal - size did not change!:\n";
	cout<<"l1: "; 
	for_each(l1.begin(), l1.end(), print<int>); 
	cout<<endl;
	cout<<"Displaying only valid elements:\n";
	cout<<"l1: "; 
	for_each(l1.begin(), newEnd1, print<int>); 
	cout<<endl<<endl;

	cout<<"------------------------------------------------\n";
	cout<<"Predicate versions:\n";
	int t1[]={1, 3, 2, 4, 5, 6, 7, 9, 8, 10};
	list <int> l2(t1, t1+10);
	cout<<"Source collection:\n";
	cout<<"l2: "; 
	for_each(l2.begin(), l2.end(), print<int>); 
	cout<<endl<<endl;
	
	cout<<"Removing duplicate values - copy version:\n";
	vector <int> v2(l2.size());
	vector<int>::iterator newEnd2 = unique_copy(l2.begin(), l2.end(), v2.begin(), Equal());
	cout<<"Collection after removal - size did not change!:\n";
	cout<<"l2: "; 
	for_each(l2.begin(), l2.end(), print<int>); 
	cout<<endl;
	cout<<"v2: "; 
	for_each(v2.begin(), v2.end(), print<int>); 
	cout<<endl;
	cout<<"Displaying only valid elements:\n";
	cout<<"v2: "; 
	for_each(v2.begin(), newEnd2, print<int>); 
	cout<<endl<<endl;

	cout<<"Removing duplicate values:\n";
	list<int>::iterator newEnd3 = unique(l2.begin(), l2.end(), Equal());
	cout<<"Collection after removal - size did not change!:\n";
	cout<<"l2: "; 
	for_each(l2.begin(), l2.end(), print<int>); 
	cout<<endl;
	cout<<"Displaying only valid elements:\n";
	cout<<"l2: "; 
	for_each(l2.begin(), newEnd3, print<int>); 
	cout<<endl<<endl;

	return 0;
}