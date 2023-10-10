#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"Course.h"
using namespace std;
//input (1) header files inputs validation
char inputChar(string prompt, string lookup);
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);
double inputDouble(string prompt, double startRange, double endRange);

class MyBagsCourse{
private:
	vector<Course> data;
public:
	MyBagsCourse();

	//member functions to specify the course, read file, search student record, remove student record, display course 
	void specifyNumberCourses(Course courses);
	void readFromFile(string& fileName);
	void searchStudentRecordIdNumber();
	void searchStudentRecordName();
	void removeStudentRecord();
	void displayCourses();

	//member function to get the menu option
	void menuInformation();
};

