/*
The functions reverse() and reverse_copy() reverse the order of the elements in the source range 
[first, last). The first range performs the reversal in place, which means that the source range 
is affected. The second version – reverse_copy() does not affect the source range, but copies its 
elements to the destination range in a reversed order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template<class T>
void print(const T & value) 
{
	cout<<value<<" ";
}

int main()
{
	int t[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	list <int> l1(t, t+10);
	cout<<"Source collection:" << endl;
	cout<<"l1: "; 
	for_each(l1.begin(), l1.end(), print<int>); 
	cout<<endl<<endl;
	
	cout<<"Reversing order - copy version:" << endl;
	vector <int> v1(l1.size());
	reverse_copy(l1.begin(), l1.end(), v1.begin());
	cout<<"Collections after reversal" << endl;
	cout<<"l1: "; 
	for_each(l1.begin(), l1.end(), print<int>); 
	cout<<endl;
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<int>); 
	cout<<endl<<endl;

	cout<<"Reversing order:" << endl;
	reverse(l1.begin(), l1.end());
	cout<<"Collection after reversal:" << endl;
	cout<<"l1: "; 
	for_each(l1.begin(), l1.end(), print<int>); 
	cout<<endl;

	return 0;
}