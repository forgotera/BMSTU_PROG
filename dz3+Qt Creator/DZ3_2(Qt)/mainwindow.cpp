#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QFileDialog>
//#include <ui_progres.h>
#include <QProgressDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[&]()
    {
      image= new QImage(QFileDialog::getOpenFileName(this));
      ui->label->setPixmap(QPixmap::fromImage(*image,Qt::AutoColor));
      image->convertToFormat(QImage::Format_Indexed8); //переводим в формат 8 бит
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() //кнопка удалить
{
    qint32 nHeight= image->height();
    qint32 nWidth= image->width();
    int n=image->height()*image->width();
    int ProNum=0;
    QProgressDialog* pro=new QProgressDialog("Progressing the data...", "&Cancel", 0,n);
    pro->setMinimumDuration(0);
    pro->setWindowTitle("please wait");
   for(int x=0; x<nWidth;x++)
   {
      // QRgb *templine =reinterpret_cast<Qrgb*>(image.scanLine(x));
       for (int y =0; y<nHeight;y++)
       {
           ProNum++;
           pro->setValue(ProNum);
           qApp->processEvents();
           //QRgb  rgb =image->pixel(x,y); //палитра цвета
                /* если цвет зеленый то setcolor(белый)*/
           if ( ( image->pixel(x,y)>=qRgb(0,128,128)) & ( image->pixel(x,y)<=qRgb(173,255,47) )  )
           {
             image->setPixel(x,y,Qt::color0);
           }
           if(pro->wasCanceled())
           {
               break;
           }
       }
   }
   pro->setValue(n);
   delete pro;
   ui->label->setPixmap(QPixmap::fromImage(*image,Qt::AutoColor));
}

void MainWindow::on_save_clicked()
{
    image->save(QFileDialog::getSaveFileName(this));

}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}
