/*

 *Author: Wasim Algamal

 *Creation Date: 09/19/2020

 *Modification Date: 09/23/2020

 *Purpose: Print monthly sales based on user month selection using 3d arrays

*/

using namespace std;
#include <iostream>
#include <iomanip>
#include <string>

const int NUM_DEPTS = 2;
const int NUM_STORES = 2;
const int NUM_MONTHS = 12;

void printMonthlySales(int monthValue, float arr[NUM_STORES][NUM_MONTHS][NUM_DEPTS]) {
	int month = monthValue - 1;
	float sumStoreOne = 0, sumStoreTwo = 0, sumDepartmentOne = 0, sumDepartmentTwo = 0, totalSales = 0;

	cout << setw(30) << "Sales for the Month of ";

	switch (month + 1) {
	case 1:  cout << "January" << endl; break;
	case 2:  cout << "February" << endl; break;
	case 3:  cout << "March" << endl; break;
	case 4:  cout << "April" << endl; break;
	case 5:  cout << "May" << endl; break;
	case 6:  cout << "June" << endl; break;
	case 7:  cout << "July" << endl; break;
	case 8:  cout << "August" << endl; break;
	case 9:  cout << "September" << endl; break;
	case 10: cout << "October" << endl; break;
	case 11: cout << "Novemeber" << endl; break;
	case 12: cout << "December" << endl; break;
	default: cout << "ERROR" << endl; break;
	}

	cout << setw(45) << setfill('=') << "\n";
	cout << setw(20) << setfill(' ') << "DEPT1 |" << setw(9) << "DEPT2 |" << setw(13) << "STORE TOTALS" << endl;
	cout << "            " << "---------------------------------\n";

	//print formatting

	for (int i = 0; i < NUM_STORES; i++) {
		cout << "STORE" << i + 1 << "      | ";

		for (int j = 0; j < NUM_DEPTS; j++) {
			cout << arr[i][month][j] << "     ";

			if (i == 0) {
				sumStoreOne += arr[i][month][j];
			}
			else if (i == 1) {
				sumStoreTwo += arr[i][month][j];
			}

			if (j == 0) {
				sumDepartmentOne += arr[i][month][j];
			}
			else if (j == 1) {
				sumDepartmentTwo += arr[i][month][j];
			}
			totalSales += arr[i][month][j];
		}

		if (i == 0) {
			cout << sumStoreOne << endl;
		}
		else if (i == 1) {
			cout << sumStoreTwo << endl;
		}
	}

	if ((sumDepartmentOne + sumDepartmentTwo) != (sumStoreOne + sumStoreTwo)) {
		cout << "WARNING: INCORRECT DATA FROM SYSTEM! SYSTEM WILL NOW SHUT DOWN!";
		exit(0);
	}
	//kind of like an assertion; ensures totals add up

	cout << "DEPT TOTALS | " << sumDepartmentOne << "     " << sumDepartmentTwo << "     " <<
		totalSales << "---> Total Sales" << endl << endl;
}
//function that prints array

int main() {
	char sentinel = 'y';
	int userInput = 0;
	bool validInput, validInput1;
	string stringInput;
	float storeMonthlySales[NUM_STORES][NUM_MONTHS][NUM_DEPTS] =
	{
	  {{1.1, 1.2} , {1.3, 1.4} , {1.5, 1.6} , {1.7, 1.8} , {1.9, 2.0} , {2.1, 2.2} ,
	  { 2.1, 2.2} , {2.3, 2.4} , {2.5, 2.6} , {2.7, 2.8} , {2.9, 3.0} , {3.1, 3.2}},
	  {{3.1, 3.2} , {3.3, 3.4} , {3.5, 3.6} , {3.7, 3.8} , {3.9, 4.0} , {4.1, 4.2} ,
	  { 2.1, 2.2} , {2.3, 2.4} , {2.5, 2.6} , {2.7, 2.8} , {2.9, 3.0} , {3.1, 3.2} }
	};

	while (sentinel == 'y') {

		cout << "Please select a month from the below options (Enter only the number):" << endl <<
			"1.   January" << endl <<
			"2.   February" << endl <<
			"3.   March" << endl <<
			"4.   April" << endl <<
			"5.   May" << endl <<
			"6.   June" << endl <<
			"7.   July" << endl <<
			"8.   August" << endl <<
			"9.   September" << endl <<
			"10.  October" << endl <<
			"11.  Novemeber" << endl <<
			"12.  December" << endl;

		stringInput.clear();
		//ensures string is clear for use
		cin >> stringInput;
		cout << endl;

		if (stringInput.size() > 2) {
			cout << "ERROR! You have entered an invalid month number! Try again: " << endl << endl;
			validInput = false;
		}
		else {
			userInput = stoi(stringInput);
			validInput = true;
		}
		//ensures decimals are not accepted and then convert to int

		if (validInput == true) {
			if (userInput < 1 || userInput > 12) {
				cout << "ERROR! You have entered an invalid month number! Try again:" << endl << endl;
				validInput1 = false;
			}
			else if (userInput >= 1 || userInput <= 12) {
				validInput1 = true;
			}
			//ensures user inputs a valid # 1-12

			if (validInput1 == true) {
				printMonthlySales(userInput, storeMonthlySales);

				do {

					cout << "Would you like to select another month? (enter \"y\" for yes or \"n\" for no)" << endl;
					cin >> sentinel;
					cout << endl;

					if (sentinel == 'y') {
						break;
					}
					else if (sentinel == 'n') {
						exit(0);
					}
					else {
						cout << "ERROR! You have entered something other than \"y\" or \"n\", try again." << endl << endl;
					}

				} while (sentinel != 'y');
				//loops if user did not enter a proper char
			}
		}
	}
	return 0;
}
