#pragma once

#include <iostream>
#include <string>
#include <sstream>
#pragma warning(disable : 4996)
using namespace std;
string ToDouble(double number) {
	stringstream stream;
	double CuttedNumber = number;
	int dotposition = 0;
	stream.precision(2);
	stream << fixed;
	stream << CuttedNumber;
	string str = stream.str();
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '.') {
			dotposition = i;
		}
	}
	char ch[sizeof(str)];
	for (int i = 0; i < str.length(); i++) {
		ch[i] = str[i];
	}
	for (int i = dotposition + 1; i > 2; i -= 3) {
		if (i == dotposition || i == dotposition + 1) {
		}
		else {
			for (int j = sizeof(ch); j >= i; j--) {
				ch[j] = ch[j - 1];
			}
			ch[i -1] = ',';
		}
	}
	string s = "";
	string checkf = "0123456789.,-";
	for (int i = 0; i < sizeof(ch) - 1; i++) {
		for (int j = 0; j < 14; j++) {
			if (ch[i] == checkf[j]
				) {
				s = s + ch[i];
			}
		}
	}
	//cout << s;
	return s;
}
