#include <QCoreApplication>
#include <QVector>
#include <QList>
#include <QDebug>
//#include <QLinkedList>//qt6에서는 단일화됨 <QList>
#include <QSet>
#include <QString>
#include <QHash>
#include <QMap>

//=============================================================================
//template<class T>
//void fill(T &container){
//    for(int i = 0; i<5; i++)
//        container.append(i);
//}

//template<class T>
//void display(T &container){
//    for(int i = 0; i<container.length(); i++){
//        if(i>0){
//            auto current = reinterpret_cast<std::uintptr_t>(&container.at(i));
//            auto previous = reinterpret_cast<std::uintptr_t>(&container.at(i-1));
//            auto distance = current-previous;

//            qInfo()<<i<<"At: "<<current<<"Previous: ";
//            qInfo()<<previous<<"Distance: "<<distance;
//        }else{
//            qInfo()<<i<<&container.at(i)<<"Distance: 0";

//        }
//    }
//}

//int main(int argc, char *argv[]){
//    QCoreApplication a(argc, argv);

//    QVector<int>vect=QVector<int>();
//    QList<int>list=QList<int>();

//    fill(vect);
//    fill(list);

//    qInfo()<<"Int takes"<<sizeof(int)<<"bytes of ram";
//    qInfo()<<"QVector uses continuous locations in memory!";
//    display(vect);
//    qInfo("");
//    qInfo()<<"QList uses whar ever it can find in memory!";
//    display(list);
//    qInfo("");

//    return a.exec();
//}

//=====================QLinkedList->QList================================================

//int main(int argc, char *argv[]){

//    QCoreApplication a(argc, argv);

//    QList<int>list;
//    for(int i=0; i<10;i++) list.append(i);

//    list.removeFirst();
//    list.removeLast();
//    list.removeOne(5);
//    if(list.contains(3)) qInfo()<<"Contains 3";
//    list.clear();

//    qInfo()<<"Done";

//    return a.exec();
//}

//=====================QSet============================================

//int main(int argc, char *argv[]){
//    QCoreApplication a(argc, argv);
//    QSet<QString> people;
//    people<<"Bryan"<<"Heather"<<"Tammy"<<"Chris";
//    people.insert("Rango");

//    foreach(QString person, people){
//        qInfo()<<person;
//    }
//    //Very Fast
//    qInfo()<<"Bryan in collection: "<<people.contains("Bryan");

//    return a.exec();
//}

//===================QHash=========================================

//int main(int argc, char *argv[]){
//    QCoreApplication a(argc, argv);

//    QHash<QString, int> ages;
//    ages.insert("Bryan", 44);
//    ages.insert("Tammy", 49);
//    ages.insert("Heather", 25);
//    ages.insert("Chris", 27);
//    ages.insert("Rango", 15);

//    qInfo()<<"Bryan is "<<ages["Bryan"]<<"year old";
//    qInfo()<<"Keys: "<<ages.keys();
//    qInfo()<<"Size: "<<ages.size();

//    foreach(QString key, ages.keys())
//        qInfo()<<key<<"="<<ages[key];

//    return a.exec();

//}

//===========QMap=====================================

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    QMap<QString, int> ages;
    ages.insert("Bryan", 44);
    ages.insert("Tammy", 49);
    ages.insert("Heather", 25);
    ages.insert("Chris", 27);
    ages.insert("Rango", 15);

    qInfo()<<"Bryan is "<<ages["Bryan"]<<"year old";
    qInfo()<<"Keys: "<<ages.keys();
    qInfo()<<"Size: "<<ages.size();

    foreach(QString key, ages.keys())
        qInfo()<<key<<"="<<ages[key];

    return a.exec();

}

