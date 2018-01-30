#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStandardItemModel *model;
    QStandardItem *item;
    int IColor;

private slots:

    void on_odd_clicked();

    void on_even_clicked();

    void on_Easy_clicked();

   // void on_comboBox_activated( int IColor);

    void on_comboBox_currentIndexChanged();

    void on_save_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
