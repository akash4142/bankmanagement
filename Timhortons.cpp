#include <iostream>
#include "Timhortons.h"
#include <fstream>
#include <sstream>
using namespace std;
namespace sdds {

	void Tims::mainmenu() {
		int choice;
		cout << endl << endl;
		cout << "                         *****WELCOME TO THE TIM HORTONS***** " << endl;
		cout << "                              1. MENU LIST " << endl;
		cout << "                              2. KNOW US " << endl;
		cout << "                              3. TO ORDER" << endl;
		cout << "                              4. EXIT" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			menulist();
			break;
		}
		case 2: {
			knowus();
			break;
		}
		case 3: {
			Toorder();
			break;
		}
		case 4: {
			break;
		}

		}
	}
	void Tims::menulist() {
		hotdrinks();
		colddrinks();
		bakedgood();
		
	}
	void Tims::knowus() {
		cout << endl;
		cout << "                                  TIM HORTONS" << endl;
		cout << "In 1964, the first Tim Hortons® restaurant in Hamilton, Ontario opened its doorsand Canadians have been ordering Tim Hortons iconic Original Blend coffee, Double - Double ™ coffees, Donutsand Timbits® ever since.Over the years, Tim Hortons has captured the heartsand taste buds of Canadians.Tim Hortons is now proud to be Canada's largest restaurant chain serving over 5 million cups of coffee every day with 80 % of Canadians visiting a Tims in Canada at least once a month.More than a coffee and bake shop, Tim Hortons is part of the fabric of Canadaand a proud symbol of our countryand its values."

			"We have always had a deep connection to our communitiesand our guests from coast to coast.Our more than 1, 500 restaurant owners are Canadians who live in communities across the country employing over 100, 000 people.Our local Owners and their teams care deeply about the communities they serve.That’s why we provide over $60 million per year to organizations and communities throughout Canada.From signature programs like Timbits® Sports and the Tim Hortons Foundation Camps, we invest in community projectsand initiatives bigand small "<< endl;
		
	}
	void Tims::Toorder() {
		cout << "order function" << endl;

	}
	void Tims::hotdrinks() {
		float smallprice;
		float mediumprice;
		float largeprice;
		char item[40];
		char saved_data[50];
		ifstream inFile;
		inFile.open("hotbrew.txt", ios::binary);
		if (inFile) {
			cout << endl << endl;;
			cout << "                        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "                                            MENU OF TIM HORTONS  " << endl;
			cout << "                                                 HOT BEV       " << endl;
			cout << "                        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "                           ITEM        SMALL     MEDIUM      LARGE " << endl;
			while (!inFile.eof()) {
				inFile.getline(saved_data, 50);
				istringstream ss(saved_data);
				ss >> item >> smallprice >> mediumprice >> largeprice;
				cout << "                         " << item << "         " << smallprice << "        " << mediumprice << "       " << largeprice << "  " << endl;
			}
		}
		else {
			cout << "not open" << endl;
		}
	}

	void Tims::colddrinks() {
		float smallprice;
		float mediumprice;
		float largeprice;
		char item[40];
		char saved_data[50];
		ifstream inFile;
		inFile.open("coldbrew.txt", ios::binary);
		if (inFile) {
			cout << endl << endl << endl;
			cout << "                        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "                                            MENU OF TIM HORTONS  " << endl;
			cout << "                                                 COLD BEV       " << endl;
			cout << "                        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "                           ITEM        SMALL     MEDIUM      LARGE " << endl;
			while (!inFile.eof()) {
				inFile.getline(saved_data, 50);
				istringstream ss(saved_data);
				ss >> item >> smallprice >> mediumprice >> largeprice;
				cout << "                         " << item << "         " << smallprice << "        " << mediumprice << "       " << largeprice << "  " << endl;
			}
		}
		else {
			cout << "not open" << endl;
		}
	}

	void Tims::bakedgood() {
		float price;
		char item[40];
		char saved_data[50];
		ifstream inFile;
		inFile.open("bakeditem.txt", ios::binary);
		if (inFile) {
			cout << endl << endl;
			cout << "                    +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "                                            MENU OF TIM HORTONS  " << endl;
			cout << "                                                 BAKED ITEM       " << endl;
			cout << "                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			cout << "                            ITEM              PRICE " << endl;
			while (!inFile.eof()) {
				inFile.getline(saved_data, 50);
				istringstream ss(saved_data);
				ss >> item >> price;
				cout << "                         " << item << "          " << price << endl;
			}
		}
		else {
			cout << "not open" << endl;
		}
	}
}