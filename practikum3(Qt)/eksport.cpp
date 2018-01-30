#include "eksport.h"
#include "ui_eksport.h"
#include <QFile>
#include<QTextStream>
#include <alltovars.h>

QFile fi(".//base.txt");
const int numberOfcountry=3;
const int numberOfEksport=4;


eksport::eksport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eksport)
{
    fi.open(QFile::ReadWrite|QFile::Text);
    QString  napr,obem,country;
    int summObem=0,endSpace,maxObem=0;
    ui->setupUi(this);
    QTextStream input(&fi);
    QString coutryOtVet;
    while (!input.atEnd())
    {
        int Nowspace;
        country=input.readLine();
        napr=country;
        obem=country;
        for(int i=0;i<numberOfcountry;i++)
        {
          Nowspace=country.indexOf(' ');
          country=country.remove(0,Nowspace+1); //удаление строки до пробела
        }
        endSpace=country.indexOf(' ');
        country.truncate(endSpace);//отсечение последней части
        contr.insert(pair<QString,int>(country,1));//вносим все в map чтобы не было повторений
        //объем
        Nowspace=obem.indexOf(' ');
        obem=obem.remove(0,Nowspace+1);
        endSpace=obem.indexOf(' ');
        obem.truncate(endSpace);
        //направление
        for(int i=0;i<numberOfEksport;i++)
        {
          Nowspace=napr.indexOf(' ');
          napr=napr.remove(0,Nowspace+1); //удаление строки до пробела
        }
        //перевод в число
         bool ok;

        for (auto it = contr.begin(); it != contr.end(); it++)
        {
                if( (napr=="экспорт")||(napr=="Экспорт")& (it->first==country) )
                {
                    summObem=obem.toInt(&ok,10);
                    if (summObem>maxObem)
                    {
                       maxObem=summObem;
                       coutryOtVet=it->first;
                    }
                }
        }
    }
    fi.close();
    ui->textEdit->insertPlainText(coutryOtVet);
}



eksport::~eksport()
{
    delete ui;
}

void eksport::on_pushButton_clicked()
{
    this->close();
}
