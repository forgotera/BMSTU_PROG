#ifndef PROGRES_H
#define PROGRES_H

#include <QDialog>

namespace Ui {
class progres;
}

class progres : public QDialog
{
    Q_OBJECT

public:
    explicit progres(QWidget *parent = 0);
    ~progres();
    Ui::progres *ui;

private slots:
    void on_pushButton_clicked();

private:

};

#endif // PROGRES_H
