#pragma once
#include "MyBagTemplate.cpp"
#include <string>
#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include <fstream>
using namespace std;

//input (1) header files inputs validation
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);
int inputInteger(string prompt, bool posNeg);
//string inputString(string prompt, bool spaces);

class Course{
private:
    string name;
    MyBagTemplate<int> studentIDs;
    MyBagTemplate<string> studentNames;
    MyBagTemplate<double> studentScores;
    MyBagTemplate<char> studentGrades;
    /*char calculateGrade(double score){
        if (score >= 90.0) return 'A';
        else if (score >= 80.0) return 'B';
        else if (score >= 70.0) return 'C';
        else if (score >= 60.0) return 'D';
        else return 'F';
    }*/
public:
    Course() {};
    //constructor
    Course(const string& courseName);

    //getters(accesors)
    const string& getName() const;
    int getNumStudents() const;
    const MyBagTemplate<int>& getStudentIDs() const;
    const MyBagTemplate<string>& getStudentNames() const;


    //setters(mutators)
    void setName(const string newName);
    char calculateGrade(double score);
    void addStudent(int ID, const string& name, double score);

    //member fucntions
    bool removeStudent(int ID);
    void displayCourse();


    void menuInformation();
};

