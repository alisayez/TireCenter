#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Customer.h"
#include<ctype.h>

using namespace std;

void printWelcome();
int chooseOption();
void employeeMenu();
void ownerMenu();
int chooseEmployee();
int chooseOwner();
char enterCustomerType();
int changeCustomerMenu();
std::string enterName();
bool confirmChange();
char enterArticleType();
int printFilterArticlesMenu();
int printFilterBySizeMenu();
int enterSize();

void printWelcome() {
	cout << "\n================================================" << endl;
	cout << "Welcome to a Tire Center Application!" << endl;
	cout << R"(
	  ______
	 /|_||_\`.__
	(   _    _ _\
	=`-(_)--(_)-'
	)" << endl;
	cout << "(c) Alisa Yezerska, 2021" << endl;
	cout << "================================================" << endl;
}


int chooseOption() {
	cout << "\nSelect your option:" << "\n\t0: Exit and update database" << "\n\t1: I am an owner " << "\n\t2: I am an employee" << endl;
	int choiceOption;
	cin >> choiceOption;
	while (choiceOption != 2 && choiceOption != 1 && choiceOption != 0 || cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter a valid digit (0, 1 or 2):" << endl;
		cin >> choiceOption;
	};

	return choiceOption;
}

void employeeMenu() {
	cout << "\n Select your option:" << "\n\t0: Back to main menu" << "\n\t1: Place order" << "\n\t2: Change customer" << 
		"\n\t3: Add customer"  <<  "\n\t4: Change article" << "\n\t5: Update stock" << "\n\t6: Print invoices" << endl;
}

void ownerMenu() {
	cout << "\t7: Add article" << "\n\t8: Delete article" << "\n\t9: Delete customer" << "\n\t10: Print customers" << "\n\t11: Prints articles" << endl;
}

int chooseEmployee() {
	int choiceOption;
	cin >> choiceOption;
	while (choiceOption < 0 || choiceOption > 6 || cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter a valid digit (0-6):" << endl;
		cin >> choiceOption;
	};

	return choiceOption;
}

int chooseOwner() {
	int choiceOption;
	cin >> choiceOption;
	while (choiceOption < 0 || choiceOption > 11 || cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter a valid digit (0-11):" << endl;
		cin >> choiceOption;
	};

	return choiceOption;
}

char enterCustomerType()
{
	char typeInput;
	cout << "Enter type of a customer('p' for private or 'c' for corporate):" << endl;
	cin >> typeInput;
	while (typeInput != 'p' && typeInput != 'c') {
		cout << "Enter a valid type(can only be 'c' for corporate or 'p' for private clients):" << endl;
		cin >> typeInput;
	}
	return typeInput;
}


int changeCustomerMenu() {
	int changeCustomerChoice;
	cout << "Choose your option:" << endl;
	cout << "\t0: Back to main menu" << endl;
	cout << "\t1: Change customer" << endl;
	cout << "\t2: Print all customers" << endl;
	cin >> changeCustomerChoice;
	while (changeCustomerChoice < 0 || changeCustomerChoice > 3) {
		cout << "Enter a valid choice(0-2):" << endl;
		cin >> changeCustomerChoice;
	}
	return changeCustomerChoice;
}

std::string enterName() {
	cout << "Enter a name:" << endl;
	cin.ignore();
	std::string nameInput;
	getline(cin, nameInput);
	while (nameInput.length() >= 50 || nameInput.length() <= 0) {
		cout << "Enter a valid name (more than 0 and less than 50 characters):" << endl;
		getline(cin, nameInput);
	}
	return nameInput;
}

bool confirmChange()
{
	//std::cout << "Press enter to continue." << endl;
	std::string answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	std::cout << "Are you sure to want to proceed? Type 'yes'." << endl;
	
	getline(cin, answer);
	if (answer == "yes") {
		return true;
	}
	else {
		return false;
	}
}

char enterArticleType()
{
	char typeInput;
	cout << "Enter type of an article('t' for tires or 'r' for rims):" << endl;
	cin >> typeInput;
	while (typeInput != 'r' && typeInput != 't') {
		cout << "Enter a valid type(can only be 't' for tires or 'r' for rims):" << endl;
		cin >> typeInput;
	}
	return typeInput;
}

int printFilterArticlesMenu()
{
	cout << "\nSelect your option:" << "\n\t0: Show only rims" << "\n\t1: Show only tires " << "\n\t2: Filter by size" << "\n\t3: Continue without filtering" << endl;
	int choiceOption;
	cin >> choiceOption;
	while (choiceOption > 3 || choiceOption < 0 || cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter a valid digit (0-3):" << endl;
		cin >> choiceOption;
	};

	return choiceOption;
}

inline int printFilterBySizeMenu()
{
	cout << "\nSelect your option:" << "\n\t0: Filter rims by diameter" << "\n\t1: Filter rims by width" << "\n\t2: Filter tires by diameter" << "\n\t3: Filter tires by width" << "\n\t4: Filter tires by height" << "\n\t5: Abort and search by name" << endl;
	int choiceOption;
	cin >> choiceOption;
	while (choiceOption > 5 || choiceOption < 0 || cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Enter a valid digit (0-5):" << endl;
		cin >> choiceOption;
	};

	return choiceOption;
}

int enterSize()
{
	int size;
	cout << "Enter size:" << endl;
	cin >> size;
	while (cin.fail() || size <= 0)
	{
		cout << "Size should be integer and more than 0" << endl;
		cout << "Enter size:" << endl;
		cin >> size;
	}
	return size;
}

