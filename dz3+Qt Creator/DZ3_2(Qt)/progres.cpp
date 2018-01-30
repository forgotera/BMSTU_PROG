#include "progres.h"
#include "ui_progres.h"
#include <mainwindow.h>

progres::progres(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::progres)
{
    ui->setupUi(this);
}

progres::~progres()
{
    delete ui;
}

void progres::on_pushButton_clicked()
{
    //остановка процесса удаления зеленого цвета;
   QWidget::close();
}
