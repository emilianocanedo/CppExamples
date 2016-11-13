/*
Functions sort() and stable_sort() sort the elements of the range in an ascending order. 
The elements are compared either using the less operator (<) or using the supplied comparator 
function comp.
sort() function does not guarantee the ordering of elements that are equal. stable_sort() will 
keep a relative order of equal elements after the operation. It means that if there are two 
equal elements a and b and a precedes b, then, after the sorting, element a will still precede 
element b.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctype.h>
#include <string>

using namespace std;

template<class T>
void print(const T & value) 
{
	cout<<value<<" ";
}

char t(char c)
{
	return tolower(c);
}

string toLower(const string & v)
{
	string ret(v);
	transform(ret.begin(), ret.end(), ret.begin(),  t);
	return ret;
}

bool descending_caseinsensitive(const string & a, const string & b)
{
	return toLower(b) < toLower(a);
}

bool descending_casesensitive(const string & a, const string & b)
{
	return b < a;
}

bool ascending_caseinsensitive(const string & a, const string & b)
{
	return toLower(a) < toLower(b);
}


int main()
{
	string t[]={"AB", "dC", "ba", "aB", "BC", "bc", "BA", "cd", "Cd", "ab"};
	vector<string> v1(10);
	
	copy(t, t+10, v1.begin());
	cout<<"Source collection:" << endl;
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<string>); 
	cout<<endl;
	
	cout<<"Sorting in ascending order:" << endl;
	
	cout<<"Normal sort:" << endl;
	sort(v1.begin(), v1.end());
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<string>); 
	cout<<endl;
	
	cout<<"Stable sort:" << endl;
	copy(t, t+10, v1.begin());
	stable_sort(v1.begin(), v1.end(), ascending_caseinsensitive);
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<string>); 
	cout<<endl<<endl;

	cout<<"Sorting in descending order:" << endl;
	
	cout<<"Normal sort:" << endl;
	sort(v1.begin(), v1.end(), descending_casesensitive);
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<string>); 
	cout<<endl;
	
	cout<<"Stable sort:" << endl;
	copy(t, t+10, v1.begin());
	stable_sort(v1.begin(), v1.end(), descending_caseinsensitive);
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<string>); 
	cout<<endl<<endl;

	return 0;
}