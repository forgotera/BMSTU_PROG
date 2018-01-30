#include <conio.h>
#include <iostream>

using namespace std;
int n;

bool input()
{
	cout << "ƒо какого числа провер€ть на палиндромы?" << endl;
	if (!(cin >> n))
	{
		cout << "¬вод не удалс€" << endl; return false;
	}
	else return true;
}

bool palindrom(int a)
{
	int k=0;//перевернутое число
	int sq = a*a;
	int s = sq;
	while (s!=0)
	{
		k = k * 10 + s % 10;//переворачиваем число 
		s = s / 10;// вычеркиваем последннее число 
	}
	if (sq == k) return true;
	else return false;
}

void print(int a)
{
	cout << a << "\t" << a*a << "-ѕалиндром"<<endl;
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