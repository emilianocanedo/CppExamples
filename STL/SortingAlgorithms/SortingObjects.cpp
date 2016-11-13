/*
The key problem with sorting utilization is implementation of comparision (cmp) function. 
This example shows sorting of complex objects. Worthy of note is the fact that the parameters 
are passed by reference
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctype.h>
#include <string>

using namespace std;

class Something
{
	public:
		int first_key, second_key;
		string value;
		Something(int first_key, int second_key, string value):first_key(first_key), second_key(second_key), value(value){}
		Something(){}
};

void print(const Something& v) 
{
	cout<<v.value<<" ";
}

bool descending_one_key(const Something& a, const Something& b)
{
	return a.first_key < b.first_key;
}

bool descending_keys_sum(const Something& a, const Something& b)
{
	return a.first_key+a.second_key < b.first_key+b.second_key;
}

int main()
{
	vector <Something> v(5);
	v.push_back(Something(1,1,"One"));
	v.push_back(Something(2,2,"Two"));
	v.push_back(Something(4,4,"Four"));
	v.push_back(Something(3,0,"Three"));
	v.push_back(Something(5,5,"Five"));
	
	cout<<"Source collection:" << endl;
	cout<<"v: "; 
	for_each(v.begin(), v.end(), print); 
	cout<<endl;

	cout<<"Sorting in descending order:" << endl;
	
	cout<<"Stable sort:" << endl;
	stable_sort(v.begin(), v.end(), descending_one_key);
	cout<<"v: "; 
	for_each(v.begin(), v.end(), print); 
	cout<<endl;

	cout<<"Normal sort:" << endl;
	sort(v.begin(), v.end(), descending_keys_sum);
	cout<<"v: "; 
	for_each(v.begin(), v.end(), print); 
	cout<<endl<<endl;

	return 0;
}