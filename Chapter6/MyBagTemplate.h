#pragma once
#include<iostream>
#include <algorithm>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string options);
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt);

//precondition: going to create a class that is Template
//postcondition: going to pass in get the T data (template class), allocate and deallocate, two variabels size and capacity
//Template class MyBag for dynamic array
template<typename T>
class MyBagTemplate{
private:
	T* data;
	int size;
	int capacity;
public:
	// Functions to interact with the bag
	void add(double value);
	void clear();
	bool contains(double value) const;
	void ensureCapacity(int newCapacity);

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

	//member function to get the menu option
	void menuInformation();
};
