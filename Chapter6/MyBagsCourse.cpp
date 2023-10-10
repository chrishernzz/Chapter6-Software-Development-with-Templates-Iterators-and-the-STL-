#include "MyBagsCourse.h"

//precondition: scope class and calling my default constructor and intializing
//postcondition: going to pass in the Course class
MyBagsCourse::MyBagsCourse(){
    //call the student default constructor
    //if there are no size avaiable there, then default
    Course defaultCon;
}
//precondition:
//postcondition:
void MyBagsCourse::specifyNumberCourses(Course courses){
	data.push_back(courses);
}
//precondition:
//postcondition: 
void MyBagsCourse::readFromFile(string& fileName){
	ifstream readFile;
	string courseName, name,idNumber,gradeScore;
	char studentGrade;
	Course courseInformation;
	//open file to read
	readFile.open(fileName);
	//checking if the file exits, if not then error
	if (readFile.fail()) {
		cout << "\n\t\t\tERROR: file, " << fileName << " cannot be found.Please re - specify.";
		cout << "\n\n";
		system("pause");
		system("cls");
		return;
	}/*
	if (fileName == "STOP") {
		break;
	}*/

	//while it is not the end of hte file
	while (!readFile.fail()) {
		//read until there is a comma encounter
		getline(readFile, courseName);
		courseInformation.setCourseName(courseName);
		getline(readFile, idNumber, ',');
		courseInformation.setIDNumber(stoi(idNumber));
		getline(readFile, name, ',');
		courseInformation.setName(name);
		getline(readFile, gradeScore);
		courseInformation.setGradeScore(stod(gradeScore));
		//end of file, then don't push_back an extra element
		if (readFile.eof()) {
			break;
		}
		//push back the elements you read (getting the setters)
		data.push_back(courseInformation);
	}
	cout << "\n\t\t\tData from file, " << fileName << " has been read and stored into Course[0].";
	for (int i = 0; i < data.size(); i++) {
		cout << "\t\t[" << i << "]: " << data[i] << endl;
	}

	cout <<"\n\n";
	system("pause");
	system("cls");
}

//precondition: going to print the information
//postcondition: going to create a menu that accepts 
void MyBagsCourse::menuInformation(){
    system("cls");
    int option;
	do {
	beginning:
		cout << "\n\t\t3) Courses using MyBags of integers, strings, doubles, and chars";
		cout << "\n\t\t" << string(82, char(205));
		cout << "\n\t\t\t1> Specify the number of courses";
		cout << "\n\t\t\t2> Read in data file and insert into courses";
		cout << "\n\t\t\t3> Search for a student record from a course";
		cout << "\n\t\t\t4> Remove a student record from a course";
		cout << "\n\t\t\t5> Display course(s)";
		cout << "\n\t\t" << string(82, char(205));
		cout << "\n\t\t\t0> return";
		cout << "\n\t\t" << string(82, char(205)) << "\n";
		option = inputInteger("\t\t\tOption: ", 0, 5);

		switch (option) {
		case 1: {
			int courses = inputInteger("\n\t\t\tEnter the number of courses: ");
			//specifyNumberCourses(courses);

		}
			  break;
		case 2: {
			string fileName;
			cout << "\n\t\t\tEnter a data file name for course[0] (STOP - return): ";
			cin >> fileName;
			readFromFile(fileName);
			
		}
			  break;
		case 3: {
			int choice;
			do {
				cout << "\n\t\tSearch by";
				cout << "\n\t\t" << string(25, char(205));
				cout << "\n\t\t\t1. ID Number";
				cout << "\n\t\t\t2. Name";
				cout << "\n\t\t\t0. return";
				choice = inputInteger("\n\t\tOption: ", 0, 2);
				switch (choice) {
				case 1: {

				}
					  break;
				case 2: {

				}
					  break;
				case 0: {
					goto beginning;
				}
				}
			} while (true);
		}
			  break;
		case 4: {

		}
			  break;
		case 5: {
			/*int choice;
			do {

				cout << "\n\t\tCourse(s)";
				cout << "\n\t\t" << string(25, char(205));
				cout << "\n\t\t\t1. ID Number";
				cout << "\n\t\t\t2. Name";
				cout << "\n\t\t\t0. return";
				choice = inputInteger("\n\t\tOption: ", 0, 2);



			} while (true);*/
		}
			  break;
		case 0: {
			return;
		}
		}
	} while (true);
}
