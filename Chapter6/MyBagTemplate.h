#pragma once
#include<iostream>
#include <algorithm>
using namespace std;

//Template class MyBag for dynamic array
template<typename T>
class MyBagTemplate{
private:
	T* data;
	int size;
	int capacity;
public:
	//defualt constructor
	MyBagTemplate();
	//constructor
	MyBagTemplate(int newCapacity);
	//destructor
	~MyBagTemplate();

	//getters(accesors)
	int getSize() const;
	//int getCapacity() const;

	//setters(mutators)
	void setSize(int newSize);
	//void setCapacity(int newCapacity);

	//member functions to clear, insert, search, remove, sort, and display
	void clearMyBag();
	void insertMyBag(const T& insert);
	bool searchMyBag(const T& search) const;
	bool removeMyBag(const T& remove);
	void sortMyBag();

	//overloading operators
	bool operator<(const MyBagTemplate<T>& obj)const;
	T& operator[](int index);
	const T& operator[](size_t index) const;
	friend ostream& operator<<(ostream& out, const MyBagTemplate<T>& bag);

};
