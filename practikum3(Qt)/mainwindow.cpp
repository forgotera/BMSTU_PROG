#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//открытие окна записи
void MainWindow::on_pushButton_clicked()
{
  zap za;
  za.exec();
}
//открытие окна  импортируемых товаров из страны
void MainWindow::on_pushButton_2_clicked()
{
    allTovars all;
    all.exec();
}
//выход
void MainWindow::on_pushButton_6_clicked()
{
    this->close();
}
//экспорт товаров
void MainWindow::on_pushButton_3_clicked()
{
    eksport eks;
    eks.exec();
}
//импорт
void MainWindow::on_pushButton_4_clicked()
{
   import im;
   im.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    grafik gr;
    gr.exec();
}
