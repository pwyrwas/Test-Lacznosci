#include <QCoreApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const QString hostName = "localhost";
    const QString dbFileName = "C:/database.FDB";
    const QString userName = "SYSDBA";
    const QString password = "orangepl";
    //qDebug() << hostName;
    //qDebug() << dbFileName;
    //qDebug() << userName;
    //qDebug() << password;
    QSqlDatabase db = QSqlDatabase::addDatabase("QIBASE","soct");

    if (!db.isValid())
        qDebug() << "The data base isn't valid";
    else
        qDebug() << "The data base is valid";

    //db.setHostName(hostName);

    db.setDatabaseName(dbFileName);
    db.setUserName(userName);
    db.setPassword(password);
    db.open();
    qDebug() << "Database last error:" << db.lastError().text();

    QSqlQuery query = QSqlQuery(db);
    QString queryString = "SELECT a.NICKNAME FROM PEOPLE a WHERE a.ID = '1'";
    query.prepare(queryString);
    query.exec();
    query.next();
    QString result = query.value(0).toString();
    qDebug() << "Query result: " << result;
    qDebug() << "query last error:" <<query.lastError().text();

    return a.exec();
}
