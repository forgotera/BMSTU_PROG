#include <conio.h>
#include <iostream>

using namespace std;
int n;

bool input()
{
	cout << "�� ������ ����� ��������� �� ����������?" << endl;
	if (!(cin >> n))
	{
		cout << "���� �� ������" << endl; return false;
	}
	else return true;
}

bool palindrom(int a)
{
	int k=0;//������������ �����
	int sq = a*a;
	int s = sq;
	while (s!=0)
	{
		k = k * 10 + s % 10;//�������������� ����� 
		s = s / 10;// ����������� ���������� ����� 
	}
	if (sq == k) return true;
	else return false;
}

void print(int a)
{
	cout << a << "\t" << a*a << "-���������"<<endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	while(!(input()));
	for (int i(1); i <= int(sqrt(n)); i++)
	{
		if (palindrom(i)) print(i);
		
	}
	_getch();
	return 0;
}