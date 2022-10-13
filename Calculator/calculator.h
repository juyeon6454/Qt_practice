#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>

class QLabel;
class QPushButton;
class QButtonGroup;

class Calculator : public QWidget {
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator( );

private:
    QLabel* m_label;
    QButtonGroup* buttonGroup;
    QString m_num1, m_op;               // 두번째 값은 QLabel 객체에 표시되어 있다.
    bool m_isFirst;                     // 버튼을 처음 눌렀을 때
    const qint32 WITDH = 4;

public slots:
   void setNum( );
   void setOp( );
   void click(int id);
};
#endif // CALCULATOR_H
