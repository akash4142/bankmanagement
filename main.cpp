#include <iostream>
#include "bank.h"
#include "Timhortons.h"
#include <fstream>
using namespace std;
using namespace sdds;
int main() {
	int choice = 0,flag= 1;
	bool ret;
	Tims t1;
	Bank b1;
	cout << "                             +-------------------------------------------------------+" << endl;
	cout << "                             ******WELCOME TO THE BANK MANAGEMENT PROJECT******" << endl;
	cout << "                                                                  Developed by - Akash yadav" << endl;
	cout << "                             +-------------------------------------------------------+" << endl;
	
	do {
		choice = b1.menu();

		switch (choice) {
		case 1: {
			b1.takeinput();
			break;
		}
		case 2: {
			ret = b1.login();
			do {
				if (ret) {
					b1.afterlogin();
					break;
				}
				else {
					cout << "you don't have account with us" << endl;
					break;
				}
			} while (true);
			break;
		}
		case 3: {
			b1.aboutus();
			break;
		}
		case 4: {
			t1.mainmenu();
		}
		case 5:
			flag = 0;
			break;
		}
	} while (flag);
	
}