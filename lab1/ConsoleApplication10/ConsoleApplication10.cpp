#include<stdafx.h>
#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "определ€ем количество палиндромов" << endl;
	const int sq = sqrt(500);
	int kvadrat = 0;
	for (int i = (1); i <= sq; i++)
	{
		kvadrat = i*i;
		if ((kvadrat / 100) == (kvadrat % 10))
			cout << i << '\t' << kvadrat << '\t' << " ѕалиндром\n";
	}
	_getch();
	return 0;
}