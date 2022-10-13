#include "widget.h"
#include <QLabel>
#include <QLineEdit>
#include <QValidator>
#include <QFormLayout>

//double,int 범위 밖의 값도 나옴
//Widget::Widget(QWidget *parent)
//{
//    QDoubleValidator* doubleValidator = new QDoubleValidator(this);
//   // doubleValidator->setRange(10.0, 100.0, 3);
//    doubleValidator->setBottom(10.0);
//    doubleValidator->setTop(100.0);
//    doubleValidator->setDecimals(3);

//    QIntValidator* intValidator = new QIntValidator(this);
//    //intValidator->setRange(13,19);
//    intValidator->setBottom(13);
//    intValidator->setTop(19);

//    QRegularExpressionValidator* regularExpressionValidator = new QRegularExpressionValidator(this);
//    regularExpressionValidator->setRegularExpression(
//                QRegularExpression("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}$"));

//    QLineEdit* lineEditDouble = new QLineEdit(this);
//    lineEditDouble->setValidator(doubleValidator);

//    QLineEdit* lineEditInt = new QLineEdit(this);
//    lineEditInt->setValidator(intValidator);

//    QLineEdit* lineEditRegularExpression = new QLineEdit(this);
//    lineEditRegularExpression->setValidator(regularExpressionValidator);

//    QFormLayout *formLayout = new QFormLayout(this);
//    formLayout->addRow("&Double", lineEditDouble);
//    formLayout->addRow("&Int", lineEditInt);
//    formLayout->addRow("&Regular Expression", lineEditRegularExpression);

//    setWindowTitle("Validator");

//}
//=============================================================

//#include <QHBoxLayout>
//#include <QPushButton>

//Widget::Widget(QWidget* parent) : QWidget(parent)
//{
//    QPushButton* pushButton1 = new QPushButton();
//    pushButton1->setText("Button1");
//    QPushButton* pushButton2 = new QPushButton("Button2");
//    QPushButton* pushButton3 = new QPushButton("Button3", this);

//    QHBoxLayout* hBoxLayout = new QHBoxLayout;
//    hBoxLayout->setContentsMargins(0,0,0,0);
//    hBoxLayout->addWidget(pushButton1);
//    hBoxLayout->addWidget(pushButton2);
//    hBoxLayout->addWidget(pushButton3);
//    setLayout(hBoxLayout);
//}

//=================================================================

//#include <QVBoxLayout>
//#include <QPushButton>

//Widget::Widget(QWidget* parent) : QWidget(parent)
//{
//    QPushButton* pushButton1 = new QPushButton();
//    pushButton1->setText("Button1");
//    QPushButton* pushButton2 = new QPushButton("Button2");
//    QPushButton* pushButton3 = new QPushButton("Button3", this);

//    QVBoxLayout* vBoxLayout = new QVBoxLayout(this);	//->setLayout()
//    vBoxLayout->setSpacing(6);
//    vBoxLayout->addWidget(pushButton1);
//    vBoxLayout->addWidget(pushButton2);
//    vBoxLayout->addWidget(pushButton3);

//}

//=======================================================================

//#include <QGridLayout>
//#include <QPushButton>
//#define NO_OF_ROW 3

//Widget::Widget(QWidget* parent) : QWidget(parent)
//{
//    QGridLayout* gridLayout = new QGridLayout;
//    QPushButton* pushButton[NO_OF_ROW * NO_OF_ROW];
//    for (int y = 0; y < NO_OF_ROW; y++) {
//        for (int x = 0; x < NO_OF_ROW; x++) {
//            int p = x + y * NO_OF_ROW;
//            QString str = QString("Button%1").arg(p + 1);
//            pushButton[p] = new QPushButton(str, this);
//            gridLayout->addWidget(pushButton[p], x, y);
//        }
//    }
//    setLayout(gridLayout);
//}

//=======================================================================

//#include <QStackedLayout>
//#include <QHBoxLayout>
//#include <QDial>
//#include <QLabel>
//#include <QCalendarWidget>
//#include <QTextEdit>

//Widget::Widget(QWidget* parent) : QWidget(parent)
//{
//  QDial* dial = new QDial(this);
//  dial->setRange(0,2);

//  QLabel* label = new QLabel("Stack 1", this);
//  QCalendarWidget* calendarWidget = new QCalendarWidget(this);
//  QTextEdit* textEdit = new QTextEdit("Stack 3", this);

//  QStackedLayout* stackedLayout = new QStackedLayout;
//  stackedLayout->addWidget(label);
//  stackedLayout->addWidget(calendarWidget);
//  stackedLayout->addWidget(textEdit);

//  connect(dial, SIGNAL(valueChanged(int)),\
//          stackedLayout, SLOT(setCurrentIndex(int)));

//  QHBoxLayout* hBoxLayout = new QHBoxLayout(this);
//  hBoxLayout->addWidget(dial);
//  hBoxLayout->addLayout(stackedLayout);

//  setLayout(hBoxLayout);
//}

//================================================================

//#include <QFormLayout>
//#include <QLineEdit>
//#include <QDateEdit>

//Widget::Widget(QWidget *parent):QWidget(parent)
//{
//    QLineEdit* ipAddressLineEdit = new QLineEdit(this);
//    ipAddressLineEdit->setPlaceholderText("IP Address");
//    ipAddressLineEdit->setInputMask("000.000.000.000;_");

//    QLineEdit* macAddressLineEdit = new QLineEdit(this);
//    macAddressLineEdit->setInputMask("HH:HH:HH:HH:HH:HH;_");

//    QDateEdit* dateEdit = new QDateEdit(QDate::currentDate(), this);
//    dateEdit->setDisplayFormat("yyyy.MM.dd");

//    QFormLayout *formLayout = new QFormLayout(this);
//    formLayout->addRow("&IP Address", ipAddressLineEdit);
//    formLayout->addRow("&Mac Address", macAddressLineEdit);
//    formLayout->addRow("&Date", dateEdit);
//}

//================================================================

//#include <QFrame>

//Widget::Widget(QWidget *parent):QWidget(parent)
//{
//    QFrame* plainLine = new QFrame(this);
//    plainLine->setGeometry(QRect(0,0,270,16));
//    plainLine->setLineWidth(2);
//    plainLine->setFrameStyle(QFrame::HLine | QFrame::Plain);

//    QFrame* raisedLine = new QFrame(this);
//    raisedLine->setGeometry(QRect(0,20,270,16));
//    raisedLine->setLineWidth(2);
//    raisedLine->setFrameStyle(QFrame::HLine | QFrame::Raised);

//    QFrame* sunkenLine = new QFrame(this);
//    sunkenLine->setGeometry(QRect(0,30,270,16));
//    sunkenLine->setLineWidth(2);
//    sunkenLine->setFrameStyle(QFrame::HLine | QFrame::Sunken);


//}

//===================================================================

//#include <QGroupBox>
//#include <QFormLayout>
//#include <QLineEdit>

//Widget::Widget(QWidget *parent):QWidget(parent)
//{
//    QLineEdit* lineEdit[3];
//    for(int i = 0; i<3; i++) lineEdit[i] = new QLineEdit(this);

//    QFormLayout *formLayout = new QFormLayout;
//    formLayout->addRow("&IP Address", lineEdit[0]);
//    formLayout->addRow("&Mac Address", lineEdit[1]);
//    formLayout->addRow("&Date", lineEdit[2]);

//    QGroupBox *groupBox = new QGroupBox("&Widget Group", this);
//    groupBox->move(5,5);
//    groupBox->setLayout(formLayout);
//    groupBox->setFlat(true);

//    resize(groupBox->sizeHint().width()+10,
//           groupBox->sizeHint().height()+10);

//}
//==================================================================

//#include <QTabWidget>
//#include <QDial>
//#include <QCalendarWidget>
//#include <QTextEdit>

//Widget::Widget(QWidget *parent):QWidget(parent)
//{

//      QDial* dial = new QDial(this);
//      QCalendarWidget* calendarWidget = new QCalendarWidget(this);
//      QTextEdit* textEdit = new QTextEdit("Stack 3", this);

//      QTabWidget* tabWidget = new QTabWidget(this);
//      tabWidget->addTab(dial, "Tab &1");
//      tabWidget->addTab(calendarWidget, "Tab 2");
//      tabWidget->addTab(textEdit, "Tab 3");

//      resize(tabWidget->sizeHint());

//}

//====================================================================
#include <QSplitter>
#include <QLabel>
#include <QDial>

Widget::Widget(QWidget *parent):QWidget(parent)
{
    QLabel* label = new QLabel("IP Address", this);
    QDial* dial = new QDial(this);
    label->setBuddy(dial);

    QSplitter *splitter= new QSplitter(this);
    splitter->addWidget(label);
    splitter->addWidget(dial);

    resize(splitter->sizeHint());
}

//===================================================================

Widget::~Widget()
{
}


