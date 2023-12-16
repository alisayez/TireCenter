//Article class member-functions definitions.
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip> 
#include "Article.h"

using namespace std;


Article::Article() {

}

Article::~Article() {
	//cout << "\nArticle object is deconstructed." << endl;
}

std::string Article::getName() {
	return name;
}
void Article::setName(std::string nameInput) {
	if (nameInput.length() > 0 && nameInput.length() < 50) {
		name = nameInput;
	}
	else {
		throw invalid_argument("Name must be more than 0 and less than 50 characters long.");
	}
	
}
std::string Article::getManufacturer() {
	return manufacturer;
}
void Article::setManufacturer(std::string manufacturerInput) {
	if (manufacturerInput.length() > 0 && manufacturerInput.length() < 50){
		manufacturer = manufacturerInput;
	}
	else {
		throw invalid_argument("Manufacturer must be more than 0 and less than 50 characters long.");
	}
	
}
int Article::getStock() {
	return stock;
}
void Article::setStock(unsigned int stockInput) {
	if (stockInput <= 1000) {
		stock = stockInput;
	}
	else {
		throw invalid_argument("Stock can be maximum 1000 per item.");
	}
}
int Article::getDiameter() {
	return diameter;
}
void Article::setDiameter(unsigned int diameterInput) {
	if (diameterInput > 10 && diameterInput < 100) {
		diameter = diameterInput;
	}
	else {
		throw invalid_argument("Diameter must be more than 10 and less than 100.");
	}

}
float Article::getPrice() {
	return price;
}
void Article::setPrice(float priceInput) {
	if (priceInput > 0) {
		price = priceInput;
	}
	else {
		throw invalid_argument("Price must be larger than 0.");
	}
}

char Article::getType() {
	return type;
}
void Article::setType(char typeInput) {
	if (typeInput == 't' || typeInput == 'r') {
		type = typeInput;
	}
	else {
		throw invalid_argument("Input must be 't' for tires or 'r' for rims.");
	}
}

void Article::printInfo()
{
	cout << left;
	cout << setw(20) << getName() << setw(20) << getManufacturer() << setw(10) << getType() << setw(10) << setprecision(2) << fixed << getPrice() << setw(10) << getStock() << setw(10) << getDiameter() << setw(10) << getWidth() << setw(10);
	if (getType() == 't') {
		cout << getHeight();
	}
	else {
		cout << "";
	}
	cout << setw(10) << getSpeedIndex() << setw(10) << getSeason() << setw(15) << getColor();
	if (getType() == 'r') { 
		cout << setw(5) << getAluminium();
	} 
	
}

void Article::enterArticle()
{
	std::string nameInput;
	std::string manufacturerInput;
	unsigned int stockInput;
	unsigned int diameterInput;
	float priceInput;

	cout << "Fill in information for a new article." << endl;
	cout << "Enter a name:" << endl;
	cin.clear();
	cin.ignore();
	getline(cin, nameInput);
	while (nameInput.length() >= 50 || nameInput.length() <= 0) {
		cout << "Enter a valid name(more than 0 and less than 50 characters):" << endl;
		getline(cin, nameInput);
	}

	cout << "Enter a manufacturer name:" << endl;
	getline(cin, manufacturerInput);
	while (manufacturerInput.length() <= 0 || manufacturerInput.length() >= 50) {
		cout << "Enter a valid manufacturer name(more than 0 and less than 50 characters):" << endl;
		getline(cin, manufacturerInput);
	}

	cout << "Enter a stock number:" << endl;
	cin >> stockInput;
	while (stockInput < 0 || stockInput > 1000 || cin.fail()) {
		cout << "Enter a valid stock number(more or equal to 0 and less than or equal to 1000):" << endl;
		cin.clear();
		cin.ignore();
		cin >> stockInput;
	}

	cout << "Enter a diameter:" << endl;
	cin >> diameterInput;
	while (diameterInput <= 10 || diameterInput >= 100 || cin.fail()) {
		cout << "Enter a valid diameter(must be more than 10 and less than 100):" << endl;
		cin.clear();
		cin.ignore();
		cin >> diameterInput;
	}

	cout << "Enter a price:" << endl;
	cin >> priceInput;
	while (priceInput <= 0 || cin.fail()) {
		cout << "Enter a valid price (more than 0):" << endl;
		cin.clear();
		cin.ignore();
		cin >> priceInput;
	}

	cout << endl;
	setName(nameInput);
	setManufacturer(manufacturerInput);
	setStock(stockInput);
	setDiameter(diameterInput);
	setPrice(priceInput);
}

void Article::changeArticle()
{
	std::string changedName;
	std::string changedManufacturer;
	std::string changedStock;
	unsigned int changedStocknum;
	std::string changedDiameter;
	unsigned int changedDiameternum;
	std::string changedPrice;
	float changedPricenum;

	cin.clear();
	cin.ignore();
	cout << "Enter new data to change or press enter to skip." << endl;
	cout << "Enter a new name (press enter to skip): " << endl;
	getline(cin, changedName);
	if (changedName != "") {
		while (changedName.length() >= 50 || changedName.length() <= 0) {
			cout << "Enter a valid name(more than 0 and less than 50 characters):" << endl;
			getline(cin, changedName);
		}
		setName(changedName);
	}

	cout << "Enter a new manufacturer name (press enter to skip):" << endl;
	getline(cin, changedManufacturer);
	if (changedManufacturer != "") {
		while (changedManufacturer.length() <= 0 || changedManufacturer.length() >= 50) {
			cout << "Enter a valid manufacturer name(more than 0 and less than 50 characters):" << endl;
			getline(cin, changedManufacturer);
		}
		setManufacturer(changedManufacturer);
	}

	cout << "Enter a stock number (press enter to skip):" << endl;
	getline(cin, changedStock);
	if (changedStock != "") {
		try {
			if (stoi(changedStock))
			{
				changedStocknum = stoi(changedStock);

				while (changedStocknum < 0 || changedStocknum > 1000 || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "Enter a valid stock number(more  or equal to 0 and more or equal to 1000):" << endl;
					cin >> changedStocknum;
				}
				setStock(changedStocknum);
			} else {
				throw exception{};
			}
		}
		catch (exception) {
			cout << "Non-integer input. Stock number will not be changed." << endl;
		}
	}

	cin.clear();
	cin.ignore();

	cout << "Enter a diameter (press enter to skip):" << endl;
	getline(cin, changedDiameter);
	if (changedDiameter != "") {
		try {
			if (stoi(changedDiameter))
			{
				changedDiameternum = stoi(changedDiameter);

				while (changedDiameternum <= 10 || changedDiameternum >= 100 || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "Enter a valid diameter(must be more than 10 and less than 100):" << endl;
					cin >> changedDiameternum;
				}
				setDiameter(changedDiameternum);
			}
			else {
				throw exception{};
			}
		}
		catch (exception) {
			cout << "Non-integer input. Diameter will not be changed." << endl;
		}
	}

	cin.clear();
	cin.ignore();
	cout << "Enter a price (press enter to skip):" << endl;
	getline(cin, changedPrice);
	if (changedPrice != "") {
		try {
			if (stoi(changedPrice))
			{
				changedPricenum = stoi(changedPrice);

				while (changedPricenum <= 0 || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "Enter a valid price(must be more than 0):" << endl;
					cin >> changedPricenum;
				}
				setPrice(changedPricenum);
			}
			else {
				throw exception{};
			}
		}
		catch (exception) {
			cout << "Non-integer input. Price will not be changed." << endl;
		}
	}
}