#include <string>
#include <sstream>
#include <iostream>
#include <iomanip> 
#include <vector>
#include "Customer.h"
#include "Article.h"
#include "Rim.h"
#include "Tire.h"
#include "Invoice.h"

using namespace std;

Invoice::Invoice(Customer*, std::vector<Article*>, float, int)
{
	r = 0;
	t = 0;
}

Invoice::Invoice()
{
	r = 0;
	t = 0;
}

Invoice::~Invoice()
{
	//cout << "\nInvoice object is deconstructed." << endl;
}

Customer* Invoice::getCustomer()
{
	return customer;
}

void Invoice::setCustomer(Customer* newCustomer)
{
	if (newCustomer->getType() == 'p') {
		dummyCustomer = *newCustomer;
		customer = &dummyCustomer;
	}
	else {
		dummyCompany.setName(newCustomer->getName());
		dummyCompany.setAddress(newCustomer->getAddress());
		dummyCompany.setType(newCustomer->getType());
		dummyCompany.setVAT(newCustomer->getVAT());
		dummyCompany.setVolumeDiscount(newCustomer->getVolumeDiscount());
		customer = &dummyCompany;
	}
}

vector<Article*> Invoice::getArticles()
{
	return articles;
}

void Invoice::setArticles(Article* article)
{
	char readType = article->getType();
	if (readType == 't') {
		tires[t].setType(article->getType());
		tires[t].setName(article->getName());
		tires[t].setManufacturer(article->getManufacturer());
		//tires[t].setStock(0);
		tires[t].setDiameter(article->getDiameter());
		tires[t].setPrice(article->getPrice());
		tires[t].setWidth(article->getWidth());
		tires[t].setHeight(article->getHeight());
		tires[t].setSpeedIndex(article->getSpeedIndex());
		tires[t].setSeason(article->getSeason());
		articles.push_back(&tires[t]);
		t+=1;

	}
	else if (readType == 'r') {
		rims[r].setType(article->getType());
		rims[r].setName(article->getName());
		rims[r].setManufacturer(article->getManufacturer());
		//rims[r].setStock(0);
		rims[r].setDiameter(article->getDiameter());
		rims[r].setPrice(article->getPrice());
		rims[r].setWidth(article->getWidth());
		rims[r].setAluminium(article->getAluminium());
		rims[r].setColor(article->getColor());
		articles.push_back(&rims[r]);
		r +=1;
	}
}

float Invoice::getPrice()
{
	return price;
}

void Invoice::setPrice(float priceInput)
{
	price = priceInput;
}

int Invoice::getDiscount()
{
	return discount;
}

void Invoice::setDiscount(int discountInput)
{
	discount = discountInput;
}

float Invoice::calculateDiscount()
{
	int sets{ 0 };
	float calculatedDiscount{0};
	if (customer->getType() == 'c') {
		
		calculatedDiscount = customer->getVolumeDiscount();
		for (int i = 0; i < articles.size(); i++) {
			int stockNum = articles[i]->getStock();
			while (!(stockNum % 4) && stockNum > 0) {
				stockNum -= 4;
				sets++;
			}
		}
		if (sets >= 10) {
			calculatedDiscount += 10;
		}
	}
	else {
		for (int i = 0; i < articles.size(); i++) {
			if (articles[i]->getType() == 't') {
				if (articles[i]->getStock() >= 4) {
					sets++;
				}
			}
		}
		if (sets > 0) {
			calculatedDiscount += 2;
		}

		int matchingRims{ 0 };
		for (int i = 0; i < articles.size(); i++) {
			if (articles[i]->getType() == 'r') {
				if (articles[i]->getStock() >= 4) {
					matchingRims++;
				}
			}
		}
		if (matchingRims > 0)
		{
			calculatedDiscount += 2;
		}
	}

	return calculatedDiscount;
}

float Invoice::calculatePrice()
{
	float calculatedPrice{0};

	for (int i = 0; i < articles.size(); i++) {
		calculatedPrice += articles[i]->getPrice() * articles[i]->getStock();
	}
	calculatedPrice = calculatedPrice - (calculatedPrice * discount/100);

	//setPrice(calculatedPrice);

	return calculatedPrice;
}

void Invoice::setStock(int stockValue, int index)
{
	articles[index]->setStock(stockValue);
}

void Invoice::printInvoice()
{
	cout << ">>> Printing invoice info..." << endl;
	cout << "Customer information:" << endl;
	cout << setw(30) << "NAME" << setw(30) << "ADDRESS" << setw(10) << "TYPE" << setw(15) << "VAT" << setw(10) << "DISCOUNT" << endl;
	customer->printInfo();
	cout << endl;
	cout << "Purchased articles:" << endl;
	cout << setw(20) << "NAME" << setw(20) << "MANUFACTURER" << setw(10) << "TYPE" << setw(10) << "PRICE" << setw(10) << "STOCK" << setw(10) << "D" << setw(10) << "W" << setw(10) << "H" << setw(10) << "SI" << setw(10) << "SEASON" << setw(15) << "COLOR" << setw(5) << "ALUMINIUM" << endl;
	for (int i = 0; i < articles.size(); i++) {
		articles[i]->printInfo();
		cout << endl;
	}
	cout << endl;
	cout << "Calculated discount: " << getDiscount() << endl;
	cout << "Final price: " << getPrice() << " euro." << endl;
}

int Invoice::getTiresNumber()
{
	return t;
}

int Invoice::getRimsNumber()
{
	return r;
}
