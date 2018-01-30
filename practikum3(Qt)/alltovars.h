#ifndef ALLTOVARS_H
#define ALLTOVARS_H

#include <QDialog>
#include <QMap>
#include<QStandardItem>
using namespace std;
namespace Ui {
class allTovars;
}

class allTovars : public QDialog
{
    Q_OBJECT

public:
    explicit allTovars(QWidget *parent = 0);
    ~allTovars();
    QStandardItemModel *model;
    QStandardItem *item;
    QString country,obem;
    map<QString, int> contr;
    int objem;

private slots:

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::allTovars *ui;
};

#endif // ALLTOVARS_H
