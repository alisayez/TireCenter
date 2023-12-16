#include <string>
#include <sstream>
#include <iostream>
#include <iomanip> 
#include "Company.h"

using namespace std;

Company::Company(std::string nameInput, std::string addressInput, char typeInput, std::string VATInput, int volumeDiscountInput)
{
	setName(nameInput);
	setAddress(addressInput);
	setType(typeInput);
	setVAT(VATInput);
	setVolumeDiscount(volumeDiscountInput);
}

Company::Company()
{
}

Company::~Company()
{
	//cout << "\nCompany object is deconstructed." << endl;
}

std::string Company::getVAT()
{
	return VAT;
}

void Company::setVAT(std::string VATInput)
{
	if (VATInput.length() <= 10 && VATInput.length() > 3)
	{
		VAT = VATInput;
	}
	else {
		throw invalid_argument("VAT must be more than 3 and less than or equal to 10 characters long.");
	}
	
}

int Company::getVolumeDiscount()
{
	return volumeDiscount;
}

void Company::setVolumeDiscount(int volumeDiscountInput)
{
	if (volumeDiscountInput > 0 && volumeDiscountInput < 70) {
		volumeDiscount = volumeDiscountInput;
	}
	else {
		throw invalid_argument("Volume discount must be > 0% and < than 70%.");
	}
}

void Company::printInfo()
{
	Customer::printInfo();
	cout << setw(15) << getVAT();
	cout << setw(10) << getVolumeDiscount();
}

void Company::enterCustomer()
{
	Customer::enterCustomer();
	std::string VATInput;
	int volumeDiscountInput;

	cout << "Enter a VAT:" << endl;
	getline(cin, VATInput);
	while (VATInput.length() <= 3 || VATInput.length() > 10) {
		cout << "Enter a valid VAT (more than 3 and less than or equal to 10 characters):" << endl;
		getline(cin, VATInput);
	}

	cout << "Enter a volume discount number:" << endl;
	cin >> volumeDiscountInput;
	while (volumeDiscountInput <= 0 || volumeDiscountInput >= 70 || cin.fail()) {
		cout << "Enter a valid volume discount number (more than 0% and less than 70%):" << endl;
		cin.clear();
		cin.ignore();
		cin >> volumeDiscountInput;
	}
	setVAT(VATInput);
	setVolumeDiscount(volumeDiscountInput);

}

void Company::changeCustomer()
{
	Customer::changeCustomer();

	string changedVAT;
	string changedVD;
	int changedVDnum;

	cout << "Enter a VAT (press enter to skip):" << endl;
	getline(cin, changedVAT);
	if (changedVAT != "") {
		while (changedVAT.length() <= 3 || changedVAT.length() > 10) {
			cin.clear();
			cin.ignore();
			cout << "Enter a valid VAT (more than 3 and less than or equal to 10 characters):" << endl;
			getline(cin, changedVAT);
		}
		setVAT(changedVAT);
	}
	
	
	cout << "Enter a volume discount (press enter to skip):" << endl;
	getline(cin, changedVD);
	if (changedVD != "") {
		try {
			
			if (stoi(changedVD))
			{
				changedVDnum = stoi(changedVD);

				while (changedVDnum >= 70 || changedVDnum <= 0 || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "Enter a valid volume discount(more than 0% and less than 70%):" << endl;
					cin >> changedVDnum;
				}
				setVolumeDiscount(changedVDnum);
			}
			else {
				throw exception{};
			}
		}
		catch (exception) {
			cout << "Non-integer input. Volume discount will not be changed." <<endl;
		}

	}
}
