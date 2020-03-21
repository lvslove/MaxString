#pragma once
#pragma once
#pragma once
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>

using namespace std;

class Tommy_gun
{

private:
	set <char> alphabeth;
	pair <bool, int> resm;
	set <string> States;
	set <string> CurrentState, S, F;
	vector<string> str_in, str_out;
	vector<char> str_x;


public:
	Tommy_gun(set <string> s, set <char> a, vector<string> str_1, vector<char> str_2, vector<string> str_3, set <string> ins, set <string> outs)
	{
		States = s; //���������� ���������
		alphabeth = a; //�������
		str_in = str_1;//������� ��������
		str_x = str_2;//������� ��������
		str_out = str_3;//������� ��������

		S = ins; //��������� ���������
		F = outs; //�������������� ���������
		//�����
		resm.first = false;//���������
		resm.second = 0;//���������
	}

	pair <bool, int>maxString(string str, int k)//������� ������ ����������� ���������� ������ � ������� �������
	{
		resm.first = false;
		resm.second = 0;
		CurrentState = S;
		set <char>::iterator it;
		if (str.length() == 0 && final(CurrentState)) //���� ��������� ��������� - ��������������
			resm.first = true;
		else {
			string new_str = "";
			for (int i = k; i < str.length(); i++) //������ �� ������
			{
				it = alphabeth.find(str[i]); //�������� ���������� �������� ������� � ���������
				if (it == alphabeth.end())
					break;
				else
				{
					new_str += str[i];
					CurrentState = change(CurrentState, str[i]); //����� ���������
					if (final(CurrentState)) //���� ����� ������� ��������� ���� ��������������
					{
						resm.first = true;
						resm.second = new_str.length();
					}
				}
			}
		}
		return resm;
	}

	set <string> change(set <string> state, char letter) //����� ���������
	{
		set <string> buff;

		for (set <string>::iterator j = state.begin(); j != state.end(); j++) {
			for (int i = 0; i < str_in.size(); i++)
				if (str_in[i] == *j && str_x[i] == letter)
					buff.insert(str_out[i]);



		}

		return buff;
	}

	bool final(set <string> c) //�������� �� �������������� ���������
	{
		set <string>::iterator it;

		for (set <string>::iterator i = F.begin(); i != F.end(); i++)
			if (c.find(*i) != c.end())
				return true;

		return false;

	}

	void print_str(string str, int k) //����� ������
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
				cout << "true " << k << ' ' << k + result.second - 1 << ' ';
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