#include <string>
#include <sstream>
#include <iostream>
#include <iomanip> 
#include "Tire.h"

using namespace std;

Tire::Tire(std::string nameInput, std::string manufacturerInput, unsigned int stockInput, unsigned int diameterInput, float priceInput, char typeInput, unsigned int widthInput, unsigned int heightInput, std::string speedIndexInput, char seasonInput)
{
    setName(nameInput);
    setManufacturer(manufacturerInput);
    setStock(stockInput);
    setDiameter(diameterInput);
    setPrice(priceInput);
    setType(typeInput);
    setWidth(widthInput);
    setHeight(heightInput);
    setSpeedIndex(speedIndexInput);
    setSeason(seasonInput);
}

Tire::Tire()
{
}

Tire::~Tire()
{
    //std::cout << "\Tire object is deconstructed." << endl;
}

unsigned int Tire::getWidth()
{
    return width;
}

void Tire::setWidth(unsigned int widthInput)
{
    if (widthInput > 10 && widthInput < 100) {
        width = widthInput;
    }
    else {
        throw invalid_argument("Width must be more than 10 and less than 100.");
    }
}

unsigned int Tire::getHeight()
{
    return height;
}

void Tire::setHeight(unsigned int heightInput)
{
    if (heightInput > 10 && heightInput < 100) {
        height = heightInput;
    }
    else {
        throw invalid_argument("Height must be more than 10 and less than 100.");
    }
}

std::string Tire::getSpeedIndex()
{
    return speedIndex;
}

void Tire::setSpeedIndex(std::string speedIndexInput)
{
    if (speedIndexInput.length() > 0 && speedIndexInput.length() <= 2) {
        speedIndex = speedIndexInput;
    } else {
        throw invalid_argument("Speed index must be 1 or 2 characters long.");
    }
}

char Tire::getSeason()
{
    return season;
}

void Tire::setSeason(char seasonInput)
{
    if (seasonInput == 'w' || seasonInput == 's' || seasonInput == 'a') {
        season = seasonInput;
    } else {
        throw invalid_argument("Season must be 'w' for winter, 's' for summer or 'a' for all-season.");
    }
}

bool Tire::getAluminium()
{
    return false;
}

void Tire::setAluminium(bool)
{
}

std::string Tire::getColor()
{
    return std::string();
}

void Tire::setColor(std::string)
{
}

void Tire::printItem()
{
    cout << setw(20) << "NAME" << setw(20) << "MANUFACTURER" << setw(10) << "TYPE" << setw(10) << "PRICE" << setw(10) << "STOCK" << setw(10) << "D" << setw(10) << "W" << setw(10) << "H" << setw(10) << "SI" << setw(10) << "SEASON" << endl;

    cout << setw(20) << getName() << setw(20) << getManufacturer() << setw(10) << getType() << setw(10) << setprecision(2) << fixed << getPrice() << setw(10) << getStock() << setw(10) << getDiameter() << setw(10) << getWidth() << setw(10) << getHeight() << setw(10) << getSpeedIndex() << setw(10) << getSeason() << endl;
}

void Tire::enterArticle()
{
    Article::enterArticle();
    unsigned int widthInput;
    unsigned int heightInput;
    string speedIndexInput;
    char seasonInput;

    cout << "Enter a width:" << endl;
    cin >> widthInput;
    while (widthInput <= 10 || widthInput >= 100 || cin.fail()) {
        cout << "Enter a valid width number(more than 10 and less than 100):" << endl;
        cin.clear();
        cin.ignore();
        cin >> widthInput;
    }

    cout << "Enter a height:" << endl;
    cin >> heightInput;
    while (heightInput <= 10 || heightInput >= 100 || cin.fail()) {
        cout << "Enter a valid height number(more than 10 and less than 100):" << endl;
        cin.clear();
        cin.ignore();
        cin >> heightInput;
    }

    cin.clear();
    cin.ignore();
    cout << "Enter a speed index:" << endl;
    getline(cin, speedIndexInput);
    while (speedIndexInput.length() < 0 || speedIndexInput.length() > 3) {
        cout << "Enter a valid speed index(more than 0 and less than 3 characters):" << endl;
        getline(cin, speedIndexInput);
    }

    cout << "Enter a season:" << endl;
    cin >> seasonInput;
    while (seasonInput != 'w' && seasonInput != 's' && seasonInput != 'a' || cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Enter a valid season('w' for winter, 's' for summer or 'a' for all-season):" << endl;
        cin >> seasonInput;
    }

    setWidth(widthInput);
    setHeight(heightInput);
    setSpeedIndex(speedIndexInput);
    setSeason(seasonInput);
}

void Tire::changeArticle()
{
    Article::changeArticle();
    
    string changedWidth;
    unsigned int changedWidthnum;
    string changedHeight;
    unsigned int changedHeightnum;
    string changedSpeedIndex;
    string changedSeason;
    char changedSeasonchar;
    
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

    cin.clear();
    cin.ignore();

    cout << "Enter a new height value (press enter to skip): " << endl;
    getline(cin, changedHeight);
    if (changedHeight != "") {
        try {
            if (stoi(changedHeight))
            {
                changedHeightnum = stoi(changedHeight);

                while (changedHeightnum <= 10 || changedHeightnum >= 100 || cin.fail()) {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                    }
                    cout << "Enter a valid height number(must be more than 10 and less than 100):" << endl;
                    cin >> changedHeightnum;
                }
                setHeight(changedHeightnum);
            }
            else {
                throw exception{};
            }
        }
        catch (exception) {
            cout << "Non-integer input. Height number will not be changed." << endl;
        }
    }

    cin.clear();
    cin.ignore();

    cout << "Enter a speed index (press enter to skip):" << endl;
    getline(cin, changedSpeedIndex);
    if (changedSpeedIndex != "") {
        while (changedSpeedIndex.length() > 3 || changedSpeedIndex.length() < 0 || cin.fail()) {
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
            }
            cout << "Enter a valid speed index (1-3 characters):" << endl;
            getline(cin, changedSpeedIndex);
        }
        setSpeedIndex(changedSpeedIndex);
    }

    
    cout << "Enter a season (press enter to skip):" << endl;
    getline(cin, changedSeason);
    if (changedSeason != "") {
        try {
            changedSeasonchar = changedSeason[0];
            if (changedSeasonchar)
            {
                while (changedSeasonchar != 'w' && changedSeasonchar != 's' && changedSeasonchar != 'a' || cin.fail()) {
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                    }
                    cout << "Enter a valid season('w' for winter, 's' for summer or 'a' for all-season):" << endl;
                    cin >> changedSeasonchar;
                }
                setSeason(changedSeasonchar);
            }
            else {
                throw exception{};
            }
        }
        catch (exception) {
            cout << "Non-integer input. Season will not be changed." << endl;
        }
    }
}
