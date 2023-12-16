#pragma once

#include <string>
#include <vector>
#include "Article.h"
#include "Tire.h"
#include "Rim.h"
#include "Company.h"
#include "Customer.h"

#ifndef TIRECENTER_H
#define TIRECENTER_H
class TireCenter
{
public:
	TireCenter(std::string, std::string);
	TireCenter();
	~TireCenter();
	std::string getName();
	void setName(std::string);
	std::string getAddress();
	void setAddress(std::string);

	std::vector <Article*> getArticles();
	void addArticles(Article*);
	void setArticles(Article*, int);
	void deleteArticles(int);
	void printArticles();
	void printFilteredArticles(char, char='n', unsigned int = 0);
	int checkArticles(Article*);
	void modifyArticle(Article*, Article*);
	void updateStock(int, int);

	std::vector<Customer*> getCustomers();
	void addCustomers(Customer*);
	void setCustomers(Customer*, int);
	void deleteCustomers(int);
	void printCustomers();
	int checkCustomers(Customer*);
	void modifyCustomer(Customer*, Customer*);
private:
	std::string name;
	std::string address;
	std::vector<Article*> articles;
	std::vector<Customer*> customers;
};

#endif