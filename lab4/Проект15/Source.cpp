#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char *str = new char[255];
	cin >> str;
	cout << "строка: " << str << endl;
	int n(0), m(0), k, l;
	for (int i(0); i < strlen(str); i++)
	{
		if (str[i] == '(') n++;
		if (n == 2)
		{
			i++;
			do
			{
				cout << "str[" << i << "] = " << str[i] << " = 0x" << (int)(&str[i]) << endl;
				i++;
			} while (str[i] !=')');
			
		}
		if (str[i] == ')') m++;
	}
	if (n == m) cout << "порядок верен" << endl;
	else cout << "порядок не верен" << endl;
	delete [] str;
	_getch();
	return 0;
}