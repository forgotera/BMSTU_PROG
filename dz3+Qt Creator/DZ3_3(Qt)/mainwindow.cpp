#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextStream>
#include <QFile>


const int number=10;
//глобальный массив для цветов
Qt::GlobalColor color[5]={ Qt::red,Qt::blue,Qt::yellow,Qt::green,Qt::white};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    model =new QStandardItemModel;
    QStringList Horizontal;
    QStringList Vertical;
    ui->setupUi(this);

    QString read;
    for (int i=0;i<number;i++)
    {
        //заголовки по гор и верт
        Horizontal.append(read.setNum(i+1));
        Vertical.append(read.setNum(i+1));
        //создает таблицу
        for(int j=0;j<number;j++)
        {
            item=new QStandardItem(read.setNum((i+1)*(1+j)));
            model->setItem(i,j,item);
        }
    }
    model->setHorizontalHeaderLabels(Horizontal);
    model->setVerticalHeaderLabels(Vertical);
    ui->tableView->setModel(model);

    //комбо бокс добавляем надписи
    ui->comboBox->addItem("Blue");
    ui->comboBox->addItem("Green");
    ui->comboBox->addItem("Red");
    ui->comboBox->addItem("Yellow");
    ui->comboBox->addItem("White  ");
}


MainWindow::~MainWindow()
{
    delete ui;
}

//выделение четных
void MainWindow::on_even_clicked()
{
    QAbstractItemModel* m= ui->tableView->model();
     for (int i=0;i<number;i++)
     {
          for(int j=0;j<number;j++)
          {
            if( ( (i+1)*(j+1) )%2 ==0 )
            {
                m->setData( m->index( i, j ), QBrush( color[IColor] ), Qt::BackgroundRole );
            }
          }
     }
}

//выделение нечетных
void MainWindow::on_odd_clicked()
{
    QAbstractItemModel* m= ui->tableView->model();
     for (int i=0;i<number;i++)
     {
          for(int j=0;j<number;j++)
          {
            if( ( (i+1)*(j+1) )%2 !=0 )
            {
                m->setData( m->index( i, j ), QBrush(color[IColor]), Qt::BackgroundRole );
            }
          }
     }
}

//простые числа
void MainWindow::on_Easy_clicked()
{
    QAbstractItemModel* m= ui->tableView->model();
    for (int i=0;i<number;i++)
    {
         for(int j=0;j<number;j++)
         {
            int k=1;
             for(int num=2;num<=(i+1)*(1+j);num++)
             {
                 if(((i+1)*(1+j))%num==0)
                 {
                     k++;
                 }
             }
            if (k==2)
            {
               m->setData( m->index( i, j ), QBrush(  color[IColor] ), Qt::BackgroundRole );
            }
        }
    }
}


//выбор цвета для закрашивания
void MainWindow::on_comboBox_currentIndexChanged()
{
  QString hi=ui->comboBox->currentText();
  //определяем цвет по колву букв
  switch (hi.length())
   {
     case 3:
        IColor=0;
     break;
     case 4:
        IColor=1;
     break;
     case 5:
       IColor=3;
    break;
    case 6:
       IColor=2;
    break;
    case 7:
        IColor=4;
    break;
  }
}

//сохранение  CSV
void MainWindow::on_save_clicked()
{
    QFile f(QFileDialog::getSaveFileName(this));

       if( f.open( QIODevice::WriteOnly ) )
       {
           QTextStream ts( &f );
           QStringList strList;
           strList << "\" \"";
           for( int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c )
               strList << "\""+ui->tableView->model()->headerData(c, Qt::Horizontal).toString()+"\"";
           ts << strList.join( ";" )+"\n";

           for( int r = 0; r < ui->tableView->verticalHeader()->count(); ++r )
           {
               strList.clear();
               strList << "\""+ui->tableView->model()->headerData(r, Qt::Vertical).toString()+"\"";
               for( int c = 0; c < ui->tableView->horizontalHeader()->count(); ++c )
               {
                   strList << "\""+ui->tableView->model()->data(ui->tableView->model()->index(r, c), Qt::DisplayRole).toString()+"\"";
               }
               ts << strList.join( ";" )+"\n";
           }
           f.close();
       }
}
