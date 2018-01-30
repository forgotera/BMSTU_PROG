/*Разработать и реализовать диаграмму классов для описанных объектов предметной обла-сти,
используя механизмы наследования и композиции. Проверить ее на тестовом примере, 
с демонстрацией всех возможностей разработанных классов на конкретных данных.
Даны:
 Объект слово, умеющий выводить на печать свое значение,
 возвращать по запросу свое значение, определять количество гласных и согласных букв слова,
 а также их процентное соотношение.
Объект «предложение», умеющий выводить себя на печать,
определять количество слов в предложении,
количество гласных и согласных букв предложения и их общее процентное соотношение.
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
		//контсруктор по умолчанию
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
	//длина строки
	int strLen = str.size();
	//процент гласных
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
	//общее колво гласных/согласных
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
				//ввод нового слова
				std::cout << "read string ";
				std::cin >> readStr;
				ObjectWord.Init(readStr);
				//сразу вводим слово во второй объект
				ObjectPredloz.initPredloz(readStr);
			}
			break;
			case 2:
			{
				//вывод слова
				ObjectWord.Print();
				break;
			}
			case 3:
			{
				//кол-во гласных /согласных в слове 
				std::cout << "Glassn: " << ObjectWord.searchGlass() << std::endl;
				std::cout << "Soglasn: " << ObjectWord.searchSoglasn() << std::endl;
				break;
			}
			case 4:
			{
				//процентное соотношение в слове
				ObjectWord.percent();
				break;
			}
			case 5:
			{
				//длина строки
				std::cout << "size str: " << ObjectWord.sizeStr() << std::endl;
				break;
			}
			case 6:
			{
				//вывод предложения 
				ObjectPredloz.printPredloz();
				break;
			}
			case 7:
			{
				//кол-во гласных и согласных в предложении
				ObjectPredloz.allsearchGlassSoglas();
				break;
			}
			case 8:
			{
				//процентное соотношение 
				ObjectPredloz.allPercet();
				break;
			}
		}
	}
	
	return 0;
}