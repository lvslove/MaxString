#pragma once
#pragma once
#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Tommy_gun
{

private:
	vector <char> alphabeth;
	pair <bool, int> resm;
	vector <string> States;
	vector <string> CurrentState, S, F;
	vector<string> str_in, str_out;
	vector<char> str_x;


public:
	Tommy_gun(vector <string> s, vector <char> a, vector<string> str_1, vector<char> str_2, vector<string> str_3, vector <string> ins, vector <string> outs)
	{
		States = s; //количество состояний
		alphabeth = a; //алфавит
		str_in = str_1;//функции перехода
		str_x = str_2;//функции перехода
		str_out = str_3;//функции перехода

		S = ins; //начальные состояния
		F = outs; //заключительные состояния
		//выход
		resm.first = false;//результат
		resm.second = 0;//результат
	}

	pair <bool, int>maxString(string str, int k)//функция вывода максимально допустимой строки с даннной позиции
	{
		resm.first = false;
		resm.second = 0;
		CurrentState = S;
		vector <char>::iterator it;
		if (str.length() == 0 && final(CurrentState)) //если стартовое состояние - заключительное
			resm.first = true;
		else {
			string new_str = "";
			for (int i = k; i < str.length(); i++) //проход по строке
			{
				it = find(alphabeth.begin(), alphabeth.end(), str[i]); //проверка совпадения текущего символа с алфавитом
				if (it == alphabeth.end())
					break;
				else
				{
					new_str += str[i];
					CurrentState = change(CurrentState, str[i]); //смена состояний
					if (final(CurrentState)) //если среди текущих состояний есть заключительное
					{
						resm.first = true;
						resm.second = new_str.length();
					}
				}
			}
		}
		return resm;
	}

	vector <string> change(vector <string> state, char letter) //смена состояний
	{
		vector <string> buff;

		for (vector <string>::iterator j = state.begin(); j != state.end(); j++) {
			for (int i = 0; i < str_in.size(); i++)
				if (str_in[i] == *j && str_x[i] == letter)
					buff.push_back(str_out[i]);



		}

		return buff;
	}

	bool final(vector <string> c) //проверка на заключительное состояние
	{
		vector <string>::iterator it;

		for (vector <string>::iterator i = F.begin(); i != F.end(); i++) {
			it = find(c.begin(), c.end(), *i);
			if (it != c.end())
				return true;
		}

		return false;

	}

	void print_str(string str, int k) //вывод строки
	{
		int length = str.length();
		bool flag = false;
		while (k < length)
		{
			pair <bool, int> result;
			result.first = false;
			result.second = 0;
			result = maxString(str, k);
			if (result.first)
			{
				cout << "true " << k << ' ' << k + result.second << ' ';
				for (int i = k; i < k + result.second; i++)
					cout << str[i];
				cout << endl;
				flag = true;
				k += result.second;
			}
			else
				k++;
		}
		if (!flag)
			cout << "false 0" << endl;
	}

};