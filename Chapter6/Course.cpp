#include "Course.h"

//precondition: going to call my defaults constructor
//postcondition: going to initialize the name (string)
Course::Course(const string& courseName): name(courseName){}

//precondition: going to get the name 
//postcondition: going to return the private name
const string& Course::getName() const{
	return name;
}
//precondition: going to get the new name
//postcondition: going to set the private name with the new name member
void Course::setName(const string newName){
	name = newName;
}

char Course::calculateGrade(double score){
	if (score >= 90.0) return 'A';
	else if (score >= 80.0) return 'B';
	else if (score >= 70.0) return 'C';
	else if (score >= 60.0) return 'D';
	else return 'F';
	
}

int Course::getNumStudents() const {
	return studentIDs.getSize();
}

const MyBagTemplate<int>& Course::getStudentIDs() const{
	return studentIDs;
}

void Course::addStudent(int ID, const string& name, double score){
	studentIDs.insertMyBag(ID);
	studentNames.insertMyBag(name);
	studentScores.insertMyBag(score);
	studentGrades.insertMyBag(calculateGrade(score));
}

bool Course::removeStudent(int ID){
    if (studentIDs.searchMyBag(ID))
    {
        int index = studentIDs.getSize() - 1;
        while (studentIDs[index] != ID)
        {
            index--;
        }

        studentIDs[index] = studentIDs[studentIDs.getSize() - 1];
        studentNames[index] = studentNames[studentNames.getSize() - 1];
        studentScores[index] = studentScores[studentScores.getSize() - 1];
        studentGrades[index] = studentGrades[studentGrades.getSize() - 1];

        studentIDs.setSize(studentIDs.getSize() - 1);
        studentNames.setSize(studentNames.getSize() - 1);
        studentScores.setSize(studentScores.getSize() - 1);
        studentGrades.setSize(studentGrades.getSize() - 1);

        return true;
    }
    return false;
}

void Course::displayCourse(){
	double sum = 0.0;
	double average = 0.0;
    cout << "\n\t\t\t" << name;
    cout << "\n\t\t\tindex    StudentID                      Name    Score   Grade";
    for (int i = 0; i < studentIDs.getSize(); i++)
    {
        cout << "\n\t\t\t    " << i << "        " << studentIDs[i] << "                 " << studentNames[i] << "     " << right << setw(4) << studentScores[i] << "   " << studentGrades[i];
		//getting the total of the scores
		sum += studentScores[i];
    }
	//get the total and divide it by the students
	average = sum / studentIDs.getSize();
	cout << "\n\n\t\t\tAverage score and grade: " << average <<"("<<calculateGrade(average)<<")";
    cout << '\n';
}
//precondition: going to print the information
//postcondition: going to create a menu that accepts 
void Course::menuInformation(){
    system("cls");
    int option;
    vector <Course> courses;
	int numCourses = 0;
	string fileName = "";

	do
	{
		system("cls");
		cout << "\n\t\t 3) Courses using MyBags of integers, strings, doubles, and chars";
		cout << "\n\t\t" << string(70, char(196));
		cout << "\n\t\t\t1> Specify the number of courses";
		cout << "\n\t\t\t2> Read in data file and insert into courses";
		cout << "\n\t\t\t3> Search for a student record from a course";
		cout << "\n\t\t\t4> Remove a student record from a course";
		cout << "\n\t\t\t5> Display course(s)";
		cout << "\n\t\t\t0> Return";
		cout << "\n\t\t" << string(70, char(196));
		option = inputInteger("\n\t\t\tOption: ",0, 5);

		switch (option)
		{
		case 1:{
			numCourses = inputInteger("\n\t\t\t1> Enter the number of courses: ", true);
			courses.clear();
			courses.reserve(numCourses);
			cout << "\n\t\t\t" << numCourses << " Course(s) has been created.\n";
		}
			  break;
		case 2:{
			if (numCourses == 0){
				cout << "\n\t\t\tERROR: number of courses has not been assigned.\n";
				break;
			}
			for (int i = 0; i < numCourses; i++){
				while (true){
					cout << "\n\t\t\t2> Enter a data file name for course [" << i << "] (STOP - return): ";
					cin >> fileName;
					if (fileName == "STOP" || fileName == "stop") {
						break;
					}
					ifstream file;
					//open the file
					file.open(fileName);
					//if the file does not exists
					if (file.fail()){
						cout << "\n\t\t\tERROR: file, " + fileName + ", cannot be found. Please re-specify..\n";
						continue;
					}
					else{
						string course_name;
						getline(file, course_name);
						courses.push_back(Course(course_name));

						string id;
						string name;
						double score;

						while (!file.eof()){
							getline(file, id, ',');
							getline(file, name, ',');
							file >> score;
							int ID = stoi(id);
							courses[i].addStudent(ID, name, score);
						}
						break;
					}
				}
				cout << "\n\t\t\tData from file, " + fileName + ", has been read and stored into Courses[" + to_string(i) + "].\n";
			}
		}
			  break;
		case 3:{

		}
			  break;
		case 4: {
		}
			  break;
		case 5:{
			/*if (numCourses == 0){
				cout << "\n\t\t\tERROR: number of courses has not been assigned.\n";
				break;
			}*/
			//if file is empty
			if (courses.empty()){
				cout << "\n\t\t\tERROR: No data file has been read and stored into Courses.\n";
				break;
			}

			cout << "\n\n\t\t\tCourse(s)";
			cout << "\n\t\t\t" << string(70, char(196));
			cout << "\n\t\t\t1. Display individual course";
			cout << "\n\t\t\t2. Display all courses";
			cout << "\n\t\t\t" << string(70, char(196));

			switch (inputInteger("\n\t\t\tOption: ", 1, 2)){
			case 1:{
				int size = courses.size() - 1;
				// Display individual course
				int courseIndex = inputInteger("\n\t\t\tEnter the index of the course to display: ", 0, size);
				if (courseIndex >= 0 && courseIndex < courses.size()){
					courses[courseIndex].displayCourse();
				}
			}
				  break;
			case 2:{
				for (size_t i = 0; i < courses.size(); i++){
					courses[i].displayCourse();
					cout << endl;
				}
			}
				  break;
			}
		}
			  break;
		case 0: {
			return;
		}
		}
		cout << "\n";
		system("pause");
	} while (true);
}







