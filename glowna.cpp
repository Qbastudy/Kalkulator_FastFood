#include "glowna.h"
#include "ui_glowna.h"

Glowna::Glowna(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Glowna)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);


    drugieOkno->show();

    if(db.BazaOpen())
        ui->label_bazadanych->setText("Połączono z bazą danych...");
    else
        ui->label_bazadanych->setText("Blad polaczenia z baza danych");

    QSqlQuery qry_odczyt("select Nazwa_restauracji from Restauracje ");
    qry_odczyt.next();
    do
    {
         ui->listWidget_restauracje->addItem(qry_odczyt.value(0).toString());
         qry_odczyt.next();

    }while(qry_odczyt.value(0).toString()!=NULL);
}

Glowna::~Glowna()
{
    delete ui;
    db.BazaClose();
    drugieOkno->close();
}

void Glowna::on_listWidget_restauracje_itemDoubleClicked(QListWidgetItem *item)
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->label_restauracja->setText(item->text());

    if(db.BazaOpen())
    {
        QSqlQueryModel* modal=new QSqlQueryModel();
        QSqlQuery qry_odczyt("select Nazwa_produktu, Ilosc_kalorii, Koszt_produktu from Produkty where Id_restauracji = "
                             "(select Id_restauracje from Restauracje where Nazwa_restauracji= '"+item->text()+"') ");
        qry_odczyt.next();
        modal->setQuery(qry_odczyt);
        ui->tableView_produkty->setModel(modal);


    }
    else
        QMessageBox::warning(this,"Bazadanych","Błąd połączenia z bazą danych!");

}

void Glowna::on_pushButtonClose_wyjdz_clicked()
{
    QApplication::quit();
}

void Glowna::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void Glowna::on_tableView_produkty_doubleClicked(const QModelIndex &index)//tabela
{
    int row=index.row();
    QModelIndex produkt=ui->tableView_produkty->model()->index(row,0);
    QModelIndex kalorie=ui->tableView_produkty->model()->index(row,1);
    drugieOkno->SumujProdukty(produkt.data(0).toString(),kalorie.data(0).toString());
}
