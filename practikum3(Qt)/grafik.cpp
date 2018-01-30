#include "grafik.h"
#include "ui_grafik.h"
#include <QVector>
using namespace std;

QFile fine(".//base.txt");
QVector<double> coordinateX;
QVector<double> coordinateY;
grafik::grafik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::grafik)
{
    ui->setupUi(this);
    fine.open(QFile::ReadWrite|QFile::Text);
     QTextStream input(&fine);
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

    fine.close();
}

grafik::~grafik()
{
    delete ui;
}

void grafik::on_pushButton_clicked()
{
    this->close();
}

void grafik::on_comboBox_currentIndexChanged(const QString &arg1)
{
    fine.open(QFile::ReadWrite|QFile::Text);
    coordinateX.reserve(10);
    coordinateY.reserve(10);
    QTextStream input(&fine);
    QString year,objem;
    input.seek(0);
    while (!input.atEnd())
    {
        int  Nowspace,endSpace;
        objem=input.readLine();
        if( (objem.indexOf(ui->comboBox->currentText())!=-1) & ( (objem.indexOf("экспорт")!=-1)|(objem.indexOf("Экспорт")!=-1) ) )
        {
            double number;
            //вырезаем из считанной строки объем
            Nowspace=objem.indexOf(' ');
            objem=objem.remove(0,Nowspace+1);
            year=objem;
            endSpace=objem.indexOf(' ');
            objem.truncate(endSpace);
            //вырезаем год
            year=year.remove(0,endSpace+1);
            endSpace=year.indexOf(' ');
            year.truncate(endSpace);
            //заносим в вектора
            number=year.toDouble();
            coordinateX.push_back(number);
            number=objem.toDouble();
            coordinateY.push_back(number);
        }
    }
    fine.close();
    //очистили график
    ui->widget->clearGraphs();
    //добавили ноый график
    ui->widget->addGraph();
    //отрисовка графика по массивам х у
    ui->widget->graph(0)->setData(coordinateX,coordinateY);
    //подписываем оси x y
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    //макс и мин значение массива x
    int max=coordinateX[0],min= coordinateX[0];
    for(int i=1;i<coordinateX.size();i++)
    {
        if (coordinateX[i]>max)
        {
            max=coordinateX[i];
        }
        if (coordinateX[i]<min)
        {
            min=coordinateX[i];
        }
    }
    //область для оси x
    ui->widget->xAxis->setRange(int(min),int(max));
    //макс и мин значение массива y
   max=coordinateY[0],min= coordinateY[0];
   for(int i=1;i<coordinateY.size();i++)
    {
        if (coordinateY[i]>max)
        {
            max=coordinateY[i];
        }
        if (coordinateY[i]<min)
        {
            min=coordinateY[i];
        }
    }
    //область для оси y
    ui->widget->yAxis->setRange(int(min),int(max));
    ui->widget->replot();
}
