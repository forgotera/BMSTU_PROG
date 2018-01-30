/*����������� � ����������� ��������� ������� ��� ��������� �������� ���������� ����-���,
��������� ��������� ������������ � ����������. ��������� �� �� �������� �������, 
� ������������� ���� ������������ ������������� ������� �� ���������� ������.
����:
 ������ �����, ������� �������� �� ������ ���� ��������,
 ���������� �� ������� ���� ��������, ���������� ���������� ������� � ��������� ���� �����,
 � ����� �� ���������� �����������.
������ ������������, ������� �������� ���� �� ������,
���������� ���������� ���� � �����������,
���������� ������� � ��������� ���� ����������� � �� ����� ���������� �����������.
*/
#include <iostream>
#include <string>
#include<conio.h>
#include <vector>

const int NUMBER_GLASN = 12;

class word
{
private:
		std::string str;
		int glas, soglas;
public:
	word()
	{
		//����������� �� ���������
		str = '\0';
		glas = 0;
		soglas = 0;
	}
	word(std::string Get_str)
	{
		Init(Get_str);
	}
	void Init(std::string Get_str)
	{
		str = Get_str;
		glas = 0;
		soglas = 0;
	}
	void Print()
	{
		std::cout << str<<std::endl;
	}
	int searchGlass();
	int searchSoglasn();
	int sizeStr();
	void percent();
	~word() {};
};

int word::sizeStr()
{
	return str.length();
}

int word::searchGlass()
{
	std::string glasn = { "AEIOUYaeiouy" };
	for (register int i(0); i < str.size(); i++)
	{
		for (register int j(0); j < NUMBER_GLASN; j++)
		{

			if (str[i] == glasn[j])
			{
				glas++;
			}
		}
	}
	return glas;

}

int word::searchSoglasn()
{
	soglas = str.length() - glas;
	return soglas;
}

void word::percent()
{
	//����� ������
	int strLen = str.size();
	//������� �������
	double percentGlas = (glas * 100) / strLen;
	double percentSogl = 100 - percentGlas;
	std::cout << "percent soglas: " << percentSogl << "%" <<std::endl<< "percent glas: " << percentGlas << "%" << std::endl;
}

class predloz :public word
{
private:
	std::vector <word> ObjectVect;
	int sumGlas, sumSog;
public:
	predloz()
	{
		ObjectVect.reserve(0);
		sumGlas = 0;
		sumSog = 0;
	}
	predloz(word get_predloz_word)
	{
		initPredloz(get_predloz_word);
	}
	void initPredloz(word get_predloz_word)
	{
		ObjectVect.push_back(get_predloz_word);
	}
	void printPredloz()
	{
		for (register int i(0); i < ObjectVect.size(); i++)
		{
			ObjectVect[i].Print();
		}
	}
	void allsearchGlassSoglas();
	void allPercet();
	void numberWord();

};

void predloz::numberWord()
{
	std::cout << "Number words: " << ObjectVect.size();
}

void predloz::allsearchGlassSoglas()
{
	//����� ����� �������/���������
	for (register int i(0); i < ObjectVect.size(); i++)
	{
		sumGlas += ObjectVect[i].searchGlass();
		sumSog += ObjectVect[i].searchSoglasn();
	}
	std::cout << "all Glas: " << sumGlas << std::endl;
	std::cout << "all soglasn: " << sumSog << std::endl;
}

void predloz::allPercet()
{
	int strLen = 0;
	for (register int i(0); i < ObjectVect.size(); i++)
	{
		strLen += ObjectVect[i].sizeStr();
	}
	double percentGlas = (sumGlas * 100) / strLen;
	double percentSogl = 100 - percentGlas;
	std::cout << "percent soglas: " << percentSogl << "%" << std::endl << "percent glas: " << percentGlas << "%" << std::endl;

}

int main()
{
	word ObjectWord;
	predloz ObjectPredloz;
	std::string readStr;
	int key=-1;
	std::cout << "1.new word\n" << "2.print word\n" << "3.number glasn or soglasn\n" << "4.percent glasn or soglasn\n" << "5.print size\n" << "6.Print all words\n";
	std::cout << "7.all numbers glasn or soglasn\n" << "8.all percent glasn or soglasn\n" << "0.Exit\n";
	for (; key != 0;)
	{	
		
		std::cin >> key;
		system("cls");	
		std::cout << "1.new word\n" << "2.print word\n" << "3.number glasn or soglasn\n" << "4.percent glasn or soglasn\n" << "5.print size\n" << "6.Print all words\n";
		std::cout << "7.all numbers glasn or soglasn\n" << "8.all percent glasn or soglasn\n" << "0.Exit\n" << std::endl;
		switch (key)
		{
		
			case 1:
			{
				//���� ������ �����
				std::cout << "read string ";
				std::cin >> readStr;
				ObjectWord.Init(readStr);
				//����� ������ ����� �� ������ ������
				ObjectPredloz.initPredloz(readStr);
			}
			break;
			case 2:
			{
				//����� �����
				ObjectWord.Print();
				break;
			}
			case 3:
			{
				//���-�� ������� /��������� � ����� 
				std::cout << "Glassn: " << ObjectWord.searchGlass() << std::endl;
				std::cout << "Soglasn: " << ObjectWord.searchSoglasn() << std::endl;
				break;
			}
			case 4:
			{
				//���������� ����������� � �����
				ObjectWord.percent();
				break;
			}
			case 5:
			{
				//����� ������
				std::cout << "size str: " << ObjectWord.sizeStr() << std::endl;
				break;
			}
			case 6:
			{
				//����� ����������� 
				ObjectPredloz.printPredloz();
				break;
			}
			case 7:
			{
				//���-�� ������� � ��������� � �����������
				ObjectPredloz.allsearchGlassSoglas();
				break;
			}
			case 8:
			{
				//���������� ����������� 
				ObjectPredloz.allPercet();
				break;
			}
		}
	}
	
	return 0;
}