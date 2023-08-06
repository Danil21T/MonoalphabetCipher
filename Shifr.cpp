#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

int alphabet[256];

int checkingForAMatch(int value) {
	for (int i = 0; i < 256; i++) {
		if (alphabet[i] == value) {
			return 0;
		}
	}
	return value;
}

void generateAlphabet() {
	int symbol;
	srand(time(0));
	for (int i = 0; i < 256; i++) {
		alphabet[i] = 0;
	}
	for (int i = 1; i < 256; i++) {
		do {
			symbol = rand() % 255 + 1;	
		} while (checkingForAMatch(symbol) != symbol);
		alphabet[i] = symbol;
	}
}

void creat(string key) {
	ofstream fout;
	try {
		fout.open(key);
	}
	catch (exception e) {
		cout << e.what();
	}
	generateAlphabet();
	for (int i = 0; i < 256; i++) {
		fout << alphabet[i] << endl;
	}
	fout.close();
}

void readAlphabet(string key) {
	//creat(key);
	ifstream fin;
	try {
		fin.open(key);
	}
	catch (exception e) {
		cout << e.what();
	}
	string s;
	int i = 0;
	int number = 0;
	while (getline(fin, s)) {
		if (i < 256) {
			for (char chr : s)
			{
				if (chr >= '0' && chr <= '9') {
					number = number * 10 + (int)(chr - 48);
				}
				
			}
			alphabet[i] = number;
			i++;
			number = 0;
		}
				
	}
	fin.close();
}

void textEncryption(string name, string name2) {
	ifstream fin;
	ofstream fout;
	try {
		fin.open(name);
		fout.open(name2);
	}
	catch (exception e) {
		cout << e.what();
	}
	string s;
	while (getline(fin,s)) {
		if (!fin.eof())
			s += "\n";
		
		for (int i = 0; i < s.size(); i++) {
			fout << (char)alphabet[(int)(s[i]&255)];
		}
	}
	fout.close();
	fin.close();
}

int searchForTheSymbolKey(int symbol) {
	for (int i = 0; i < 256; i++) {
		if (alphabet[i] == symbol) {
			return i;
		}
	}
	return 0;
}


void decryptionOfTheText(string name, string name2) {
	ifstream fin;
	ofstream fout;
	try {
		fin.open(name);
		fout.open(name2);
	}
	catch (exception e) {
		cout << e.what();
	}
	string s;
	while (getline(fin, s)) {
		if (!fin.eof())
			s += "\n";
		for (int i = 0; i < s.size(); i++) {
			fout << (char)searchForTheSymbolKey((int)(s[i] & 255));
		}
	}
	fout.close();
	fin.close();
}