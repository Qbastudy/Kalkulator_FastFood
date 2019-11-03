#ifndef LICZKALORIE_H
#define LICZKALORIE_H

#include <QDialog>

namespace Ui {
class LiczKalorie;
}

class LiczKalorie : public QDialog
{
    Q_OBJECT

public:
    explicit LiczKalorie(QWidget *parent = nullptr);
    ~LiczKalorie();
    void SumujProdukty(QString,QString);

private slots: //x
    void on_LiczKalorie_rejected();

private:
    Ui::LiczKalorie *ui;
};

#endif // LICZKALORIE_H
