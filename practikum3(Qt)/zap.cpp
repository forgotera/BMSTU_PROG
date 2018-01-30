#include "zap.h"
#include "ui_zap.h"
#include <mainwindow.h>
#include <QTextStream>



 QFile f(".//base.txt");
 zap::zap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zap)
{
    ui->setupUi(this);
   f.open(QFile::Append|QFile::Text);//открытие файла
}

zap::~zap()
{
    f.close();
    delete ui;
}


void zap::on_pushButton_2_clicked()
{
    f.close();
    this->close();
}

void zap::on_pushButton_clicked()
{
    QString str;
    QTextStream output (&f);
    str=ui->textEdit->toPlainText(); //наименование товара
    output<<str<<' ';
    str=ui->textEdit_2->toPlainText();//объем
    output<<str<<' ';
    str=ui->textEdit_3->toPlainText();//год
    output<<str<<' ';
    str=ui->textEdit_4->toPlainText();//страна
    output<<str<<' ';
    str=ui->textEdit_5->toPlainText();//направление
    output<<str<<endl;

    //очистка поля ввода
    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->textEdit_4->clear();
    ui->textEdit_5->clear();
}
