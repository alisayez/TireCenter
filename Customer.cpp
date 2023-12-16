#include <string>
#include <sstream>
#include <iostream>
#include <iomanip> 
#include "Customer.h"

using namespace std;

Customer::Customer(std::string nameInput, std::string addressInput, char typeInput) {
	setName(nameInput);
	setAddress(addressInput);
	setType(typeInput);
}
Customer::Customer() {
}
Customer::~Customer()
{
	//cout << "\nCustomer object is deconstructed." << endl;
}
std::string Customer::getName() {
	return name;
}
void Customer::setName(std::string nameInput) {
	if (nameInput.length() < 50 && nameInput.length() > 0) {
		name = nameInput;
	}
	else {
		throw invalid_argument("Name must be more than 0 and less than 50 characters long.");
	}
	
}
std::string Customer::getAddress() {
	return address;
}
void Customer::setAddress(std::string addressInput) {
	if (addressInput.length() > 5 && addressInput.length() < 100) {
		address = addressInput;
	} else {
		throw invalid_argument("Address must be longer than 5 and less than 100 characters long.");
	}
}
char Customer::getType() {
	return type;
}
void Customer::setType(char typeInput) {
	if (typeInput == 'p' || typeInput == 'c') {
		type = typeInput;
	}
	else {
		throw invalid_argument("Input must be 'p' for a private customer or 'c' for a corporate customer.");
	}
}

void Customer::setVAT(std::string)
{
	//cout << "You're inside a Customer class." << endl;
}

std::string Customer::getVAT()
{
	return std::string();
}

int Customer::getVolumeDiscount()
{
	return 0;
}

void Customer::setVolumeDiscount(int)
{
	//cout << "You're inside a Customer class." << endl;
}

void Customer::printInfo()
{
	cout << setw(30) << getName();
	cout << setw(30) << getAddress();
	cout << setw(10) << getType();
}

void Customer::enterCustomer()
{
	std::string nameInput;
	std::string addressInput;

	cout << "Fill in information for a new customer." << endl;
	cout << "Enter a name:" << endl;
	cin.clear();
	cin.ignore();
	getline(cin, nameInput);
	while (nameInput.length() >= 50 || nameInput.length() < 1) {
		cout << "Enter a valid name (more than 0 and less than 50 characters):" << endl;
		//cin.ignore();
		getline(cin, nameInput);
	}

	cout << "Enter an address:" << endl;
	getline(cin, addressInput);
	while (addressInput.length() <= 5 || addressInput.length() >= 100) {
		cout << "Enter a valid address (more than 5 and less than 100 characters):" << endl;
		getline(cin, addressInput);
	}

	cout << endl;
	setName(nameInput);
	setAddress(addressInput);

}


void Customer::changeCustomer() {

	string changedName;
	string changedAdress;

	cin.clear();
	cin.ignore();
	cout << "Enter new data to change or press enter to skip." << endl;
	cout << "Enter a new name: " << endl;
	getline(cin, changedName);
	if (changedName != "") {
		while (changedName.length() >= 50 || changedName.length() < 1) {
			cout << "Enter a valid name (more than 0 and less than 50 characters):" << endl;
			getline(cin, changedName);
		}
		setName(changedName);
	}

	cout << "Enter an address:" << endl;
	getline(cin, changedAdress);
	if (changedAdress != "") {
		while (changedAdress.length() <= 5 || changedAdress.length() >= 100) {
			cout << "Enter a valid address (more than 5 and less than 100 characters):" << endl;
			getline(cin, changedAdress);
		}
		setAddress(changedAdress);
	}

}


