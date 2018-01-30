#ifndef IMPORT_H
#define IMPORT_H

#include <QDialog>
#include <Qmap>
#include <QFile>
#include <QTextStream>
#include <QStandardItem>

using namespace std;

namespace Ui {
class import;
}

class import : public QDialog
{
    Q_OBJECT

public:
    explicit import(QWidget *parent = 0);
    ~import();
    map<QString,int> name;
    QString strName;
    QStandardItemModel *model;
    QStandardItem *item;
    QString country,obem;

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::import *ui;
};

#endif // IMPORT_H
