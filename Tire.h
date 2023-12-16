#pragma once
#include <string>
#include "Article.h"

using namespace std;

#ifndef TIRE_H
#define TIRE_H
class Tire :
    public Article
{
public:
	Tire(std::string, std::string, unsigned int, unsigned int, float, char, unsigned int, unsigned int, std::string, char);
	Tire();
	~Tire();
	unsigned int getWidth();
	void setWidth(unsigned int);
	unsigned int getHeight();
	void setHeight(unsigned int);
	std::string getSpeedIndex();
	void setSpeedIndex(std::string);
	char getSeason();
	void setSeason(char);
	virtual bool getAluminium();
	virtual void setAluminium(bool);
	virtual std::string getColor();
	virtual void setColor(std::string);
	virtual void printItem();
	virtual void enterArticle();
	virtual void changeArticle() override;

private:
    unsigned int width;
    unsigned int height;
    string speedIndex;
    char season;
};

#endif