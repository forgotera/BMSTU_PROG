#ifndef GRAFIK_H
#define GRAFIK_H

#include <QDialog>
#include <Qmap>
#include <QFile>
#include <QTextStream>
using namespace std;

namespace Ui {
class grafik;
}

class grafik : public QDialog
{
    Q_OBJECT

public:
    explicit grafik(QWidget *parent = 0);
    ~grafik();
    map<QString,int> name;
     QString strName;

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::grafik *ui;
};

#endif // GRAFIK_H
