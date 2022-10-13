#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
#include <QList>

class QAction;
class QTextEdit;
class QLabel;
class QMdiArea;
class QMdiSubWindow;
class QFontComboBox;
class QDoubleSpinBox;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QtEditor : public QMainWindow
{
    Q_OBJECT

private:
    QAction *makeAction(QString icon, QString name, QString shorCut, QString toolTip, QObject* recv, const char* slot);
   // QTextEdit* textedit;
    QLabel* statusLabel;
    QMdiArea* mdiArea;
    QList<QAction*> actions;
    QTextEdit* prevTextEdit = nullptr;
    QHash<QAction*, QWidget*> windowHash;
    QMenu*windowMenu;
    QFontComboBox* fontComboBox;
    QDoubleSpinBox* sizeSpinBox;

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

public slots:
    void newFile();
    void open();//file
    void save();
    void saveAs();
    void print();
    void alignText();
    void font();
    void color();

    void undo();//edit
    void redo();
    void copy();
    void cut();
    void paste();
    void zoomIn();
    void zoomOut();
    //void makeEdit();
    void about();//help

    void setTextFont(QFont font);//font 밖
    void setTextSize(qreal size);
    void setFontWidget();
    void connectWindow(QMdiSubWindow*);

    void selectWindow();
   // void closeWindow();
    bool eventFilter(QObject *obj, QEvent *event);


};

#endif // QTEDITOR_H
