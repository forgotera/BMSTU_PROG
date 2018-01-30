#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 3;
	double ar[n][n];
	int a(0);
	for (int i = 0; i < n; i++)                                                                       //////////////////	
	{																								 // Проверка Ввода//
		for (int j = 0; j < n; j++)                                                                 ////////////////////
		{
			cout << "Введите элемент массива с индексом [ " << i + 1 << " ]" << " [ " << j + 1 << " ]\n";
			while (!(cin >> ar[i][j]))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Введите элемент массива с индексом [ " << i + 1 << " ]" << " [ " << j + 1 << " ]\n";
			}
		}
	}
	system("cls");
	cout << "Исходная матрица" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{                                                                                            ////////////////
			cout << "[" << ar[i][j] << "]";															//Вывод матрицы//
		}																							/////////////////
		cout << endl;
	}
	double  m = 0;
	int q = 0, w = 0;
	cout << "Преобразованная матрица" << endl;
	for (int i = 0; i < n; i++)
	{
		m = ar[0][i];
		for (int j = 1; j < n; j++)
		{
			if (ar[j][i] > m) {
				m = ar[j][i];																		//наибольшее в столбце
				q = j; w = i;																		// индекс наибольшего
			}
		}
		m = ar[q][w];																			/////////////////////////////////////
		ar[q][w] = ar[i][i];																	//Замена наибольшего с диогональным// 
		ar[i][i] = m;																			/////////////////////////////////////
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{                                                                                            ////////////////
			cout << "[" << ar[i][j] << "]";															//Вывод матрицы//
		}																							/////////////////
		cout << endl;
	}
	cout << "СПИРАЛЬ" << endl;
	//Заполнение матрицы спиралью против часовой стрелки
/*	[3] [2] [1]		[00] [01] [02]
	[4]	[9]	[8]		[10] [11] [12]
	[5] [6] [7]	    [20] [21] [22]    */
	int k=0,z=0;
	int x = 1;
	do
	{
		// лево
		for (int i(n - x); i >= z; i--)
		{
			k++;
			ar[z][i] = k;
			if (k == n*n)
				goto stop;
		}

		//вниз
		for (int i(x); i < n-z; i++)
		{
			k++;
			ar[i][z] = k;
			
			if (k == n*n)
				goto stop;
		}
		//право
		for (int i(x); i < n-z; i++)
		{
			k++;
			ar[n - x][i] = k;
			if (k == n*n)
				goto stop;
		}

		//вверх
		for (int i(n - x-1); i >= x; i--)
		{
			k++;
			ar[i][n - x] = k;
		
			if (k == n*n)
				goto stop;
		}
		x++;
		z++;
	} while (k != n*n);
	stop:
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{                                                                                            ////////////////
			cout << "[" << ar[i][j] << "]";															//Вывод матрицы//
		}																							/////////////////
		cout << endl;
	}


	_getch();
	return 0;

}