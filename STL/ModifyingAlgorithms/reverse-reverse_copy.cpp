/*
The function rotate() rotates the range left. It means that rotate() moves all the elements 
in range left in such a manner that the element pointed to by n_first, will become the first 
element of that range. All elements which preceded element n_first will still be located in 
that range and element d_first-1 will become the new last element.
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