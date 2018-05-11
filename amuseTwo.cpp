// Author:			Logan Hammond; hamm32637@email.ccbcmd.edu; Febuary 5, 2018
// Source file:		amuseTwo.cpp
// Description:		Changes to amuseOne.cpp
// IDE used:		Microsoft Visual Studio 2017

#include <iostream>
#include <iomanip>
using namespace std;

const double CHILDPRICE = 12.00, ADULTPRICE = 26.50;

int main() {
	int adultTix, childTix = 0, confirmNum = 100;
	double adultTotal, childTotal, totalBill, amountPaid = 0;

	cout << "\n\n\n\t\t Chesapeake Amusement Park" << endl << endl;
	cout << "     Enter number of children or -1 to stop: ";
	cin >> childTix;
	while (childTix != -1) {
		cout << "     Enter number of adults                : ";
		cin >> adultTix;

		childTotal = CHILDPRICE * childTix;
		childTotal -= (childTix / 4) * CHILDPRICE;		// Every fourth child is free

		adultTotal = ADULTPRICE * adultTix;
		if (adultTix >= 5) {							// Reduces total adult cost by 3 if 5 or more adults are present
			adultTotal -= 3;
		}

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

		cout << "\n\n                 Chesapeake Amusement Park";
		cout << "\n                 -------------------------";
		cout << "\n\n               Tickets      Price      Total\n";
		cout << "     Children   " << setw(3) << childTix
			<< setw(14) << CHILDPRICE
			<< setw(11) << childTotal;

		cout << "\n     Adults     " << setw(3) << adultTix
			<< setw(14) << ADULTPRICE
			<< setw(11) << adultTotal;

		cout << "\n     Total" << setw(9) << (childTix + adultTix) << setw(25) << (childTotal + adultTotal);

		if ((childTix + adultTix) > 20 || childTix >= 14) {
			cout << "\n\n     Security Fee" << setw(27) << "15.00";
			totalBill = childTotal + adultTotal + 15;
			cout << "\n\n     Total Bill" << setw(29) << totalBill;
		}
		else {
			totalBill = childTotal + adultTotal;
			cout << "\n\n     Total Bill" << setw(29) << totalBill;
		}

		do {
			cout << "\n\n     Amount Paid: ";
			cin >> amountPaid;
			if (amountPaid - totalBill < 0) {
				cout << "\n     Insufficient funds. Try again.";
			}
		} while ((amountPaid - totalBill) < 0);

		cout << "\n     Change Due:" << setw(27) << (amountPaid - totalBill);
		cout << "\n     Confirmation #: " << confirmNum;
		confirmNum++;

		cout << "\n\n\n\t\t Chesapeake Amusement Park" << endl << endl;
		cout << "     Enter number of children or -1 to stop: ";
		cin >> childTix;
	}

	cout << endl << endl << "     ";
	system("pause");
	return 0;
}