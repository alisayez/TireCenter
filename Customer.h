#pragma once
#include <string>

#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{
public:
	Customer(std::string, std::string, char);
	Customer();
	virtual ~Customer();
	std::string getName();
	void setName(std::string);
	std::string getAddress();
	void setAddress(std::string);
	char getType();
	void setType(char);
	virtual void setVAT(std::string);
	virtual std::string getVAT();
	virtual int getVolumeDiscount();
	virtual void setVolumeDiscount(int);
	virtual void printInfo();
	virtual void enterCustomer();
	virtual void changeCustomer();
protected:
	std::string name;
	std::string address;
	char type;
};

#endif