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
#include <iterator>

using namespace std;

template<class T>
void print(const T & value) 
{
	cout<<value<<" ";
}

int main()
{
	int t[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	list<int> l1(t, t+10);
	cout<<"Source collection:" << endl;
	cout<<"l1: "; 
	for_each(l1.begin(), l1.end(), print<int>); 
	cout<<endl<<endl;
	
	cout<<"Rotating elements - putting 3 on top:" << endl;
	list<int>::iterator it = l1.begin();
	advance(it,2);
	rotate(l1.begin(), it, l1.end());
	cout<<"Collection after rotate" << endl;
	cout<<"l1: "; 
	for_each(l1.begin(), l1.end(), print<int>); 
	cout<<endl<<endl;

	cout<<"Rotating elements - putting 7 on top:" << endl;
	it = l1.begin();
	advance(it,4);
	rotate(l1.begin(), it, l1.end());
	cout<<"Collection after rotate" << endl;
	cout<<"l1: "; 
	for_each(l1.begin(), l1.end(), print<int>); 
	cout<<endl<<endl;

	return 0;
}