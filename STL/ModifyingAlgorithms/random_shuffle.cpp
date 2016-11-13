/*
The function random_shuffle() – rearranges elements of the collection in a possible but 
unpredictable order. The first version is completely random, the second one uses the external 
random number generator. In the second case a programmer can influence the exact randomization 
process.
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

int main()
{
	int t[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector <int> v1(t, t+10);
	cout<<"Source collection:" << endl;
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<int>); 
	cout<<endl<<endl;
	
	cout<<"Randomly shuffling elements:" << endl;
	random_shuffle(v1.begin(), v1.end());
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<int>); 
	cout<<endl<<endl;

	cout<<"Randomly shuffling elements - again:" << endl;
	random_shuffle(v1.begin(), v1.end());
	cout<<"v1: "; 
	for_each(v1.begin(), v1.end(), print<int>); 
	cout<<endl<<endl;

	return 0;
}