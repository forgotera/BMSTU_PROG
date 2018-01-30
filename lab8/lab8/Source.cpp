#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
struct sp
{
	int chislo;
	sp *next;
	string stroka;
};
//класс
class sort :public  sp
{
private:
	sp *begin, *q;
public:
	sort::sort(sp *get_begin, sp *q)
	{
		setData(get_begin, q);
	}
	void sort::setData(sp *get_begin, sp* q)
	{
		begin = get_begin;
		q = NULL;
	}
	void bSort()
	{
		sp *buffSp = begin, *buffSp2 = begin;
		while (buffSp->next != NULL)
		{
			while (begin->next != NULL)
			{
				if ((begin->chislo) > (begin->next->chislo))
				{
					{
						int temp;
						string buff;
						temp = begin->chislo;
						buff = begin->stroka;
						begin->chislo = begin->next->chislo;
						begin->stroka = begin->next->stroka;
						begin->next->chislo = temp;
						begin->next->stroka = buff;
					}
				}
				begin = begin->next;
			}
			begin = buffSp2;//ставлю указатель на начало
			buffSp = buffSp->next;
		}
	}
};
//шаблонный класс
template < typename T >
class sort :public  sp
{
private:
	T *begin, *q;
public:
	sort(T *get_begin, T *q)
	{
		setData(get_begin, q);
	}
	void setData(T *get_begin, T* q)
	{
		begin = get_begin;
		q = NULL;
	}
	void bSort();
};

template < typename T >
void sort<T>::bSort()
{
	T *buffSp = begin, *buffSp2 = begin;
	while (buffSp->next != NULL)
	{
		while (begin->next != NULL)
		{
			//сортировка списка , перемещаю указатели
			if ((begin->chislo) > (begin->next->chislo))
			{
				{

					int temp;
					string buff;
					temp = begin->chislo;
					buff = begin->stroka;
					begin->chislo = begin->next->chislo;
					begin->stroka = begin->next->stroka;
					begin->next->chislo = temp;
					begin->next->stroka = buff;
				}
			}
			begin = begin->next;
		}
		begin = buffSp2;//ставлю указатель на начало
		buffSp = buffSp->next;
	}
}

sp* CreateSp(int a, string str, sp**begin)
{
	sp *last = NULL;
	if (*begin == NULL)
	{
		*begin = new sp;
		(*begin)->chislo = a;
		(*begin)->stroka = str;
		(*begin)->next = NULL;
		return *begin;
	}
	else
	{
		(last) = new sp;
		(last)->chislo = a;
		(last)->stroka = str;
		(last)->next = *begin;
		return (last);
	}
}
void AddSp(int a, int b, string str, sp *begin)
{
	sp *q, *p;
	while (begin != NULL)
	{
		if (a == begin->chislo)
		{
			q = new sp;
			q->chislo = b;
			q->stroka = str;
			p = begin->next;
			begin->next = q;
			q->next = p;
			return;
		}
		else begin = begin->next;
	}
	cout << "Entered item not found\n";
}//
void DelSp(int a, sp *begin)
{
	sp *p;
	while (begin != NULL)
	{
		if (a == begin->next->chislo)
		{
			p = begin->next;
			begin->next = begin->next->next;
			delete p;
			return;
		}
		else begin = begin->next;
	}
	cout << "Entered item not found\n";
}
void PrintSp(sp *begin)
{
	begin = begin->next;
	while (begin != NULL)
	{
		cout << begin->chislo << " " << begin->stroka << endl;
		begin = begin->next;
	}

}
void FreeMem(sp *begin)
{
	sp *p;
	while (begin != NULL)
	{
		p = begin->next;
		delete begin;
		begin = p;
	}
}

int main()
{
	sp *head = NULL;
	int a, c, b;
	string str, str1;

	cout << "print integer and char\n";
	do
	{
		cin >> a;
		getline(cin, str);
		head = CreateSp(a, str, &head);
	} while (a != 0);
	PrintSp(head);
	cout << endl;
	do
	{
		cout << "\tenter  1 for  delete sp\n\tenter 2 for add sp\n\tenter 3 for print sp\n\tenter 4 for sort sp\n\tenter 0 for exit\n";
		cin >> c;
		cout << endl;
		switch (c)
		{
		case 1:
			cout << "enter integer  for delete sp\n";
			cin >> a;
			cout << endl;
			DelSp(a, head);
			break;
		case 2:
			cout << "enter integer after which add sp\n";
			cin >> a;
			cout << endl;
			cout << "enter integer and char which add in sp\n";
			cin >> b;
			cout << endl;
			getline(cin, str);
			cout << endl;
			AddSp(a, b, str, head);
			break;
		case 3:
			PrintSp(head);
			break;
		case 4:
			sp *q = NULL;
			sort<sp> cl(head, q);
			cl.bSort();
			break;
		}
	} while (c != 0);
	FreeMem(head);
	return 0;
}
