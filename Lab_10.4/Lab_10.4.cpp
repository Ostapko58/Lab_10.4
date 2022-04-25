#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;

void Input(const char* filename)
{
	ofstream f;
	f.open(filename);
	string tmp;
	cout << "������ ��� �����: " << endl;
	do
	{
		getline(cin, tmp,'\n');
		if (tmp == "end")
		{
			break;
		}
		f << tmp;
		f << '\n';
		/*cout << "�� ������ ����������"; cin >> menu;
		cin.get(); cin.sync();
		cout << endl;*/
	} while (tmp != "end");
	f.close();
}

//void Print()
//{
//	string line;
//	ifstream f2("a1.txt");
//	while (getline(f2, line))
//	{
//		cout << line << endl;
//	}
//	f2.close();
//}

void WordWithGolosnii(const char* filename1,const char* filename2,bool& are_open)
{
	string line,word,max_word;
	int num = 1, pos, finish, count, max;
	fstream f(filename1);
	if (!f.is_open())
	{
		cout << "������ ����� �� ����" << endl;
		are_open = false;
		return;
	}

	ofstream f2(filename2);
	//cin.get(); cin.sync();
	while (getline(f, line))
	{
		if (num%2==0)
		{
			f2 << line;
			f2 << '\n';
			num++;
		}
		else
		{
			pos = 0;
			max = 0;
			while ((pos=line.find_first_not_of(" ,.-_", pos)) != -1)
			{
				count = 0;
				finish = line.find_first_of(" ,.-_", pos)-1;
				if(finish == -1)
				{
					finish = line.length() - 1;
				}
				word = line.substr(pos, (finish - pos)+1);
				for (int i = 0; i < word.length(); i++)
				{
					if (word[i]=='�'|| word[i] == '�' || word[i] == '�' || word[i] == '�' || word[i] == '�' || word[i] == '�' || word[i] == '�' || word[i] == '�' || word[i] == '�' || word[i] == '�')
					{
						count++;
					}
				}
				if (max<count)
				{
					max = count;
					max_word = word;
				}
				pos = finish + 1;

			}
			f2 << line + ' ' + max_word;
			f2 << '\n';
			num++;
		}
		
	}
	f.close();
	f2.close();

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menuItem;
	bool are_open;
	char filename1[60],filename2[60];
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ������ ����� � ��������� ������� ��������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;
		cin.get(); cin.sync();
		switch (menuItem)
		{
		case 1:
			cout << "������ ����� �����: "; cin.getline(filename1,60);
			cout << "��� �������� ������ end." << endl;
			Input(filename1);
			break;
		case 2:
			/*cout << "������ ����� ����� ��� �����������: "; cin.getline(filename1, 60);
			cout << "������ ����� ����� ��� ���������: "; cin.getline(filename2, 60);
			WordWithGolosnii(filename1, filename2,);*/
			do
			{
				cout << "������ ����� ����� ��� �����������: "; cin.getline(filename1, 60);
				cout << "������ ����� ����� ��� ���������: "; cin.getline(filename2, 60);
				are_open = true;
				WordWithGolosnii(filename1, filename2,are_open);
			} while (!are_open);

			break;
		case 0:
			break;
		default:
			cout << "�� ����������, ���������� �����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}