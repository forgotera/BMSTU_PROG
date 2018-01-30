#include <iostream>
#include <conio.h>
#include <cstring>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

struct tree
{
	tree* right;	//������ �����
	tree* left;		//����� ����� 
	string  str;		//���� 
}
;

void AddTree(string str1, tree **begin) //�������� ������ 
{
	if ((*begin) == NULL)
	{
		*begin = new tree;
		(*begin)->str = str1;
		(*begin)->left = NULL;
		(*begin)->right = NULL;
		return;
	}
	else
		if (str1 >(*begin)->str)
			AddTree(str1, &(*begin)->right);
		else
			AddTree(str1, &(*begin)->left);
}
void PrintStringInc(tree *begin)//����� �� ������������
{
	if (begin == NULL)
	{
		return;
	}
	else
	{
		PrintStringInc(begin->left);
		cout << begin->str << ' ';
		PrintStringInc(begin->right);
	}
}
void PrintStringDec(tree *begin)//����� �� ��������
{
	if (begin == NULL)
		return;
	else
	{
		PrintStringDec(begin->right);
		cout << begin->str << " ";
		PrintStringDec(begin->left);
	}
}
void FreeMem(tree *begin)//������������ ������
{
	if (begin == NULL)
		return;
	else
	{
		FreeMem(begin->left);
		FreeMem(begin->right);
		delete begin;
	}
}


int main()
{
	setlocale(0, "Russian");
	tree  *head = NULL;
	string str;
	int n;
	cout << "read srting\nstop read-exit\n";
	do
	{
		getline(cin, str);
		if (str != "exit")
		{
			AddTree(str, &head);
		}
	} while (str != "exit");
	cout << endl << "����� �� ������������" << endl;
	PrintStringInc(head);
	cout << endl << "����� �� ��������" << endl;
	PrintStringDec(head);
	FreeMem(head);
	_getch();
	return 0;
}
