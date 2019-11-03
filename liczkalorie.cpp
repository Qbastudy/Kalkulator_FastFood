#include "liczkalorie.h"
#include "ui_liczkalorie.h"

LiczKalorie::LiczKalorie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LiczKalorie)
{
    ui->setupUi(this);

    move(800,150);
}

LiczKalorie::~LiczKalorie()
{
    delete ui;
}

void LiczKalorie::on_LiczKalorie_rejected()
{
    QApplication::quit();
}

void LiczKalorie::SumujProdukty(QString nazwa_produktu, QString ilosc_kalorii)
{
    ui->listWidget_produkty->addItem(nazwa_produktu);
    ui->listWidget_kalorie->addItem(ilosc_kalorii);
    QString x = ui->textBrowser_suma->toPlainText();
    if(!x.isNull()) //fasle //! //true
    {
        int suma=x.toInt();
        suma +=ilosc_kalorii.toInt();
        ui->textBrowser_suma->setText(QString::number(suma));
    }
    else
        ui->textBrowser_suma->setText(ilosc_kalorii);
}
