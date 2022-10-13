/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QDial *dial;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QSplitter *splitter;
    QLabel *label;
    QLineEdit *lineEdit;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(275, 406);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        dial = new QDial(Widget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setWrapping(true);
        dial->setNotchesVisible(true);

        verticalLayout_2->addWidget(dial);

        horizontalSlider = new QSlider(Widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBothSides);

        verticalLayout_2->addWidget(horizontalSlider);

        spinBox = new QSpinBox(Widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setWrapping(true);
        spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);

        verticalLayout_2->addWidget(spinBox);

        splitter = new QSplitter(Widget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        splitter->addWidget(label);
        lineEdit = new QLineEdit(splitter);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setCursorPosition(0);
        splitter->addWidget(lineEdit);

        verticalLayout_2->addWidget(splitter);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

#if QT_CONFIG(shortcut)
        label->setBuddy(lineEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Widget);
        QObject::connect(dial, &QDial::valueChanged, horizontalSlider, &QSlider::setValue);
        QObject::connect(spinBox, &QSpinBox::valueChanged, dial, &QDial::setValue);
        QObject::connect(horizontalSlider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
        QObject::connect(spinBox, &QSpinBox::textChanged, lineEdit, &QLineEdit::setText);
        QObject::connect(pushButton, &QPushButton::clicked, Widget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "&Value", nullptr));
        lineEdit->setInputMask(QCoreApplication::translate("Widget", "99", nullptr));
        lineEdit->setText(QCoreApplication::translate("Widget", "0", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Widget", "Input the number", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "&Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
