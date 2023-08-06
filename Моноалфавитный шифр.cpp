#include <iostream>
#include <locale>
#include "Shifr.h"
#include "frequencyAnalysis.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choise = 0;
	do {
		cout << "Выберите способ задания ключа: \n1. Ввод своего ключа из файла(десятичный код для каждого значения в алфавитном порядке).\n2. Рандомное задание ключа. \nВыбор: ";
		cin >> choise;
	} while (choise != 1 && choise != 2);
	cout << "Введите название шифруемого файла:" << endl;
	string name;
	cin >> name;
	cout << "Введите название файла(или полный путь) для зашифрованного текста:" << endl;
	string name2;
	cin >> name2;
	cout << "Введите название файла(или полный путь) для расшифрованного текста:" << endl;
	string name3;
	cin >> name3;
	if (choise == 1) {
		cout << "Введите название файла с ключом для шифра(или полный путь)" << endl;
		string key;
		cin >> key;
		readAlphabet(key);
		textEncryption(name, name2);
		decryptionOfTheText(name2, name3);
	}
	if (choise == 2) {
		generateAlphabet();
		textEncryption(name, name2);
		decryptionOfTheText(name2, name3);
	}
	
	//frequencyAnalysis();
	//frequencyAnalysis("Text1.txt");
	//alphabetSee();
	//textEncryptionFrequencyAnalysis(name2, "Text3.txt");

	return 0;
}
