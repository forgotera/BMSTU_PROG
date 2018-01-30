#include "alltovars.h"
#include "ui_alltovars.h"
#include <zap.h>
#include<QTextStream>
#include<QFile>
#include <QMap>

const int numberOfcountry=3;
using namespace std;
QFile fe(".//base.txt");
allTovars::allTovars(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allTovars)
{
    ui->setupUi(this);
    fe.open(QFile::ReadWrite|QFile::Text);//открытие файла

    QTextStream input(&fe);

  while (!input.atEnd())
  {
      int Nowspace;
      country=input.readLine();
      for(int i=0;i<numberOfcountry;i++)
      {
        Nowspace=country.indexOf(' ');
        country=country.remove(0,Nowspace+1); //удаление строки до пробела
      }
      int endSpace=country.indexOf(' ');
      country.truncate(endSpace);//отсечение последней части
      contr.insert(pair<QString,int>(country,1));//вносим все в map чтобы не было повторений
  }

   for (auto it = contr.begin(); it != contr.end(); it++)
   {
     ui->comboBox->addItem(it->first);//выводим на комбобокс
   }
  // fe.close();
}

allTovars::~allTovars()
{
    fe.close();
    delete ui;
}



void allTovars::on_pushButton_clicked()//закрытие формы
{
    fe.close();
    this->close();
}

void allTovars::on_comboBox_currentIndexChanged(const QString &arg1) //выбор страны
{
    int Nowspace;
    fe.open(QFile::ReadWrite|QFile::Text);
    QTextStream input(&fe);
    model=new QStandardItemModel();
    QStringList Vertical;
    Vertical.append("Товар:");
    Vertical.append("Суммарный обьем:");
    model->setVerticalHeaderLabels(Vertical);
    int summObem=0;
    int stolbec=0;
     while (!input.atEnd())
     {
        country=input.readLine();
        obem=country;
        if((country.indexOf(ui->comboBox->currentText())!=-1) & ( (country.indexOf("импорт")!=-1)|(country.indexOf("Импорт")!=-1) ) )
        {
              int endSpace=country.indexOf(' ');
              country.truncate(endSpace+1);
              //выводим в табл товар
              item=new QStandardItem(country);
              model->setItem(0,stolbec,item);
              stolbec++;
              //из текста выделяем обьем
              Nowspace=obem.indexOf(' ');
              obem=obem.remove(0,Nowspace+1);
              endSpace=obem.indexOf(' ');
              obem.truncate(endSpace);
              //перевод в число
              bool ok;
              summObem+=obem.toInt(&ok,10);
        }
     }
//вывод суммарного объема
 item=new  QStandardItem(country.setNum(summObem));
 model->setItem(1,0,item);
 ui->tableView->setModel(model);
 fe.close();
}
