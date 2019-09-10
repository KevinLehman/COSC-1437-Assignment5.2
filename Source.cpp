/*
Kevin Lehman  - 1463553
Tarrant County College - COSC 1437- Fall 2017
Assignment 2 - Week 5
*/

#include <iostream>
#include <string>
using namespace std;

void formatMoney(string &);

int main()
{
	string dollarInput = "@";
	const string maxInput = "20000000";
	const string minInput = "0";
	

	while (dollarInput != "X" || dollarInput != "x")
	{
		cout << "Enter your unformatted dollar amount or X to exit: " << endl;
		cin >> dollarInput;

		if (dollarInput == "X" || dollarInput == "x")
		{
			return 0;
		}
		if (dollarInput > maxInput && dollarInput < minInput)
		{
			cout << "Please enter a number from 0-20,000,000" << endl;
			cin >> dollarInput;
		}
		
		formatMoney(dollarInput);

		cout << "Your properly formatted dollar amount is:" << endl;
		cout << dollarInput << endl;
		
	}
	

	system("PAUSE");
	return 0;
}

void formatMoney(string &currency)
{
	int decimal;
	int length;

	length = currency.length();
	decimal = currency.find('.');
	if (decimal < 0)
	{
		currency.resize(length + 3);
		currency.insert((length), ".");
		currency.insert((length + 1), "0");
		currency.insert((length + 2), "0");
		decimal = currency.find('.');
	}
	if (length > decimal + 2)
	{
		currency.erase((decimal + 3), (length - (decimal + 3)));
	}
	if (decimal > 3)
	{
		for (int count = decimal - 3; count > 0; count -= 3)
			currency.insert(count, ",");
	}

	currency.insert(0, "$");
}