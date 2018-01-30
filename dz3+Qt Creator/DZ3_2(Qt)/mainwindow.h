#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include<progres.h>
#include <QProgressBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage *image;


private slots:
    void on_pushButton_2_clicked();

    void on_save_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

     QProgressBar *pro;

};

#endif // MAINWINDOW_H
