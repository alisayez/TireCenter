#pragma once
#include <string>

#ifndef ARTICLE_H
#define ARTICLE_H
class Article
{
public:
	Article();
	~Article();
	std::string getName();
	void setName(std::string);
	std::string getManufacturer();
	void setManufacturer(std::string);
	int getStock();
	void setStock(unsigned int);
	int getDiameter();
	void setDiameter(unsigned int);
	float getPrice();
	void setPrice(float);
	char getType();
	void setType(char);
	virtual unsigned int getWidth() = 0;
	virtual void setWidth(unsigned int) = 0;
	virtual unsigned int getHeight() = 0;
	virtual void setHeight(unsigned int) = 0;
	virtual std::string getSpeedIndex() = 0;
	virtual void setSpeedIndex(std::string) = 0;
	virtual char getSeason() = 0;
	virtual void setSeason(char) = 0;
	virtual bool getAluminium() = 0;
	virtual void setAluminium(bool) = 0;
	virtual std::string getColor() = 0;
	virtual void setColor(std::string) = 0;
	virtual void printInfo();
	virtual void printItem() = 0;
	virtual void enterArticle();
	virtual void changeArticle();
protected:
	std::string name;
	std::string manufacturer;
	unsigned int stock;
	unsigned int diameter;
	float price;
	char type;
};

#endif