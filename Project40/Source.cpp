#include <iostream>
#include <fstream>
#include "Tommy_gun.h"

int main()
{
	setlocale(LC_ALL, "rus");
	pair <bool, int> result;
	string path = "Tommy_gun.txt";
	bool stop = false;
	string menu = "";
	vector<string> str_1;
	vector<char> str_2;
	vector<string> str_3;
	int z, k;
	string state, str, str2, str3;
	char letter;
	vector <char> a;
	vector <string> s, ins, outs;


	ifstream in;
	in.open(path);
	if (in.is_open()) // файл успешно открыт
	{
		in >> z;
		getline(in, state);
		for (int i = 1; i <= z; i++)
		{
			getline(in, state);
			s.push_back(state);
		}

		in >> z;
		char letter;
		for (int i = 0; i < z; i++)
		{
			in >> letter;
			a.push_back(letter);
		}

		in >> z;
		getline(in, str);
		for (int i = 0; i < z; i++)
		{
			str = str2 = str3 = "";
			int j = 0;
			getline(in, str);
			while (isalpha(str[j]) != 0)
			{
				str2 += str[j];
				j++;
			}

			letter = str[j + 1];

			for (int l = j + 3; l < str.length(); l++)
				str3 += str[l];


			str_1.push_back(str2);
			str_2.push_back(letter);
			str_3.push_back(str3);



		}

		in >> z;
		getline(in, state);
		for (int i = 0; i < z; i++)
		{
			getline(in, state);
			ins.push_back(state);
		}

		in >> z;
		getline(in, state);
		for (int i = 0; i < z; i++)
		{
			getline(in, state);
			outs.push_back(state);
		}

	}
	in.close();





	Tommy_gun automato(s, a, str_1, str_2, str_3, ins, outs);

	int ch, y = 0;
	result.first = false;
	result.second = 0;
	do
	{
		cout << "\nНахождение всех допустимых слов и вывод максимальной длинны допустимого слова";
		cout << "\n 1. Все слова строки  ";
		cout << "\n 2. Слово максимальной длинны c заданной позиции";
		cout << "\n 3. Выход ";
		cout << "\nВыбор действия: "; cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Введите строку" << endl;
			cin >> str;
			cout << "Введите позицию ";
			cin >> k;
			automato.print_str(str, k);
			break;
		case 2:
			cout << "Введите строку: " << endl;
			cin >> str;
			cout << "Введите позицию: " << endl;
			cin >> k;
			result = automato.maxString(str, k);
			if (result.first == 0)
				str = "false";
			else
				str = "true";
			cout << str << ' ' << result.second << endl;
			break;
		case 3: y = 1;
			break;
		default: cout << "\nВыбор действия.";
		}
		cout << endl;
	} while (y != 1);

}   