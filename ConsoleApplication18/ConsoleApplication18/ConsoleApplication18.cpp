
#include <iostream>
#include<vector>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "Header.h"

using namespace std;

string ReadFromFile() { // function from last semester
    string file, temp, newfile;
    int check = 0;
    vector<string> text_file1;
Check1: // goto loop, used safely
    cout << "Please input source file name\n";
    cin >> file;
    ifstream ifs(file);
    if (ifs.is_open()) {
        while (getline(ifs, temp))
            text_file1.push_back(temp);
    }
    else {
        cout << "Error, The file does not exist \n";
        goto Check1; // goto
    }
    if (text_file1[0] == "") { 
        cout << "File is empty or not valid " << endl;
        exit(0);
    }
    return text_file1[0];
}


vector<double> CheckInput() {
    //string base = ReadFromFile();
    double Balance, Percent, months;
    string input, file;
    vector<double> data;
    input = ReadFromFile();
    input = input + " ";
    string delim = " ";
    vector<string> words{};
    size_t pos = 0;
    while ((pos = input.find(delim)) != string::npos) {
        words.push_back(input.substr(0, pos));
        input.erase(0, pos + delim.length());
    }
    char* c = const_cast<char*>(words[0].c_str());
    Balance = atof(c);
    data.push_back(Balance);
    char* b = const_cast<char*>(words[2].c_str());
    Percent = atof(b);
    data.push_back(Percent);
    char* a = const_cast<char*>(words[3].c_str());
    months = atof(a);
    data.push_back(months);
    return data;
}

vector<double> Calculation() {
    vector<double> data = CheckInput(); //[0]-balance [1]percent [2]months
    vector<double> output;
    double var = 0;
    var = data[0];
    output.push_back(data[0]);
    for (int i = 0; i <= data[2]; i++) {
        output.push_back(var);
        var = (1 + data[1] / 12) * var;

    }
    //for (int i = 1; i <= data[2]; i++) {      //console output
        // cout << i << "  "  << output[i] << endl;
   // }
    return output;
}
void ToFile() {
    vector<double> output = Calculation();
    string file;
    cout << "Please name output file " << endl;
    cin >> file;
    ofstream MyFile(file);
    for (int i = 1; i <= output.size() - 1; i++) {
        MyFile << i - 1 << " " << ToDouble(output[i]) << endl;
        // cout << i-1 << "  "   << ToDouble(output[i]) << endl;
    }

}


//Formula to use newBalance = (1 + percent / 12) * oldBalance
int main()
{
    ToFile();
}

/*
* DoubleConvert();
*
*
*
string ReadFromFile() {
    string file, temp, newfile;
    int check = 0;
    vector<string> text_file1;
Check1: // goto loop, used safely
    cout << "Please input source file name\n";
    cin >> file;
    ifstream ifs(file);
    if (ifs.is_open()) {
        while (getline(ifs, temp))
            text_file1.push_back(temp);
    }
    else {
        cout << "Error, The file does not exist \n";
        goto Check1; // goto
    }
    return text_file1[0];
    }
}


Write a program that read the starting balance, interest rate and number of months from a file.

Example:

1200.43  .08 60

(Balance of $1200.43, 8 percent interest rate, 60 months)

your program will print out a table showing month number and current balance (assume it is compounded monthly) for the number of specified months. 

Your program should prompt the user for the name of the output file.  Use the formatting function you created previously to format the amount.

Example:

0 1,200.43

1 1,208.44

2 1,216.54

etc.



Formula to use newBalance=(1+percent/12)*oldBalance*/