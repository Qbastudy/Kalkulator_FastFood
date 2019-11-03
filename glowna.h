#ifndef GLOWNA_H
#define GLOWNA_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QtSql>
#include <QMessageBox>
#include "liczkalorie.h"
#include "bazadanych.h"

namespace Ui {
class Glowna;
}

class Glowna : public QMainWindow
{
    Q_OBJECT

public:
    explicit Glowna(QWidget *parent = nullptr);
    ~Glowna();

private slots: //def
    void on_listWidget_restauracje_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButtonClose_wyjdz_clicked();

    void on_pushButton_clicked();

    void on_tableView_produkty_doubleClicked(const QModelIndex &index);

private:
    Ui::Glowna *ui;
    BazaDanych db;
    LiczKalorie* drugieOkno = new LiczKalorie;//obiekt na klase
};

#endif // GLOWNA_H
