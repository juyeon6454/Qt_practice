#include "personmodel.h"

#include <QListView>
#include <QTableView>
#include <QTreeView>
#include <QVBoxLayout>

PersonModel::PersonModel(QWidget *parent)
    : QAbstractListModel(parent)
{
    persons.append(new Person("Jamie Lannister", "red", 33));
    persons.append(new Person("Marry Lnae", "cyan", 26));
    persons.append(new Person("Steve Moors", "yellow", 44));
    persons.append(new Person("Victor Trunk", "dodgerblue", 30));
    persons.append(new Person("Ariel Geeny", "blue", 33));
    persons.append(new Person("Knut Vikran", "lightblue", 26));
}

PersonModel::~PersonModel()
{
    qDeleteAll(persons);
}
int PersonModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return persons.size();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const {
    if(index.row() < 0 || index.row()>=persons.count())
        return QVariant();

    Person * person = persons[index.row()];

    if(role == Qt::DisplayRole){
        return person->names() + " " + QString::number(index.row());

    }

    return QVariant();
}

