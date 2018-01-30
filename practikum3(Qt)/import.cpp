#include "import.h"
#include "ui_import.h"

const int numberOfcountry=3;
QFile fin(".//base.txt");
import::import(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::import)
{
    ui->setupUi(this);
    fin.open(QFile::ReadWrite|QFile::Text);
    QTextStream input(&fin);
     while (!input.atEnd())
     {
         //название продукта
         strName=input.readLine();
         int endSpace=strName.indexOf(" ");
         strName.truncate(endSpace);
         name.insert(pair<QString,int>(strName,1));
     }
     for(auto it=name.begin();it!=name.end();it++)
     {
         ui->comboBox->addItem(it->first);
     }
     fin.close();

}

import::~import()
{
    delete ui;
}

void import::on_pushButton_clicked()
{
    this->close();
}

void import::on_comboBox_currentIndexChanged(const QString &arg1)
{
    int Nowspace;
    fin.open(QFile::ReadWrite|QFile::Text);
    QTextStream input(&fin);
    model=new QStandardItemModel();
    QStringList Vertical;
    Vertical.append("Страна:");
    Vertical.append("обьем:");
    model->setVerticalHeaderLabels(Vertical);
    int stolbec=0;
     while (!input.atEnd())
     {
        country=input.readLine();
        obem=country;
        if((country.indexOf(ui->comboBox->currentText())!=-1) & ( (country.indexOf("импорт")!=-1)|(country.indexOf("Импорт")!=-1) ) )
        {
            for(int i=0;i<numberOfcountry;i++)
            {
              Nowspace=country.indexOf(' ');
              country=country.remove(0,Nowspace+1); //удаление строки до пробела
            }
            int endSpace=country.indexOf(' ');
            country.truncate(endSpace);//отсечение последней части
            item=new QStandardItem(country);
            model->setItem(0,stolbec,item);
            //из текста выделяем обьем
            Nowspace=obem.indexOf(' ');
            obem=obem.remove(0,Nowspace+1);
            endSpace=obem.indexOf(' ');
            obem.truncate(endSpace);
            //запись в таб число
            item=new  QStandardItem((obem));
            model->setItem(1,stolbec,item);
            stolbec++;
        }
     }
//вывод суммарного объема
 ui->tableView->setModel(model);
 fin.close();
}
