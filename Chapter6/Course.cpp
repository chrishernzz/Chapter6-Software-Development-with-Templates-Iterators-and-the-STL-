//#include "Course.h"
//////precondition:
//////postcondition:
////Course::Course():courseName("unknown"), name("unknown"), IDNumber(0), gradeScore(0.0), studentGrade('F') {}
////
//////precondition:
//////postcondition:
////void Course::setCourseName(string newCourseName){
////	courseName = newCourseName;
////}
//////precondition:
//////postcondition:
////void Course::setName(string newName){
////	name = newName;
////}
//////precondition:
//////postcondition:
////void Course::setIDNumber(int newIDNumber) {
////	IDNumber = newIDNumber;
////}
//////precondition:
//////postcondition:
////void Course::setGradeScore(double newGradeScore) {
////	gradeScore = newGradeScore;
////}
//////precondition:
//////postcondition:
////void Course::setStudentGrade(char newStudentGrade){
////	studentGrade = newStudentGrade;
////}
//////precondition:
//////postcondition:
//ostream& operator <<(ostream& outs, const Course& obj) {
//	outs << obj.courseName<<"\n";
//	outs << obj.IDNumber << ", " << obj.name << ", " << obj.gradeScore <<", "<<obj.studentGrade;
//	return outs;
//}
////precondition:
////postcondition:
//bool operator<(const Course& obj1, const Course& obj2){
//	if (obj1.name < obj2.name)
//		return true;
//	else
//		return false;
//}


////precondition: going to print the information
////postcondition: going to create a menu that accepts 
//void Course::menuInformation() {
//	system("cls");
//	int option;
//	do {
//	beginning:
//		cout << "\n\t\t3) Courses using MyBags of integers, strings, doubles, and chars";
//		cout << "\n\t\t" << string(82, char(205));
//		cout << "\n\t\t\t1> Specify the number of courses";
//		cout << "\n\t\t\t2> Read in data file and insert into courses";
//		cout << "\n\t\t\t3> Search for a student record from a course";
//		cout << "\n\t\t\t4> Remove a student record from a course";
//		cout << "\n\t\t\t5> Display course(s)";
//		cout << "\n\t\t" << string(82, char(205));
//		cout << "\n\t\t\t0> return";
//		cout << "\n\t\t" << string(82, char(205)) << "\n";
//		option = inputInteger("\t\t\tOption: ", 0, 5);
//
//		switch (option) {
//		case 1: {
//			int courses = inputInteger("\n\t\t\tEnter the number of courses: ");
//			//specifyNumberCourses(courses);
//
//		}
//			  break;
//		case 2: {
//			string fileName;
//			cout << "\n\t\t\tEnter a data file name for course[0] (STOP - return): ";
//			cin >> fileName;
//			//readFromFile(fileName);
//
//		}
//			  break;
//		case 3: {
//			int choice;
//			do {
//				cout << "\n\t\tSearch by";
//				cout << "\n\t\t" << string(25, char(205));
//				cout << "\n\t\t\t1. ID Number";
//				cout << "\n\t\t\t2. Name";
//				cout << "\n\t\t\t0. return";
//				choice = inputInteger("\n\t\tOption: ", 0, 2);
//				switch (choice) {
//				case 1: {
//
//				}
//					  break;
//				case 2: {
//
//				}
//					  break;
//				case 0: {
//					goto beginning;
//				}
//				}
//			} while (true);
//		}
//			  break;
//		case 4: {
//
//		}
//			  break;
//		case 5: {
//			/*int choice;
//			do {
//				cout << "\n\t\tCourse(s)";
//				cout << "\n\t\t" << string(25, char(205));
//				cout << "\n\t\t\t1. ID Number";
//				cout << "\n\t\t\t2. Name";
//				cout << "\n\t\t\t0. return";
//				choice = inputInteger("\n\t\tOption: ", 0, 2);
//			} while (true);*/
//		}
//			  break;
//		case 0: {
//			return;
//		}
//		}
//	} while (true);
//}
//
//
//
