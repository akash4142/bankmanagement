#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "bank.h"
#include <cstring>
#include <sstream>
#include <fstream>
using namespace std;
namespace sdds {
	Bank::Bank() {
		name= nullptr;                                       //default constructor
		acc_num = 0;
	}


	Bank::~Bank() {
		delete[] name;                                        //destructors
		name = nullptr;
	}


	int Bank::menu() {
		int flag=0,choice;
		do{
			cout << endl << endl;
			cout << "                         1. NEW ACCOUNT REGISTRATION" << endl;
			cout << "                         2. EXISTING USER"<<  endl;                         //show menu
			cout << "                         3. ABOUT US" <<endl;
			cout << "                         4. TIM HORTONS" << endl;
			cout << "                         5. Exit" <<endl;
			cout << "                         Enter your choice :: ";
		    cin >> choice;
			return choice;
		} while (flag == 0);
	}


	void Bank::takeinput() {
		char input_name[40];//taking input from the user 
		cout <<"                     Enter your name ::" ;
		cin >> input_name;
		name = new char[strlen(input_name) + 1];
		strcpy(name, input_name);
		cout << "                     Enter the account number :: " ;
		cin >> acc_num;
		cout << "                     Enter your mobile number :: " ;
		cin >> mob_no;
		cout << "                       Enter the password :: ";
		cin >> pass;
		cout << "                      How many money you want to deposit :: ";                     //take input
		cin >> deposit;
		fileuploading(name, pass, acc_num, deposit);
		cout << "++++ CONGRATS , YOU HAVE BEEN REGISTERED WITH US . I HOPE YOU WILL ENJOY OUR SERVICES . ++++" << endl;
		cout << "                             THANK YOU SO MUCH . I AM LOOKING FORWARD TO HELP YOU." << endl;
	}


	bool Bank::login() {                       //login input from the user 
		int flag = 0;
		char input_name[40];
		cout << "                     Enter your name ::";
		cin >> input_name;
		char saved_data[50];
		char saved_name[40];
		int saved_pass;
		int saved_acc_no;
		name = new char[strlen(input_name) + 1];                                              //login
		strcpy(name, input_name);
		cout << "                       Enter the password :: ";
		cin >> pass;
		cout << "                     Enter the account number :: ";
		cin >> acc_num;
		ifstream inFile;
		inFile.open("account.dat", ios::binary);
		if (inFile) { 
			while (!inFile.eof()) {
				inFile.getline(saved_data, 50);
				istringstream ss(saved_data);
				ss >> saved_name >> saved_pass >> saved_acc_no;
				if (saved_acc_no == acc_num && saved_pass == pass) {
					flag = 1;
					break;
				}
				else {
					flag = 0;
				}
			}
			if (flag == 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			cout << "not open";

		}
	}


	void Bank::aboutus() {
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "This is the application developed by the akash yadav . I am student at seneca college doing my bachelors in computer science . " << endl;
		cout << "I am currently doing my internship as the software developer at GAOTEK INC . In which , I am working in the team of 10 people who are testing and maintaining codes . " << endl;
		cout << "This project has been made to practice the different topics of object oriented programming .It includes dynamic memory allocation ,  operator overloading and module programming " << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	}


	void Bank::display() { //helper function to display the details 
		cout << "                      Name is :: " << name<< endl; 
		cout << "                      Account number :: " << acc_num << endl;
		cout << "                      Deposit :: " << deposit <<endl;
		cout << "count is :: "<<count;
	}


	Bank& Bank::operator ++ () {//operator
		count += 1;
		return *this;
	}


	void Bank::fileuploading(const char* name, int pass,double price,int acc_num) {//upload the data into the file of the user
		ofstream outFile("account.dat", ios::binary | ios::app);
		outFile << name << " " << pass << " " << acc_num << " " << price << '\n';
		outFile.close();
	}
	
	void Bank::afterlogin() {//this function is executes after the the login 
		int choice;
		cout << "+++++++++++++++*******    SUCCESSFULLY LOGGED IN    *******+++++++++++++++++" << endl;
		cout << "1. Modify account " << endl;
		cout << "2. Balance enquiry " << endl;
		cout << "3. Delete the account " << endl;
		cout << "4. Deposit or Withdrawal " << endl;
		cout << "5. To Back" << endl;
		cin >> choice;
		switch (choice) {
		case 1: {
			 modify_account();
			 break;
		}
		case 2: {
			 balance_account();
			 break;
		}
		case 3: {
			 delete_account();
			 break;
		}
		case 4: {
		    deposit_withdrawal();
			break;
		}
		case 5: {
			break;
		}
		
		}
	}

	void Bank::modify_account(){
		cout << "modify account " << endl;


	}
	void Bank::balance_account() {
		cout << "balance account " << endl;
	}
	void Bank::delete_account() {
		cout << "delete account" << endl;
	}
	void Bank::deposit_withdrawal() {
		cout << "deposit " << endl;
	}

}