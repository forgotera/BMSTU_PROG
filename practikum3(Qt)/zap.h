#ifndef ZAP_H
#define ZAP_H

#include <QDialog>
#include<mainwindow.h>

namespace Ui {
class zap;
}

class zap : public QDialog
{
    Q_OBJECT

public:
    explicit zap(QWidget *parent = 0);
    ~zap();



private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::zap *ui;
};

#endif // ZAP_H
