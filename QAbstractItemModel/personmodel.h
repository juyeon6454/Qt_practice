#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractListModel>
#include <QList>
#include "person.h"

class PersonModel : public QAbstractListModel
{
    Q_OBJECT

public:
    PersonModel(QWidget *parent = nullptr);
    ~PersonModel();

    //QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

private:
    QList<Person *> persons;
};
#endif // PERSONMODEL_H
