#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include<cstdlib>
#include <cstdio>

using namespace std;
const int BOOKS_AMOUNT = 100;
const int SIZE_NUMBER = 100;
const int SIZE_CHAR = 2;

struct myStruct
{
	char name[10];
	int number[100];
};

struct indexFromFile
{
	string name;
	size_t number;
};

int main()
{
	myStruct zap;
	fstream fout;
	indexFromFile zapF;
	map<string, size_t> index;
	fout.open("output.txt", ios_base::out);
	srand(time(NULL));
	//рандомим записи в файл
	for (int i(0); i < BOOKS_AMOUNT; i++)
	{
		for (int x(0); x < SIZE_CHAR; x++)
		{
			zap.name[x] = rand() % 26 + 65;
		}
		zap.name[SIZE_CHAR + 1] = '\0';
		for (int j(0); j < SIZE_NUMBER; j++)
		{
			zap.number[j] = rand() % 1000;
		}
		fout << zap.name;
		fout << " ";
		fout << zap.number;
		fout << " ";
	}
	fout.close();
	fout.open("output.txt", ios_base::in);
	if (!fout)
	{
		cout << "file fou not open";
	}
	ofstream fin;
	fin.open("input.txt", ios_base::out);
	if (!fin)
	{
		cout << "file fin not open";
	}
	for (int i(0); i < BOOKS_AMOUNT; i++)
	{
		fout >> zapF.name; //считать имя 
		zapF.number = i + 10 - sizeof(myStruct);//считать смещение из файла
		index.insert(pair<string, size_t>(zapF.name, zapF.number));
	}
	for (auto it = index.begin(); it != index.end(); it++)
	{
		fin << it->first;
		fin << ' ';
		fin << it->second;
		fin << endl;
	}
	fout.close();
	fin.close();
	return 0;
}
