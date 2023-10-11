#pragma once
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, string options);
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);

class MyBag{
private:
	//pointer variable to dynamic array of ints
	vector<int> myBag;
	int* newValue = new int[myBag.size()];
	int size;
	int capacity;
public:
	//defualt constructor
	MyBag();
	//constructor
	MyBag(int newSize, int newCapacity); 
	//deconstructor
	~MyBag();

	//getters(accesors)
	int getSize() const; 
	int getCapacity() const;

	//setters(mutators)
	void setSize(int newSize); 
	void setCapacity(int newCapacity);
	
	//member functions to clear, insert, search, remove, sort, and display
	void clearMyBag();
	void insertMyBag(int *value);
	void searchMyBag(int search);
	void removeMyBag(int remove);
	void sortMyBag();

	void displayMyBag();

	//member function to get the menu option
	void menuInformation(); 
};

