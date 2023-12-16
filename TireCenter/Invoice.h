#pragma once

#include <string>
#include <vector>
#include "Customer.h"
#include "Company.h"
#include "Tire.h"
#include "Rim.h"
#include "Article.h"


#ifndef INVOICE_H
#define INVOICE_H
class Invoice
{
public:
	Invoice(Customer*, std::vector<Article*>, float, int);
	Invoice();
	~Invoice();
	Customer* getCustomer();
	void setCustomer(Customer*);
	std::vector<Article*> getArticles();
	void setArticles(Article*);
	float getPrice();
	void setPrice(float);
	int getDiscount();
	void setDiscount(int);
	float calculateDiscount();
	float calculatePrice();
	void setStock(int, int);
	void printInvoice();
	int getTiresNumber();
	int getRimsNumber();

private:
	Customer dummyCustomer;
	Company dummyCompany;
	Customer* customer;
	Tire tires[20];
	Rim rims[20];
	int t;
	int r;
	std::vector<Article*> articles;
	float price;
	int discount;
};

#endif