#include "MyBag.h"

//precondition: going to call my defaults constructor
//postcondition: going to set the variables to 0 since they are int (initialize them)
MyBag::MyBag(): size(0), capacity(0){}
//precondition: going to call my constructor
//postcondition: going to be allocating new to the newSize and newCapacity with size and capacity
MyBag::MyBag(int newSize, int newCapacity){
	size = newSize;
	capacity = newCapacity;
}
//precondition: going to call my deconstructor
//postcondition: going to deallocate the newValue 
MyBag::~MyBag(){
	newValue = nullptr;
	delete[] newValue;
}

//precondition: going to get the size 
//postcondition: going to return the private size
int MyBag::getSize() const{
	return size;
}
//precondition: going to get the new size
//postcondition: going to set the private size with the new size member
void MyBag::setSize(int newSize){
	size = newSize;
}

//precondition: going to get the capacity 
//postcondition: going to return the private capacity
int MyBag::getCapacity() const{
	return capacity;
}
//precondition: going to get the new capacity
//postcondition: going to set the private capacity with the new sicapacityze member
void MyBag::setCapacity(int newCapacity) {
	capacity = newCapacity;
}

//precondition: going to call the myBag vector
//postcondition: going to then clear the myBag vector (make it empty)
void MyBag::clearMyBag(){
	//check if MyBag is empty, if empty, send a warning
	if (myBag.empty()) {
		cout << "\n\t\t\tMyBag is empty.\n\n";
		system("pause");
		system("cls");
		return;
	}
	myBag.clear();
	cout << "\n\t\t\tMyBag is cleared of all elements.";
	cout << "\n\n";
	system("pause");
	system("cls");
}
//precondition: going to pass in a value as our parameter and its a pointer
//postcondition: going to then use .push_back() to push back the values
void MyBag::insertMyBag(int *value){
	myBag.push_back(*newValue);
	cout << "\n\t\t\t" << *value << " has been inserted into MyBag.";
	cout << "\n\n";
	system("pause");
	system("cls");
}
//precondition: going to pass in a value as our parameter
//postcondition: going to for loop through MyBag size, then search for the index (subscript)
void MyBag::searchMyBag(int search){
	bool found = false;
	//WE NEED TO USE THE SIZE THIS IS JUST TEST CASING
	for (int i = 0; i < myBag.size(); i++) {
		//if statement to check if its equal to it, go through the myBag
		if (myBag.at(i) == search) {
			//flag it to true
			found = true;
			cout << "\n\t\t\tValue " << search << " is found at subscript #" << i << " from MyBag.";
		}
	}
	//if statement to check if its not found
	if (!found) {
		cout << "\n\t\t\tValue " << search << " is not found from MyBag.";
	}

	cout << "\n\n";
	system("pause");
	system("cls");
}
//precondition: going to pass in a value as our parameter
//postcondition: going to use the .erase() to delete the value from MyBag
void MyBag::removeMyBag(int remove){
	//get the beginning of the bag, then erase it 
	myBag.erase(myBag.begin() + remove);
	//cout << "\n\t\t\tValue " << remove << " has been deleted from MyBag.";
	cout << "\n\t\t\tIndex [" << remove << "] has been deleted from MyBag.";
	cout << "\n\n";
	system("pause");
	system("cls");
}

//precondition: going to call the MyBag vector
//postcondition: going to return the vector in sorted
void MyBag::sortMyBag() {
	//check if MyBag is empty, if empty, send a warning
	if (myBag.empty()) {
		cout << "\n\t\t\tMyBag is empty.\n\n";
		system("pause");
		system("cls");
		return;
	}
	//int* first;
	//int* second;
	//if (*first < *second) {
	sort(myBag.begin(), myBag.end());
	cout << "\n\t\t\tMyBag has been sorted.";
	cout << "\n\n";
	system("pause");
	system("cls");
	
}
//precondition: going to call MyBag
//postcondition: going to then display the MyBag information
void MyBag::displayMyBag(){
	//check if MyBag is empty, if empty, send a warning
	if (myBag.empty()) {
		cout << "\n\t\t\tMyBag is empty.\n\n";
		system("pause");
		system("cls");
		return;
	}
	cout << "\n\t\t\tMyBag contains these sorted integers: ";
	for (int i = 0; i < myBag.size(); i++){
		cout <<"\n\t\t\t[" << i << "] - " << myBag[i];
	}
	cout << "\n\n";
	system("pause");
	system("cls");
}
//precondition: going to print the information
//postcondition: going to create a menu that accepts 
void MyBag::menuInformation(){
	system("cls");
	char option;
	do {
		beginning:
		cout << "\n\t\t1> Non-template MyBag of integers";
		cout << "\n\t\t" << string(82, char(205));
		cout << "\n\t\t\tA> clear";
		cout << "\n\t\t\tB> insert";
		cout << "\n\t\t\tC> search";
		cout << "\n\t\t\tD> remove";
		cout << "\n\t\t\tE> sort";
		cout << "\n\t\t\tF> display";
		cout << "\n\t\t" << string(82, char(205));
		cout << "\n\t\t\t0> return";
		cout << "\n\t\t" << string(82, char(205)) << "\n";
		option = inputChar("\t\t\tOption: ", (static_cast<string>("ABCDEF0")));

		switch (toupper(option)) {
		case 'A': {
			clearMyBag();
		}
				break;
		case 'B': {
			*newValue = inputInteger("\n\t\t\tEnter a value and insert into MyBag: ");
			//setSize(insert);
			insertMyBag(newValue);
		}
				break;
		case 'C': {
			//check if MyBag is empty, if empty, send a warning
			if (myBag.empty()) {
				cout << "\n\t\t\tMyBag is empty.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			int search = inputInteger("\n\t\t\tEnter a value to search fromm MyBag: ");
			searchMyBag(search);
		}
				break;
		case 'D': {
			//check if MyBag is empty, if empty, send a warning
			if (myBag.empty()) {
				cout << "\n\t\t\tMyBag is empty.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			int remove = inputInteger("\n\t\t\tEnter an index(subscript) from MyBag to be deleted: ", 0, myBag.size()-1);
			removeMyBag(remove);
		}
				break;
		case 'E': {
			sortMyBag();
		}
				break;
		case 'F': {
			displayMyBag();
		}
				break;
		case '0': {
			return;
		}
		}
	} while (true);
}




