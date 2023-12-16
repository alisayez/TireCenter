#include <iostream>
#include <stdexcept>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Customer.h"
#include "Company.h"
#include "Article.h"
#include "Tire.h"
#include "Rim.h"
#include "Invoice.h"
#include "SourceFunctions.h"
#include "TireCenter.h"

using namespace std;

int main() {

	TireCenter my_tire_center{ "Brussels Tires&Rims", "High Street 2, Wonderland" };

	// Change numbers in brackets for bigger database
	Customer new_customers[20];
	Company new_companies[20];
	// Counters for new customers and companies
	int j = 0;
	int k = 0;

	//Read customers from a file
	ifstream inCustomersFile{"customers_data.txt", ios::in};
	if (!inCustomersFile) {
		cerr << "Customers file could not be opened!" << endl;
		exit(EXIT_FAILURE);
	}

	while (!inCustomersFile.eof()) {
		std::string nameTxt;
		std::string addressTxt;
		char typeTxt = 'n';
		std::string VATTxt;
		int volumeDiscountTxt;
		inCustomersFile >> quoted(nameTxt) >> quoted(addressTxt) >> typeTxt;
		if (typeTxt == 'p') {
			Customer newCustomer(nameTxt, addressTxt, typeTxt);
			new_customers[j] = newCustomer;
			my_tire_center.addCustomers(&new_customers[j]);
			j++;
		}
		if (typeTxt == 'c') {
			inCustomersFile >> VATTxt >> volumeDiscountTxt;
			Company newCompany(nameTxt, addressTxt, typeTxt, VATTxt, volumeDiscountTxt);
			new_companies[k] = newCompany;
			my_tire_center.addCustomers(&new_companies[k]);
			k++;
		}
	}
	inCustomersFile.close();

	Tire new_tires[20];
	Rim new_rims[20];

	//Counters for tires and rims
	int l = 0;
	int m = 0;

	//Read articles from a file
	ifstream inArticlesFile{ "articles_data.txt", ios::in };
	if (!inArticlesFile) {
		cerr << "Articles file could not be opened!" << endl;
		exit(EXIT_FAILURE);
	}
	while (!inArticlesFile.eof()) {
		std::string nameTxt;
		std::string manufacturerTxt;
		char typeTxt = 'n';
		unsigned int stockTxt;
		unsigned int diameterTxt;
		float priceTxt;

		unsigned int widthTxt;
		unsigned int heightTxt;
		string speedIndexTxt;
		char seasonTxt;

		bool aluminiumTxt;
		string colorTxt;

		inArticlesFile >> quoted(nameTxt) >> quoted(manufacturerTxt) >> typeTxt >> stockTxt >> diameterTxt >> priceTxt;
		if (typeTxt == 't') {
			inArticlesFile >> widthTxt >> heightTxt >> quoted(speedIndexTxt) >> seasonTxt;
			Tire newTire(nameTxt, manufacturerTxt, stockTxt, diameterTxt, priceTxt, typeTxt, widthTxt, heightTxt, speedIndexTxt, seasonTxt);
			new_tires[l] = newTire;
			my_tire_center.addArticles(&new_tires[l]);
			l++;
		}
		if (typeTxt == 'r') {
			inArticlesFile >> widthTxt >> aluminiumTxt >> quoted(colorTxt);
			Rim newRim(nameTxt, manufacturerTxt, stockTxt, diameterTxt, priceTxt, typeTxt, aluminiumTxt, colorTxt, widthTxt);
			new_rims[m] = newRim;
			my_tire_center.addArticles(&new_rims[m]);
			m++;
		}
	}
	inArticlesFile.close();

	Invoice invoices[20];
	//Counter for invoices
	int c = 0;

	//Read invoices from a file
	ifstream inInvoicesFile{ "invoices_data.txt", ios::in };
	if (!inInvoicesFile) {
		cerr << "Invoices file could not be opened!" << endl;
		exit(EXIT_FAILURE);
	}

	while (!inInvoicesFile.eof()) {
		std::string nameTxt;
		std::string addressTxt;
		char typeTxt = 'n';
		std::string VATTxt;
		int volumeDiscountTxt;
		std::string nameArticleTxt;
		std::string manufacturerTxt;
		char typeArticleTxt = 'n';
		unsigned int stockTxt;
		unsigned int diameterTxt;
		float priceTxt;
		unsigned int widthTxt;
		unsigned int heightTxt;
		string speedIndexTxt;
		char seasonTxt;
		bool aluminiumTxt;
		string colorTxt;
		float priceInvoiceTxt;
		int discountTxt;
		int tt = 0;
		int rr = 0;

		inInvoicesFile >> quoted(nameTxt) >> quoted(addressTxt) >> typeTxt;
		if (typeTxt == 'p') {
			Customer newCustomer(nameTxt, addressTxt, typeTxt);
			invoices[c].setCustomer(&newCustomer);
		}
		if (typeTxt == 'c') {
			inInvoicesFile >> VATTxt >> volumeDiscountTxt;
			Company newCompany(nameTxt, addressTxt, typeTxt, VATTxt, volumeDiscountTxt);
			invoices[c].setCustomer(&newCompany);
		}
		inInvoicesFile >> priceInvoiceTxt >> discountTxt >> tt >> rr;

		for (int i = 0; i < tt; i++) {
			inInvoicesFile >> quoted(nameArticleTxt) >> quoted(manufacturerTxt) >> typeArticleTxt >> stockTxt >> diameterTxt >> priceTxt;
			inInvoicesFile >> widthTxt >> heightTxt >> quoted(speedIndexTxt) >> seasonTxt;
			Tire newTire(nameArticleTxt, manufacturerTxt, stockTxt, diameterTxt, priceTxt, typeArticleTxt, widthTxt, heightTxt, speedIndexTxt, seasonTxt);
			invoices[c].setArticles(&newTire);
			invoices[c].setStock(stockTxt, i);
		}
		int a = tt;
		for (int j = 0; j < rr; j++) {
			inInvoicesFile >> quoted(nameArticleTxt) >> quoted(manufacturerTxt) >> typeArticleTxt >> stockTxt >> diameterTxt >> priceTxt;
			inInvoicesFile >> widthTxt >> aluminiumTxt >> quoted(colorTxt);
			Rim newRim(nameArticleTxt, manufacturerTxt, stockTxt, diameterTxt, priceTxt, typeArticleTxt, aluminiumTxt, colorTxt, widthTxt);
			invoices[c].setArticles(&newRim);
			invoices[c].setStock(stockTxt, a);
			a++;
		}
		invoices[c].setPrice(priceInvoiceTxt);
		invoices[c].setDiscount(discountTxt);
		c++;
		tt = 0;
		rr = 0;
	}
	c = c - 1;
	inInvoicesFile.close();

	std::cout << setw(30) << left << "Tire center name:" << setw(50) <<  my_tire_center.getName() << endl;
	std::cout << setw(30) << left << "Tire center address:" << setw(50) << my_tire_center.getAddress() << endl;

	printWelcome();

	int mainMenu{0};
	int choiceMenu;

	
	do {
		int choiceOption = chooseOption();
		vector<Customer*> clients_database = my_tire_center.getCustomers();
		vector<Article*> articles_database = my_tire_center.getArticles();
		do {
			mainMenu = 1;
			if (choiceOption == 1) {
				std::cout << "You are logged in as an owner." << endl;
				employeeMenu();
				ownerMenu();
				choiceMenu = chooseOwner();
			}
			else if (choiceOption == 2) {
				std::cout << "You are logged in as an employee." << endl;
				employeeMenu();
				choiceMenu = chooseEmployee();
			}
			else if (choiceOption == 0) {
				std::cout << "Goodbye. And see you soon." << endl;
				std::cout << "Results are being saved..." << endl;
				ofstream customers_data;
				customers_data.open("customers_data.txt");
				for (int i = 0; i < clients_database.size(); i++) {
					customers_data << quoted(clients_database[i]->getName()) << " " << quoted(clients_database[i]->getAddress()) << " " << clients_database[i]->getType();
					if (clients_database[i]->getType() == 'p') {
						customers_data << "\n";
					}
					else {
						customers_data << " " << clients_database[i]->getVAT() << " " << clients_database[i]->getVolumeDiscount() << "\n";
					}
				}
				customers_data.close();

				ofstream articles_data;
				articles_data.open("articles_data.txt");
				for (int i = 0; i < articles_database.size(); i++) {
					articles_data << quoted(articles_database[i]->getName()) << " " << quoted(articles_database[i]->getManufacturer()) << " " << articles_database[i]->getType() << " " << articles_database[i]->getStock() << " " << articles_database[i]->getDiameter() << " " << articles_database[i]->getPrice();
					if (articles_database[i]->getType() == 't') {
						articles_data << " " << articles_database[i]->getWidth() << " " << articles_database[i]->getHeight() << " " << quoted(articles_database[i]->getSpeedIndex()) << " " << articles_database[i]->getSeason() << "\n";
					}
					else {
						articles_data << " " << articles_database[i]->getWidth() << " " << articles_database[i]->getAluminium() << " " << quoted(articles_database[i]->getColor()) << "\n";
					}
				}
				articles_data.close();

				ofstream invoices_data;
				invoices_data.open("invoices_data.txt");
				for (int i = 0; i < c; i++) {
					Customer* readCustomer = invoices[i].getCustomer();
					invoices_data << quoted(readCustomer->getName()) << " " << quoted(readCustomer->getAddress()) << " " << readCustomer->getType() << " ";
					if (readCustomer->getType() == 'c') {
						invoices_data << readCustomer->getVAT() << " " << readCustomer->getVolumeDiscount() << " ";
					}
					invoices_data << invoices[i].getPrice() << " " << invoices[i].getDiscount() << " ";
					int t_invoice = invoices[i].getTiresNumber();
					int r_invoice = invoices[i].getRimsNumber();
					invoices_data << t_invoice << " " << r_invoice << " ";
					vector <Article*> readArticles = invoices[i].getArticles();
					for (int i = 0; i < readArticles.size(); i++) {
						if (readArticles[i]->getType() == 't') {
							invoices_data << quoted(readArticles[i]->getName()) << " " << quoted(readArticles[i]->getManufacturer()) << " " << readArticles[i]->getType() << " " << readArticles[i]->getStock() << " " << readArticles[i]->getDiameter() << " " << readArticles[i]->getPrice();
							invoices_data << " " << readArticles[i]->getWidth() << " " << readArticles[i]->getHeight() << " " << quoted(readArticles[i]->getSpeedIndex()) << " " << readArticles[i]->getSeason() << " ";
						}
					}
					for (int i = 0; i < readArticles.size(); i++) {
						if (readArticles[i]->getType() == 'r') {
							invoices_data << " " << quoted(readArticles[i]->getName()) << " " << quoted(readArticles[i]->getManufacturer()) << " " << readArticles[i]->getType() << " " << readArticles[i]->getStock() << " " << readArticles[i]->getDiameter() << " " << readArticles[i]->getPrice();
							invoices_data << " " << readArticles[i]->getWidth() << " " << readArticles[i]->getAluminium() << " " << quoted(readArticles[i]->getColor()) << " ";
						}
					}
					invoices_data << "\n";
				}
				invoices_data.close();
				exit(0);
			}

			switch (choiceMenu) {
			case 0:
			{
				mainMenu = 0;
				break;
			}
			case 1:
			{
				clients_database = my_tire_center.getCustomers();
				articles_database = my_tire_center.getArticles();
				std::cout << "Ok! Let's place a new order." << endl;
				std::cout << "Select a customer." << endl;
				my_tire_center.printCustomers();
				string customerName = enterName();
				int n = 0;
				for (int i = 0; i < clients_database.size(); i++) {
					if (customerName == clients_database[i]->getName()) {
						n++;
					}
				}
				std::cout << "Found " << n << " entry(ies) with this name." << endl;
				int i = 0;
				while (n > 0) {
					clients_database = my_tire_center.getCustomers();
					if (customerName == clients_database[i]->getName()) {
						clients_database[i]->printInfo();
						std::cout << endl;
						std::cout << "Do you want to create an invoice for a customer with name '" << customerName << "' and an ID " << i << "?" << endl;
						std::cout << "Press enter..." << endl;
						bool answer = confirmChange();

						if (answer) {
							invoices[c].setCustomer(clients_database[i]);
							break;
						}
						else {
							std::cout << "Wrong input. Mission aborted." << endl;
						}
						n--;
					}
					i++;
				};

				if (n == 0)
				{
					std::cout << "Cannot create an invoice without a customer. Mission aborted." << endl;
					break;
				}
				bool addingDone = false;
				int a = 0;
				while (addingDone == false) {
					string answer;
					std::cout << "Let's add articles to your invoice" << endl;
					std::cout << "Do you want to filter articles first?" << endl;
					int filterArticleChoice = printFilterArticlesMenu();
					if (filterArticleChoice == 0) {
						my_tire_center.printFilteredArticles('r');
					}
					else if (filterArticleChoice == 1) {
						my_tire_center.printFilteredArticles('t');
					}
					else if (filterArticleChoice == 2) {
						std::cout << "Ok. Let's filter by size." << endl;
						int filterBySizeChoice = printFilterBySizeMenu();
						int sizeValue = enterSize();
						if (filterBySizeChoice == 0) {
							my_tire_center.printFilteredArticles('r', 'd', sizeValue);
						} 
						else if (filterBySizeChoice == 1) {
							my_tire_center.printFilteredArticles('r', 'w', sizeValue);
						}
						else if (filterBySizeChoice == 2) {
							my_tire_center.printFilteredArticles('t', 'd', sizeValue);
						}
						else if (filterBySizeChoice == 3) {
							my_tire_center.printFilteredArticles('t', 'w', sizeValue);
						}
						else if (filterBySizeChoice == 4) {
							my_tire_center.printFilteredArticles('t', 'h', sizeValue);
						}
						else if (filterBySizeChoice == 5) {
							std::cout << "Ok. Let's proceed without filtering." << endl;
							my_tire_center.printArticles();
						}
					}
					else {
						std::cout << "Ok. Let's proceed without filtering." << endl;
						my_tire_center.printArticles();
					}

					string articleToAdd = enterName();
					int n = 0;
					for (int i = 0; i < articles_database.size(); i++) {
						if (articleToAdd == articles_database[i]->getName()) {
							n++;
						}
					}
					std::cout << "Found " << n << " entry(ies) with this name." << endl;

					int i = 0;
					while (n > 0) {
						articles_database = my_tire_center.getArticles();
						if (articleToAdd == articles_database[i]->getName()) {
							articles_database[i]->printInfo();
							std::cout << endl;
							std::cout << "Do you want to add this article to invoice?" << endl;
							std::cout << "Press enter..." << endl;
							bool answer = false;
							answer = confirmChange();
							if (answer) {
								invoices[c].setArticles(articles_database[i]);
								std::cout << "How many articles do you want to add?" << endl;
								int purchasedStock;
								cin >> purchasedStock;
								if (articles_database[i]->getType() == 't') {
									while (cin.fail() || purchasedStock % 2 != 0 && purchasedStock != 1) {
										if (cin.fail()) {
											cin.clear();
											cin.ignore();
										}
										cout << "Tires are sold only in set of 2 or 4 articles or per piece." << endl;
										cout << "Enter a new number of tires:" << endl;
										cin >> purchasedStock;
									}
								}
								else {
									while (cin.fail() || purchasedStock % 4 != 0) {
										if (cin.fail()) {
											cin.clear();
											cin.ignore();
										}
										cout << "Rims are sold only in set of 4 articles." << endl;
										cout << "Enter a new number of rims:" << endl;
										cin >> purchasedStock;
									}
								}
								if (articles_database[i]->getStock() >= purchasedStock) {
									invoices[c].setStock(purchasedStock, a);
									int updatedStock = articles_database[i]->getStock() - purchasedStock;
									articles_database[i]->setStock(updatedStock);
									a++;
								}
								else {
									cout << "You need more articles than there's currently in stock. Mission aborted." << endl;
								}
							}
							else {
								std::cout << "Wrong input. Mission aborted." << endl;
							}
							n--;
						}
						i++;
					};
					cin.clear();
					cin.ignore();
					std::cout << "Do you want to add more articles? Type 'yes' to proceed." << endl;
					getline(cin, answer);
					if (answer != "yes") {
						addingDone = true;
					}
				}
				std::cout << "Ok. The invoice is being calculated..." << endl;
				invoices[c].setDiscount(invoices[c].calculateDiscount());
				invoices[c].setPrice(invoices[c].calculatePrice());
				std::cout << "The calculated discount is " << invoices[c].getDiscount() << "%." << endl;
				std::cout << "Total price is " << invoices[c].getPrice() << endl;
				a = 0;
				c++;
				break;
			}
			case 2:
			{
				std::cout << "Ok! Let's change a customer." << endl;
				std::cout << "Currently we have " << clients_database.size() << " client(s) in our database." << endl;
				my_tire_center.printCustomers();
				string customerName;
				customerName = enterName();
				std::cout << "We are looking for a customer whose name is " << customerName << endl;
				int n = 0;
				for (int i = 0; i < clients_database.size(); i++) {
					if (customerName == clients_database[i]->getName()) {
						n++;
					}
				}
				std::cout << "Found " << n << " entry(ies) with this name." << endl;
				std::cout << "!REMEMBER. You cannot change a type of a customer." << endl;

				if (n > 0) {
					for (int i = 0; i < clients_database.size(); i++) {
						if (customerName == clients_database[i]->getName()) {
							clients_database = my_tire_center.getCustomers();
							std::cout << "Printing info..." << endl;
							std::cout << setw(30) << "NAME" << setw(30) << "ADDRESS" << setw(10) << "TYPE" << setw(15) << "VAT" << setw(10) << "DISCOUNT" << endl;
							clients_database[i]->printInfo();
							std::cout << endl;
							std::cout << "Changing a customer with a name '" << customerName << "' and an ID " << i << ":" << endl;
							std::cout << "Press enter to continue..." << endl;

							char typeRead = clients_database[i]->getType();
							bool confirmChoice;
							if (typeRead == 'p') {
								Customer dummyCust;
								my_tire_center.modifyCustomer(clients_database[i], &dummyCust);
								std::cout << "Changed private customer info:" << endl;
								dummyCust.printInfo();
								std::cout << endl;
								confirmChoice = confirmChange();
								if (confirmChoice) {
									my_tire_center.setCustomers(&dummyCust, i);
									my_tire_center.printCustomers();
								} else {
									cout << "Customer was not changed!" << endl;
								}

							}
							else if (typeRead == 'c') {
								Company dummyComp;
								my_tire_center.modifyCustomer(clients_database[i], &dummyComp);
								std::cout << "Changed corporate customer info:" << endl;
								dummyComp.printInfo();
								std::cout << endl;
								confirmChoice = confirmChange();
								if (confirmChoice) {
									my_tire_center.setCustomers(&dummyComp, i);
									my_tire_center.printCustomers();
								} else {
									cout << "Customer was not changed!" << endl;
								}
							}
						}
					}
				}
				break;
			}
			case 3:
			{
				std::cout << "Ok! Let's add a customer." << endl;
				char typeChoice = enterCustomerType();
				if (typeChoice == 'p') {
					Customer newCustomer;
					newCustomer.setType('p');
					newCustomer.enterCustomer();
					std::cout << "A new private customer with following name, address and type will be created:" << endl;
					newCustomer.printInfo();
					std::cout << endl;
					new_customers[j] = newCustomer;
					my_tire_center.addCustomers(&new_customers[j]);
					j++;
				} else if (typeChoice == 'c') {
					Company newCompany;
					newCompany.setType('c');
					newCompany.enterCustomer();
					std::cout << "A new corporate customer with following name, address, type, VAT and volume discount will be created:" << endl;
					newCompany.printInfo();
					std::cout << endl;
					new_companies[k] = newCompany;
					my_tire_center.addCustomers(&new_companies[k]);
					k++;
				}
				std::cout << "A new customer is added succesfully." << endl;
				my_tire_center.printCustomers();
				break;
			}
			case 4:
			{
				std::cout << "Ok! Let's change an article." << endl;
				std::cout << "Currently we have " << articles_database.size() << " client(s) in our database." << endl;
				my_tire_center.printArticles();
				string articleName;
				articleName = enterName();
				std::cout << "We are looking for an article which name is " << articleName << endl;
				int n = 0;
				for (int i = 0; i < articles_database.size(); i++) {
					if (articleName == articles_database[i]->getName()) {
						n++;
					}
				}
				std::cout << "Found " << n << " entry(ies) with this name." << endl;
				std::cout << "!REMEMBER. You cannot change a type of an article." << endl;

				if (n > 0) {
					for (int i = 0; i < articles_database.size(); i++) {
						if (articleName == articles_database[i]->getName()) {
							articles_database = my_tire_center.getArticles();
							std::cout << "Printing info..." << endl;
							articles_database[i]->printItem();
							std::cout << endl;
							std::cout << "Changing an article with a name '" << articleName << "' and an ID " << i << ":" << endl;
							std::cout << "Press enter to continue..." << endl;

							char typeRead = articles_database[i]->getType();
							bool confirmChoice;
							if (typeRead == 't') {
								Tire dummyTire;
								my_tire_center.modifyArticle(articles_database[i], &dummyTire);
								std::cout << "Changed tire info:" << endl;
								dummyTire.printItem();
								std::cout << endl;
								confirmChoice = confirmChange();
								if (confirmChoice) {
									my_tire_center.setArticles(&dummyTire, i);
									my_tire_center.printArticles();
								}
								else {
									cout << "Tire info was not changed!" << endl;
								}
							}
							else if (typeRead == 'r') {
								Rim dummyRim;
								my_tire_center.modifyArticle(articles_database[i], &dummyRim);
								std::cout << "Changed rim info:" << endl;
								dummyRim.printItem();
								std::cout << endl;
								confirmChoice = confirmChange();
								if (confirmChoice) {
									my_tire_center.setArticles(&dummyRim, i);
									my_tire_center.printArticles();
								}
								else {
									cout << "Rim info was not changed!" << endl;
								}
							}
						}
					}
				}
				break;
				break;
			}
			case 5:
			{
				std::cout << "Ok! Let's update stock." << endl;
				my_tire_center.printArticles();
				std::cout << "We are searching for an article to update by name:" << endl;
				string articleUpdateStock = enterName();
				articles_database = my_tire_center.getArticles();
				std::cout << "We are looking for an article which name is " << articleUpdateStock << endl;
				int n = 0;
				for (int i = 0; i < articles_database.size(); i++) {
					if (articleUpdateStock == articles_database[i]->getName()) {
						n++;
					}
				}
				std::cout << "Found " << n << " entry(ies) with this name." << endl;

				int i = 0;
				while (n > 0) {
					articles_database = my_tire_center.getArticles();
					if (articleUpdateStock == articles_database[i]->getName()) {
						articles_database[i]->printItem();
						std::cout << endl;
						std::cout << "Do you want to update stock for an article which name is " << articleUpdateStock << " and an ID " << i << "?" << endl;
						std::cout << "Press enter..." << endl;

						string changeStockChoice;
						int changedStock;
						cout << "Enter a new stock number (or press enter to skip):" << endl;
						getline(cin, changeStockChoice);
						if (changeStockChoice != "") {
							try {
								if (stoi(changeStockChoice))
								{
									changedStock = stoi(changeStockChoice);

									while (changedStock < 0 || changedStock > 1000 || cin.fail()) {
										if (cin.fail()) {
											cin.clear();
											cin.ignore();
										}
										cout << "Enter a valid stock number(more  or equal to 0 and more or equal to 1000):" << endl;
									}
									bool updateStockAnswer = confirmChange();
									if (updateStockAnswer) {
										my_tire_center.updateStock(i, changedStock);
										my_tire_center.printArticles();
									}
									else {
										std::cout << "Wrong input. Mission aborted." << endl;
									}
								}
								else {
									throw exception{};
								}
							}
							catch (exception) {
								cout << "Non-integer input. Stock number will not be changed." << endl;
							}
						}
						n--;
					}
					i++;
				};

				break;
			}
			case 6:
			{
				std::cout << "Ok! Let's print invoices." << endl;
				std::cout << "Currently we have " << c << " invoice(s) in our database." << endl;
				if (c > 0) {
					for (int i = 0; i < c; i++) {
						invoices[i].printInvoice();
					}
				}
				
				break;
			}
			case 7:
			{
				std::cout << "Ok! Let's add an article." << endl;
				
				char typeChoice = enterArticleType();
				if (typeChoice == 't') {
					my_tire_center.printFilteredArticles('t');
					Tire newTire;
					newTire.setType('t');
					newTire.enterArticle();
					
					std::cout << "A new tire with following data will be created:" << endl;
					newTire.printItem();
					std::cout << endl;
					bool createArticleChoice = confirmChange();
					if (createArticleChoice == true) {
						new_tires[l] = newTire;
						my_tire_center.addArticles(&new_tires[l]);
						l++;
					}
					else {
						std::cout << "A new tire was not created!" << endl;
					}
					
				}
				else if (typeChoice == 'r') {
					my_tire_center.printFilteredArticles('r');
					Rim newRim;
					newRim.setType('r');
					newRim.enterArticle();
					std::cout << "A new rim with following data will be created:" << endl;
					newRim.printItem();
					std::cout << endl;
					bool createArticleChoice = confirmChange();
					if (createArticleChoice == true) {
						new_rims[l] = newRim;
						my_tire_center.addArticles(&new_rims[l]);
						l++;
					}
					else {
						std::cout << "A new rim was not created!" << endl;
					}
				}
				my_tire_center.printArticles();

				break;
			}
			case 8:
			{
				std::cout << "Ok! Let's delete an article." << endl;
				my_tire_center.printArticles();
				cout << "Let's search for an article by name." << endl;
				std::string nameToDelete = enterName();
				articles_database = my_tire_center.getArticles();
				std::cout << "We are looking for an article which name is " << nameToDelete << endl;
				int n = 0;
				for (int i = 0; i < articles_database.size(); i++) {
					if (nameToDelete == articles_database[i]->getName()) {
						n++;
					}
				}
				std::cout << "Found " << n << " entry(ies) with this name." << endl;

				int i = 0;
				while (n > 0) {
					articles_database = my_tire_center.getArticles();
					if (nameToDelete == articles_database[i]->getName()) {
						articles_database[i]->printItem();
						std::cout << endl;
						std::cout << "Delete an article with a name '" << nameToDelete << "' and an ID " << i << "?" << endl;
						std::cout << "Press enter..." << endl;
						bool deleteAnswer = confirmChange();

						if (deleteAnswer) {
							my_tire_center.deleteArticles(i);
							my_tire_center.printArticles();
						}
						else {
							std::cout << "Wrong input. Mission aborted." << endl;
						}
						n--;
					}
					i++;
				};

				break;
			}
			case 9:
			{
				std::cout << "Ok! Let's delete a customer." << endl;
				my_tire_center.printCustomers();
				std::string nameToDelete = enterName();
				clients_database = my_tire_center.getCustomers();
				std::cout << "We are looking for a customer whose name is " << nameToDelete << endl;
				int n = 0;
				for (int i = 0; i < clients_database.size(); i++) {
					if (nameToDelete == clients_database[i]->getName()) {
						n++;
					}
				}
				std::cout << "Found " << n << " entry(ies) with this name." << endl;

				int i = 0;
				while (n > 0) {
					clients_database = my_tire_center.getCustomers();
					if (nameToDelete == clients_database[i]->getName()) {
						clients_database[i]->printInfo();
						std::cout << endl;
						std::cout << "Delete a customer with a name '" << nameToDelete << "' and an ID " << i << "?" << endl;
						std::cout << "Press enter..." << endl;
						bool answer = confirmChange();

						if (answer) {
							my_tire_center.deleteCustomers(i);
							my_tire_center.printCustomers();
						}
						else {
							std::cout << "Wrong input. Mission aborted." << endl;
						}
						n--;
					}
					i++;
				};
				break;
			}
			case 10: 
			{
				my_tire_center.printCustomers();
				break;
			}
			case 11:
			{
				my_tire_center.printArticles();
				break;
			}
			}
			std::cout << "The menu choice execution is completed." << endl;
		} while (mainMenu == 1);
	} while (mainMenu == 0);
	
	return 0;
}