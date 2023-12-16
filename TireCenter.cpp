#include <string>
#include <sstream>
#include <iostream>
#include <iomanip> 
#include <vector>
#include "TireCenter.h"

using namespace std;

TireCenter::TireCenter(std::string nameInput, std::string addressInput)
{
	name = nameInput;
	address = addressInput;
}

TireCenter::TireCenter()
{
}

TireCenter::~TireCenter()
{
	//cout << "\nTireCenter object is deconstructed.";
}

std::string TireCenter::getName()
{
	return name;
}

void TireCenter::setName(std::string nameInput)
{
	name = nameInput;
}

std::string TireCenter::getAddress()
{
	return address;
}

void TireCenter::setAddress(std::string adressInput)
{
	address = adressInput;
}

std::vector <Article*> TireCenter::getArticles()
{
	return articles;
}

void TireCenter::addArticles(Article* newArticle)
{
	int matches{ 0 };
	matches = checkArticles(newArticle);

	if (matches == 0) {
		articles.push_back(newArticle);
	}
	else {
		cout << "Failed. There is already a article with the same info in the database." << endl;
	}
}

void TireCenter::setArticles(Article* newArticle, int index)
{
	int matches{ 0 };
	matches = checkArticles(newArticle);
	char readType = newArticle->getType();

	if (matches == 0) {
		articles[index]->setName(newArticle->getName());
		articles[index]->setManufacturer(newArticle->getManufacturer());
		articles[index]->setStock(newArticle->getStock());
		articles[index]->setDiameter(newArticle->getDiameter());
		articles[index]->setPrice(newArticle->getPrice());
		
		if (readType == 't') {
			articles[index]->setHeight(newArticle->getHeight());
			articles[index]->setWidth(newArticle->getWidth());
			articles[index]->setSpeedIndex(newArticle->getSpeedIndex());
			articles[index]->setSeason(newArticle->getSeason());
		}
		else {
			articles[index]->setWidth(newArticle->getWidth());
			articles[index]->setAluminium(newArticle->getAluminium());
			articles[index]->setColor(newArticle->getColor());
		}
	}
	else {
		cout << "Failed. Either there is already an article with the same info in the database." << endl << "Or you have entered the same data for the chosen article." << endl;
	}
}

void TireCenter::deleteArticles(int index)
{
	articles.erase(articles.begin() + index);
	std::cout << "Succesfully deleted." << endl;
}

void TireCenter::printArticles()
{

	cout << left << setw(5) << "ID" << setw(20) << "NAME" << setw(20) << "MANUFACTURER" << setw(10) << "TYPE" << setw(10) << "PRICE" << setw(10) << "STOCK" << setw(10) << "D" << setw(10) << "W" << setw(10) << "H" << setw(10) << "SI" << setw(10) << "SEASON" <<  setw(15)  <<"COLOR" << setw(5) << "ALUMINIUM" << endl;
	cout << endl;
	for (int i = 0; i < articles.size(); i++) {
		cout << setw(5) << left << i;
		articles[i]->printInfo();
		cout << endl;
	}
}

void TireCenter::printFilteredArticles(char command, char parameter, unsigned int size)
{
	if (command == 't' && size == 0 && parameter == 'n') {
		cout << "Printing only tires..." << endl;
		for (int i = 0; i < articles.size(); i++) {
			if (articles[i]->getType() == 't') {
				articles[i]->printItem();
				cout << endl;
			}
			
		}
	}
	if (command == 'r' && size == 0 && parameter == 'n') {
		cout << "Printing only rims..." << endl;
		for (int i = 0; i < articles.size(); i++) {
			if (articles[i]->getType() == 'r') {
				articles[i]->printItem();
				cout << endl;
			}

		}
	}
	if (command == 'r' && size != 0) {
		if (parameter == 'w')
		{
			for (int i = 0; i < articles.size(); i++) {
				if (articles[i]->getType() == 'r' && articles[i]->getWidth() > size) {
					articles[i]->printItem();
				}
			}
		}
		else if (parameter == 'd') {
			for (int i = 0; i < articles.size(); i++) {
				if (articles[i]->getType() == 'r' && articles[i]->getDiameter() > size) {
					articles[i]->printItem();
				}
			}
		}
	}
	else if (command == 't' && size != 0) {
		if (parameter == 'w')
		{
			for (int i = 0; i < articles.size(); i++) {
				if (articles[i]->getType() == 't' && articles[i]->getWidth() > size) {
					articles[i]->printItem();
				}
			}
		}
		else if (parameter == 'd') {
			for (int i = 0; i < articles.size(); i++) {
				if (articles[i]->getType() == 't' && articles[i]->getDiameter() > size) {
					articles[i]->printItem();
				}
			}
		}
		else if (parameter == 'h') {
			for (int i = 0; i < articles.size(); i++) {
				if (articles[i]->getType() == 't' && articles[i]->getHeight() > size) {
					articles[i]->printItem();
				}
			}
		}
	}
}

int TireCenter::checkArticles(Article* newArticle)
{
	int matches{ 0 };
	char readType = newArticle->getType();

	for (int i = 0; i < articles.size(); i++) {
		if (readType == 't') {
			if (newArticle->getName() == articles[i]->getName() && newArticle->getManufacturer() == articles[i]->getManufacturer() && newArticle->getDiameter() == articles[i]->getDiameter() && newArticle->getPrice() == articles[i]->getPrice() && newArticle->getWidth() == articles[i]->getWidth() && newArticle->getHeight() == articles[i]->getHeight() && newArticle->getSpeedIndex() == articles[i]->getSpeedIndex() && newArticle->getSeason() == articles[i]->getSeason())
				matches++;
		}
		else if (readType == 'r') {
			if (newArticle->getName() == articles[i]->getName() && newArticle->getManufacturer() == articles[i]->getManufacturer() && newArticle->getDiameter() == articles[i]->getDiameter() && newArticle->getPrice() == articles[i]->getPrice() && newArticle->getWidth() == articles[i]->getWidth() && newArticle->getAluminium() == articles[i]->getAluminium() && newArticle->getColor() == articles[i]->getColor())
				matches++;
		}
	}
	return matches;
}

void TireCenter::modifyArticle(Article* article, Article* dummyArticle)
{
	char readType = article->getType();
	
	dummyArticle->setType(article->getType());
	dummyArticle->setName(article->getName());
	dummyArticle->setManufacturer(article->getManufacturer());
	dummyArticle->setStock(article->getStock());
	dummyArticle->setDiameter(article->getDiameter());
	dummyArticle->setPrice(article->getPrice());
	dummyArticle->setWidth(article->getWidth());

	if (readType == 't') {
		dummyArticle->setHeight(article->getHeight());
		dummyArticle->setSpeedIndex(article->getSpeedIndex());
		dummyArticle->setSeason(article->getSeason());
	}
	else {
		dummyArticle->setAluminium(article->getAluminium());
		dummyArticle->setColor(article->getColor());
	}

	dummyArticle->changeArticle();
}

void TireCenter::updateStock(int index, int changedStock)
{
	articles[index]->setStock(changedStock);

}


std::vector<Customer*> TireCenter::getCustomers()
{
	return customers;
}

void TireCenter::addCustomers(Customer* newCustomer) {
	int matches{ 0 };
	matches = checkCustomers(newCustomer);

	if (matches == 0) {
		customers.push_back(newCustomer);
	}
	else {
		cout << "Failed. There is already a customer with the same info in the database." << endl;
	}
}



void TireCenter::setCustomers(Customer* newCustomer, int index)
{
	int matches{ 0 };
	matches = checkCustomers(newCustomer);
	char readType = newCustomer->getType();

	if (matches == 0) {
		customers[index]->setName(newCustomer->getName());
		customers[index]->setAddress(newCustomer->getAddress());
		if (readType == 'c') {
			customers[index]->setVAT(newCustomer->getVAT());
			customers[index]->setVolumeDiscount(newCustomer->getVolumeDiscount());
		}
	}
	else {
		cout << "Failed. Either there is already a customer with the same name, address and type in the database." << endl << "Or you have entered the same data for the chosen customer." << endl;
	}
	
}

void TireCenter::deleteCustomers(int index) {
	customers.erase(customers.begin() + index);
	std::cout << "Succesfully deleted." << endl;
}

void TireCenter::printCustomers()
{
	cout << left << setw(5) << "ID" <<  setw(30) << "NAME" << setw(30) << "ADDRESS" << setw(10) << "TYPE" << setw(15) << "VAT" << setw(10) << "DISCOUNT" << endl;
	for (int i = 0; i < customers.size(); i++) {
		cout << setw(5) << i;
		customers[i]->printInfo();
		cout << endl;
	}
}

int TireCenter::checkCustomers(Customer* newCustomer)
{
	int matches{ 0 };
	char readType = newCustomer->getType();

	for (int i = 0; i < customers.size(); i++) {
		if (readType == 'p') {
			if (newCustomer->getName() == customers[i]->getName() && newCustomer->getAddress() == customers[i]->getAddress() && newCustomer->getType() == customers[i]->getType())
				matches++;
		}
		else if (readType == 'c') {
			if (newCustomer->getName() == customers[i]->getName() && newCustomer->getAddress() == customers[i]->getAddress() && newCustomer->getType() == customers[i]->getType() && newCustomer->getVAT() == customers[i]->getVAT() && newCustomer->getVolumeDiscount() == customers[i]->getVolumeDiscount())
				matches++;
		}

	}
	return matches;
}

void TireCenter::modifyCustomer(Customer* customer, Customer* dummyCustomer)
{
	char readType = customer->getType();

	dummyCustomer->setName(customer->getName());
	dummyCustomer->setAddress(customer->getAddress());
	dummyCustomer->setType(customer->getType());
	if (readType == 'c') {
		dummyCustomer->setVAT(customer->getVAT());
		dummyCustomer->setVolumeDiscount(customer->getVolumeDiscount());
	}
	dummyCustomer->changeCustomer();
}

