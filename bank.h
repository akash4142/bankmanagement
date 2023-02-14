#pragma once
#ifndef SDDS_BANK_H
#define SDDS_BANK_H

namespace sdds {
	class Bank {
		int count;
		int pass;
		char* name;
		int acc_num;
		int mob_no;
		double deposit;
	public:
		Bank();
		~Bank();
		int menu(); //display the menu
		void takeinput(); //it takes the data for the registration
        bool login();//it takes the login details
		void afterlogin();//this controls the data after the login 
		void aboutus(); // tell us about me
		void display(); // display the data 
		Bank& operator ++ (); //is used to track the total data
		void fileuploading(const char* name, int pass,double price , int acc_num); //uploads the data into the file
		void modify_account();//this i to modify the details of the account holder
		void balance_account();// this is to check the balance details
		void delete_account();// this is to delete the account
		void deposit_withdrawal();// this is to either to deposit ir the withdrawal
    };
}
#endif // !SDDS_BANK_H

