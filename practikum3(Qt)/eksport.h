#ifndef EKSPORT_H
#define EKSPORT_H

#include <QDialog>
#include <alltovars.h>

namespace Ui {
class eksport;
}

class eksport : public QDialog
{
    Q_OBJECT

public:
    explicit eksport(QWidget *parent = 0);
    ~eksport();
    map<QString, int> contr;

private slots:
    void on_pushButton_clicked();

private:
    Ui::eksport *ui;
};

#endif // EKSPORT_H
