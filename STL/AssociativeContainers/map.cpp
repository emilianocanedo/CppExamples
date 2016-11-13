/*
Map and multimap are associative containers in which elements stored inside them are composed of 
two parts:

    key – which is used in association
    mapped value – value which is associated with the key.

Each element is identified by its key. Key is used to retrieve or access the mapped value inside 
the map. Such access is very useful, for example you might want to build a structure in which you 
associate a person’s name with its data record. As you can see in the map template definition, 
the key and the mapped value do not have to be of the same type, which is a very useful feature.
*/

#include <map>
#include <iostream>
#include <functional>

using namespace std;

template<class T>
void print(T start, T end)
{
	while (start != end) {
		cout << start->first << ":" << start->second << " ";
		start++;
	}
}

template<class T, class U>
void fillMap(map<T, T>& m, U start, U end)
{
	for (; start != end; ++start)
		m.insert(pair<T, T>(*start, *start));
}

template<class T, class U>
void fillMultimap(multimap<T, T>& m, U start, U end)
{
	for (; start != end; ++start)
		m.insert(pair<T, T>(*start, *start));
}

void check(const pair<map<int, int>::iterator, bool>& result)
{
	if (result.second == true)
		cout << "A new key value (" << result.first->first << ") has been inserted" << endl;
	else
		cout << "Insertion failed, key " << result.first->first << " already exists" << endl;
}

int main()
{
	int t[] = {45, 67, 89, 54, 90, 78, 32, 23};

	//default constructor
	map<int, int> m1;
	fillMap(m1, t, t+8);

	//iterator constructor
	map<int, int> m2(m1.begin(), m1.end());

	//copy constructor
	map<int, int> m3(m2);

	//different comparator
	map<int, int, greater<int> > m4(m3.begin(), m3.end());

	//assignement
	map<int, int, greater<int> > m5;
	m5 = m4;

	//multimap
	multimap<int, int> multi;
	fillMultimap(multi, t, t+8);

	cout << "print a map with default comparator (m3)" << endl;
	print(m3.begin(), m3.end());
	cout << endl << endl;

	cout << "print a map with other comparator (m5)" << endl;
	print(m5.begin(), m5.end());
	cout << endl << endl;

	cout << "print a map with default comparator with reverse iterator (m3)" << endl;
	print(m3.rbegin(), m3.rend());
	cout << endl << endl;

	cout << "m3 is empty?" << endl;
	cout << (m3.empty() ? "true" : "false") << endl << endl; 

	cout << "m3 size and max_size" << endl;
	cout << m3.size() << " " << m3.max_size() << endl << endl;

	cout << "access to key '89' in m3 by [] (no multimap)" << endl;
	cout << m3[89] << endl << endl;
	
	cout << "CAUTION: if an element with key x cannot be found inside the map, the container will create an element with such a key" << endl;
	cout << m3[666] << endl;
	print(m3.rbegin(), m3.rend());
	cout << endl << endl;
	
	cout << "NEVER use this operator to check if a particular key is stored inside the map. Use either the find() or the count() method..." << endl;
	cout << "find return a pair with the values:" << endl;
	cout << (m3.find(89))->second << endl;
	cout << "count return a boolean:" << endl;
	cout << (m3.count(77) ? "true" : "false") << endl << endl;

	cout << "Insert a duplicate key in m3" << endl;
	pair<map<int, int>::iterator, bool> p = m3.insert(pair<int, int>(89, 77));
	check(p);
	cout << endl;

	cout << "Insert a new key in m3" << endl;
	p = m3.insert(pair<int, int>(404, 77));
	check(p);
	cout << endl;

	cout << "Insert a duplicate key in multimap" << endl;
	multi.insert(pair<int, int>(89, 77));
	print(multi.begin(), multi.end());
	cout << endl << endl;

	cout << "m3 before removes:" << endl;
	print(m3.begin(), m3.end());
	cout << endl;
	cout << "Removing element for a certain position (iterator)" << endl;
	map<int, int>::iterator it = m3.find(404);
	m3.erase(it);
	print(m3.begin(), m3.end());
	cout << endl;
	cout << "Removing certain key value (666) from m3" << endl;
	m3.erase(666);
	print(m3.begin(), m3.end());
	cout << endl;
	cout << "Removing all elements from m3" << endl;
	m3.clear();
	cout << "Size: " << m3.size() << endl << endl;

	return 0;
}