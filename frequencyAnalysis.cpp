#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int alphabetT[256];
int trueAlphabet[256];
int shifrAlphabet[256];

void frequencyAnalysis() {
	ifstream f;
	f.open("Text.txt");
	string s;
	for (int j = 0; j < 256; j++) {
		alphabetT[j] = 0;
	}
	while (getline(f, s)) {
		if (f.eof()) {
			s += "\n";
		}
		for (int i = 0; i < s.size(); i++) {
			alphabetT[(int(s[i] & 255))]++;
		}
	}
	for (int u = 0; u < 256; u++) {
		if (alphabetT[u] != 0) {
			cout << (char)u << " " << alphabetT[u] << endl;
		}
	}
}

/*void alphabetSee() {
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < 256; i++) {
		if (trueAlphabet[i] != 0) {
			cout << "Ñטלגמכ " << i << " גסענוקאועüסÿ " << trueAlphabet[i] << endl;
		}
	}
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 256; i++) {
		if (shifrAlphabet[i] != 0) {
			cout << "Ñטלגמכ " << i << " גסענוקאועüסÿ " << shifrAlphabet[i] << endl;
		}
	}
}*/

void textEncryptionFrequencyAnalysis(string name, string name2) {
	ofstream fout;
	ifstream fin;
	try {
		fout.open(name2);
		fin.open(name);
	}
	catch (exception e) {
		cout << e.what();
	}

	string s;
	while (getline(fin, s)) {
		if (!fin.eof())
			s += "\n";
		for (int z = 0; z < s.size(); z++) {
			int code = (int)s[z] & 255;
				for (int i = 0; i < 256; i++) {
					if (trueAlphabet[i] == shifrAlphabet[code]) {
						trueAlphabet[i]--;
						shifrAlphabet[code]--;
						fout << (char)i;
						break;
					}
				}
		}
	}
	fin.close();
	fout.close();
}

long long int factorial(int value) {
	long long int result = 1;
	for (int i = 2; i <= value; i++) {
		result = result * i;
	}
	return result;
}

long long int uniquenessDistance() {
	return log2l((factorial(256) / log2(256)));
}