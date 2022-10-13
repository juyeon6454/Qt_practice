#include "widget.h"

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QCompleter>
#include <QComboBox>


//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    Widget w;
//    w.resize(400,200);

//    QLabel label("<font color=green>Hello, World!</font>",&w);
//    label.setGeometry(10, 10, 300, 40);

//    QLineEdit lineEdit1(&w);
//    lineEdit1. setEchoMode(QLineEdit::PasswordEchoOnEdit);
//    lineEdit1.setGeometry(10,50,300,30);

//    QLineEdit lineEdit2(&w);
//    lineEdit2.setGeometry(10,90,300,30);

//    QObject::connect(&lineEdit2, SIGNAL(textChanged(const QString &)), &label, SLOT(setText(const QString &)));

//    w.show();
//    return a.exec();
//}


//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    //Widget w;

//    QLineEdit *lineEdit = new QLineEdit();
//    QStringList CompletionList;
//    CompletionList<<"Bryan"<<"Bart"<<"Kelvin"<<"Beth"<<"Bard"<<"Kelly"<<"Amy"<<"Apple"<<"CAR";
//    QCompleter* StringCompleter = new QCompleter(CompletionList);
//    StringCompleter->setCaseSensitivity(Qt::CaseInsensitive);
//    //StringCompleter->setModel(new QDirModel(StringCompleter));
//    lineEdit->setCompleter(StringCompleter);
//    lineEdit->show();

//    return a.exec();
//}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

//    QComboBox *comboBox = new QComboBox();
//    comboBox->addItem("KDE");
//    comboBox->addItem("Gnome");
//    comboBox->addItem("FVWM");
//    comboBox->addItem("CDE");
//    comboBox->setEditable(true);
//    comboBox->show();
    w.show();
    return a.exec();
}


