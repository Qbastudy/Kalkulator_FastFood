#ifndef BAZADANYCH_H
#define BAZADANYCH_H

#include <QtSql>

class BazaDanych
{
public:
    BazaDanych();
    const QString Sciezka="C:\\Users\\Kuba\\Desktop\\Projekty\\bazadanych\\kalkulatordb.db";
    QSqlDatabase MojDB;
    bool BazaOpen();
    void BazaClose();
    ~BazaDanych();
};

#endif // BAZADANYCH_H
