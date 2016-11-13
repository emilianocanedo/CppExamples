/*
transform() applies given predicates (unary_op or binary_op) to elements of the collection 
or collections and store results in another collection. The first version of transform calls 
unary_op for each of the elements from the first range and the result of such a call is stored 
in consecutive elements of the result  d_first range. The second version is working in a similar 
manner, but it takes as arguments elements from two collections (ranges), and after applying a 
given operation binary_op also stores result in the range d_first.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

template<class T>
void print(const T& value)
{
	cout << value << " ";
}

struct Add
{
    int _v;
    Add(int v): _v(v){}
    int operator()(int a)
    {
        return a + _v;
    }
};

struct Averange
{
    double operator()(const int& a, const int& b)
    {
        return (a+b)/2.0;
    }
};

int main()
{
    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> v1(t, t+10);
    list<int> l1(v1.size());
    cout << "Source collection:" << endl;
    cout << "v1: ";
    for_each(v1.begin(), v1.end(), print<int>);
    cout << endl << endl;
    
    cout << "Adding value - 10 to all elements of the collection:" << endl;
    transform(v1.begin(), v1.end(), l1.begin(), Add(10));
    cout << "l1: ";
    for_each(l1.begin(), l1.end(), print<int>);
    cout << endl << endl;

    cout << "Adding value - 10 storing result in the same collection:" << endl;
    transform(v1.begin(), v1.end(), v1.begin(), Add(10));
    cout << "v1: ";
    for_each(v1.begin(), v1.end(), print<int>);
    cout << endl << endl;
    
    cout << "Calculating average of elements from two collections:" << endl;
    list<float> l2(l1.size());
    transform(v1.begin(), v1.end(), l1.rbegin(), l2.begin(), Averange());
    cout << "l2: ";
    for_each(l2.begin(), l2.end(), print<float>);
    cout << endl << endl;

    return 0;
}
