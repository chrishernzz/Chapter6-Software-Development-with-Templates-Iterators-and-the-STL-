//Christian Hernandez
//Date: 10/12/2023
//subscription: CMPR131

#include<iostream>
#include"input (1).h"
#include"MyBag.h"
using namespace std;

//prototype
int menuOption();
void challenge1();
void challenge2();
void challenge3();

int main()
{
	do {
		switch (menuOption()) {
		case 0: exit(1); break;
		case 1: challenge1(); break;
		case 2: challenge2(); break;
		case 3: challenge3(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	return EXIT_SUCCESS;
}

//precondition: making a menu option
//postcondition: it will return an int (the choice of the menu)
int menuOption() {
	system("cls");
	cout << "\n\tCMPR131 Chapter 6: non-template and template Container by Christian Hernandez(9/28/2023)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Non-template MyBag container of int";
	cout << "\n\t\t2> Template MyBag<double> container";
	cout << "\n\t\t3> Application using MyBag container";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));
	//calling the input.h and we are inputting c1 from 0 through 3
	return inputInteger("\n\t\tOption: ", 0, 3);
}

//precondition: going to call my MyBag class that has the size and capacity
//postcondition: going to then call my menuInformation function that will have all the information and the menus as well
void challenge1() {
	MyBag menu;
	menu.menuInformation();
}
//precondition: going to call my Rational Class
//postcondition: going to then displayInformation function so that will give me the information for rational
void challenge2() {
	/*Rational menu;
	menu.RationalMenu();*/
}
//precondition: going to call my MyBagsCourse class that will read from the file
//postcondition: going to then call my menuInformation function that will have all the information and the menus as well
void challenge3() {
	//Course menu;
	//menu.menuInformation();
}
