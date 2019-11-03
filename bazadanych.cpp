#include "bazadanych.h"

BazaDanych::BazaDanych()
{

}

BazaDanych::~BazaDanych()
{

}

bool BazaDanych::BazaOpen()
{
    MojDB= QSqlDatabase::addDatabase("QSQLITE");
    MojDB.setDatabaseName(Sciezka);
    MojDB.open();
    QFileInfo check_file(Sciezka);
    if(check_file.exists() && check_file.isFile())
    {
        qDebug()<<("Połączono z bazą danych...");

        return true;
    }
    else
    {
        qDebug()<<("Blad polaczenia z baza danych");

        return false;
    }
}

void BazaDanych::BazaClose()
{
    MojDB.close();
    MojDB.removeDatabase(QSqlDatabase::defaultConnection);
}
