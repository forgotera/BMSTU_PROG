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
	{																								 // �������� �����//
		for (int j = 0; j < n; j++)                                                                 ////////////////////
		{
			cout << "������� ������� ������� � �������� [ " << i + 1 << " ]" << " [ " << j + 1 << " ]\n";
			while (!(cin >> ar[i][j]))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "������� ������� ������� � �������� [ " << i + 1 << " ]" << " [ " << j + 1 << " ]\n";
			}
		}
	}
	system("cls");
	cout << "�������� �������" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{                                                                                            ////////////////
			cout << "[" << ar[i][j] << "]";															//����� �������//
		}																							/////////////////
		cout << endl;
	}
	double  m = 0;
	int q = 0, w = 0;
	cout << "��������������� �������" << endl;
	for (int i = 0; i < n; i++)
	{
		m = ar[0][i];
		for (int j = 1; j < n; j++)
		{
			if (ar[j][i] > m) {
				m = ar[j][i];																		//���������� � �������
				q = j; w = i;																		// ������ �����������
			}
		}
		m = ar[q][w];																			/////////////////////////////////////
		ar[q][w] = ar[i][i];																	//������ ����������� � ������������// 
		ar[i][i] = m;																			/////////////////////////////////////
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{                                                                                            ////////////////
			cout << "[" << ar[i][j] << "]";															//����� �������//
		}																							/////////////////
		cout << endl;
	}
	cout << "�������" << endl;
	//���������� ������� �������� ������ ������� �������
/*	[3] [2] [1]		[00] [01] [02]
	[4]	[9]	[8]		[10] [11] [12]
	[5] [6] [7]	    [20] [21] [22]    */
	int k=0,z=0;
	int x = 1;
	do
	{
		// ����
		for (int i(n - x); i >= z; i--)
		{
			k++;
			ar[z][i] = k;
			if (k == n*n)
				goto stop;
		}

		//����
		for (int i(x); i < n-z; i++)
		{
			k++;
			ar[i][z] = k;
			
			if (k == n*n)
				goto stop;
		}
		//�����
		for (int i(x); i < n-z; i++)
		{
			k++;
			ar[n - x][i] = k;
			if (k == n*n)
				goto stop;
		}

		//�����
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
			cout << "[" << ar[i][j] << "]";															//����� �������//
		}																							/////////////////
		cout << endl;
	}


	_getch();
	return 0;

}