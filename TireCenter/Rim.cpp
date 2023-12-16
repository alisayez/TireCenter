#include <string>
#include <sstream>
#include <iostream>
#include <iomanip> 
#include "Rim.h"

using namespace std;

Rim::Rim(std::string nameInput, std::string manufacturerInput, unsigned int stockInput, unsigned int diameterInput, float priceInput, char typeInput, bool aluminiumInput, string colorInput, unsigned int widthInput)
{
    setName(nameInput);
    setManufacturer(manufacturerInput);
    setStock(stockInput);
    setDiameter(diameterInput);
    setPrice(priceInput);
    setType(typeInput);
    aluminium = aluminiumInput;
    setColor(colorInput);
    setWidth(widthInput);
}

Rim::Rim()
{
}

Rim::~Rim()
{
    //std::cout << "\Rim object is deconstructed." << endl;
}

bool Rim::getAluminium()
{
	return aluminium;
}

void Rim::setAluminium(bool aluminiumInput)
{
    aluminium = aluminiumInput;
}

std::string Rim::getColor()
{
	return color;
}

void Rim::setColor(std::string colorInput)
{
    if (colorInput.length() >= 3 && colorInput.length() <= 10) {
        color = colorInput;
    }
    else {
        throw invalid_argument("Color length must be between 3 and 10.");
    }

}

unsigned int Rim::getWidth()
{
	return width;
}

void Rim::setWidth(unsigned int widthInput)
{
    if (widthInput > 10 && widthInput < 100) {
        width = widthInput;
    }
    else {
        throw invalid_argument("Width must be more than 10 and less than 100.");
    }
}

unsigned int Rim::getHeight()
{
    return 0;
}

void Rim::setHeight(unsigned int)
{
}

std::string Rim::getSpeedIndex()
{
    return std::string();
}

void Rim::setSpeedIndex(std::string)
{
}

char Rim::getSeason()
{
    return 0;
}

void Rim::setSeason(char)
{
}

void Rim::printItem()
{
    cout << setw(20) << "NAME" << setw(20) << "MANUFACTURER" << setw(10) << "TYPE" << setw(10) << "PRICE" << setw(10) << "STOCK" << setw(10) << "D" << setw(10) << "W" << setw(10) << setw(15) << "COLOR" << setw(5) << "ALUMINIUM" << endl;
    cout << setw(20) << getName() << setw(20) << getManufacturer() << setw(10) << getType() << setw(10) << setprecision(2) << fixed << getPrice() << setw(10) << getStock() << setw(10) << getDiameter() << setw(10) << getWidth() << setw(15) << getColor() << setw(5)<< getAluminium() << endl;

}

void Rim::enterArticle()
{
    Article::enterArticle();
    string aluminiumInput;
    string colorInput;
    unsigned int widthInput;

    //cout << "Press enter to continue..." << endl;
    cin.clear();
    cin.ignore();

    cout << "Enter a aluminium value (yes or no):" << endl;
    getline(cin, aluminiumInput);
    while (aluminiumInput != "yes" && aluminiumInput != "no") {
        cout << "Enter a valid aluminium value('yes' or 'no'):" << endl;
        getline(cin, aluminiumInput);
    }

    cout << "Enter a color:" << endl;
    getline(cin, colorInput);
    while (colorInput.length() < 3 || colorInput.length() > 10) {
        cout << "Enter a valid color name(more than or equal to 3 and less or equal to 10 characters):" << endl;
        getline(cin, colorInput);
    }

    cout << "Enter a width:" << endl;
    cin >> widthInput;
    while (widthInput <= 10 || widthInput >= 100 || cin.fail()) {
        cout << "Enter a valid width number (more than 10 and less than 100):" << endl;
        cin.clear();
        cin.ignore();
        cin >> widthInput;
    }

    if (aluminiumInput == "yes") {
        setAluminium(true);
    }
    else {
        setAluminium(false);
    }
    setColor(colorInput);
    setWidth(widthInput);
}

void Rim::changeArticle()
{
    Article::changeArticle();

    string changedWidth;
    unsigned int changedWidthnum;
    string changedAluminium;
    string changedColor;
    
    cin.clear();
    cin.ignore();
    cout << "Enter a new width value (press enter to skip): " << endl;
    getline(cin, changedWidth);
    if (changedWidth != "") {
        try {
            if (stoi(changedWidth))
            {
                changedWidthnum = stoi(changedWidth);

                while (changedWidthnum <= 10 || changedWidthnum >= 100 || cin.fail()) {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                    }
                    cout << "Enter a valid width number(must be more than 10 and less than 100):" << endl;
                    cin >> changedWidthnum;
                }
                setWidth(changedWidthnum);
            }
            else {
                throw exception{};
            }
        }
        catch (exception) {
            cout << "Non-integer input. Width number will not be changed." << endl;
        }
    }

    cout << "Enter a new aluminium value (press enter to skip): " << endl;
    getline(cin, changedAluminium);
    if (changedAluminium != "") {
        while (changedAluminium != "yes" && changedAluminium != "no") {
            cout << "Enter a valid aluminium value('yes' or 'no'):" << endl;
            getline(cin, changedAluminium);
        }
        if (changedAluminium == "yes") {
            setAluminium(true);
        }
        else {
            setAluminium(false);
        }
    }

    cout << "Enter a new color (press enter to skip): " << endl;
    getline(cin, changedColor);
    if (changedColor != "") {
        while (changedColor.length() > 10 || changedColor.length() < 3) {
            cout << "Enter a valid color (must be between 3 and 10 characters):" << endl;
            getline(cin, changedColor);
        }
        setColor(changedColor);
    }

}
