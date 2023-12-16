#pragma once
#include <string>
#include <vector>
#include "Customer.h"


#ifndef COMPANY_H
#define COMPANY_H

class Company :
    public Customer
{
public:
    Company(std::string, std::string, char, std::string, int);
    Company();
    virtual ~Company();
    virtual std::string getVAT() override;
    virtual void setVAT(std::string) override;
    virtual int getVolumeDiscount();
    virtual void setVolumeDiscount(int);
    virtual void printInfo();
    virtual void enterCustomer();
    virtual void changeCustomer();
private:
    std::string VAT;
    int volumeDiscount;
};

#endif