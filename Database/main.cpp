#include "database.h"

#include <QApplication>
#include <QTableView>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName(":memory:");//메모리 저장
    db.setDatabaseName("./tmp");//파일로저장
    if(!db.open()) return false;

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS person(id INTEGER Primary Key, "
               "firstname VARCHAR(20) NOT NULL, lastname VARCHAR(200));");
    query.exec("INSERT INTO person VALUES(101, 'Yongsu','Kang');");
    query.exec("INSERT INTO person(firstname, lastname) VALUES('Soomi','Kim')");
    query.exec("INSERT INTO person(firstname, lastname) VALUES"
               "('Hanmi','Lee'),('YoungJin','Suh'),('YoungHwa','Ryu');");

    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnection()) return 1;

//    QSqlQueryModel queryModel;//수정불가능
//    queryModel.setQuery("select * from person");

    QSqlTableModel queryModel;//수정가능
    queryModel.setTable("person");
//    queryModel.setEditStrategy(QSqlTableModel::OnManualSubmit);//저장되지 않도록 고정?
    queryModel.select();

    queryModel.setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    queryModel.setHeaderData(1, Qt::Horizontal, QObject::tr("firstname"));
    queryModel.setHeaderData(2, Qt::Horizontal, QObject::tr("lastname"));

    QTableView *tableview = new QTableView;
    tableview->setModel(&queryModel);
    tableview->setWindowTitle(QObject::tr("Query Model"));
    tableview->show();

//    Database w;
//    w.show();
    return a.exec();
}
