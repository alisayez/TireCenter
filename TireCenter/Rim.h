#pragma once
#include <string>
#include "Article.h"

using namespace std;

#ifndef RIM_H
#define RIM_H

class Rim :
    public Article
{
public:
    Rim(string, string, unsigned int, unsigned int, float, char, bool, string, unsigned int);
    Rim();
    ~Rim();
    bool getAluminium();
    void setAluminium(bool);
    std::string getColor();
    void setColor(std::string);
    unsigned int getWidth();
    void setWidth(unsigned int);
    virtual unsigned int getHeight();
    virtual void setHeight(unsigned int);
    virtual std::string getSpeedIndex();
    virtual void setSpeedIndex(std::string);
    virtual char getSeason();
    virtual void setSeason(char);
    virtual void printItem();
    virtual void enterArticle();
    virtual void changeArticle() override;
private:
    bool aluminium;
    string color;
    unsigned int width;

};

#endif