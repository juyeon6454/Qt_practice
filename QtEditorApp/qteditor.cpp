#include "qteditor.h"
#include <QTextEdit>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QToolBar>
#include <QFontComboBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QColorDialog>
#include <QFontDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QHash>
#include <QFile>
#include <QFileInfo>
#include <QKeyEvent>

QtEditor::QtEditor(QWidget *parent)
    : QMainWindow(parent)//생성자를 불러서 초기화 qmainwindow class의 생성자
{
    mdiArea = new QMdiArea(this);
    setCentralWidget(mdiArea);


   // QTextEdit *textedit = new QTextEdit(this);//로컬변수가 아닌 멤버변수로
    //textedit = new QTextEdit(this);
    //setCentralWidget(textedit);//등록 //이부분이 없으면 입력하는 부분과 window창 크기가 따로 논다
    //mdiArea->addSubWindow(textedit);

    QMenuBar *menubar = new QMenuBar(this); //두 가지 방법 가능
    setMenuBar(menubar);
//    QMenuBar *menubar = this->menuBar();

   // setMenuBar(menubar);

    QAction *newAct = makeAction("new.png",tr("&New"),"Ctrl+0",tr("make new file"),this,SLOT(newFile()));
//    QAction *newAct = new QAction(QIcon("new.png"),"&New",this);
//    newAct->setShortcut(tr("Ctrl+N"));
//    newAct->setStatusTip(tr("make new file"));
//    connect(newAct, SIGNAL(triggered()),SLOT(newFile()));

    QAction *openAct = makeAction("open.png",tr("&Open"),"Ctrl+1",tr("Open this program"),this,SLOT(open()));
    QAction *saveAct = makeAction("save.png",tr("&Save"),"Ctrl+2",tr("Save this file"),this,SLOT(save()));
    QAction *saveasAct = makeAction("saveas.png",tr("&Save As"),"Ctrl+3",tr("Save as this file"),this,SLOT(saveAs()));
    QAction *printAct = makeAction("print.svg",tr("&Print"),"Ctrl+4",tr("Print this file"),this,SLOT(print()));
    QAction *quitAct = makeAction("quit.svg",tr("&Quit"),"Ctrl+5",tr("Quit this program"),qApp,SLOT(quit()));
//    QAction *quitAct = new QAction("&Quit",this);
//    connect(quitAct, SIGNAL(triggered()),qApp, SLOT(quit()));
//    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(about(Qt()));r

    QAction *undoAct = makeAction("undo.png",tr("&Undo"),"Ctrl+6",tr("Undo"),this,SLOT(undo()));
    //QAction *undoAct = makeAction(":/images/undo.png","&Undo","Ctrl+U","Undo this program",textedit,SLOT(undo()));
    QAction *redoAct = makeAction("redo.svg",tr("&Redo"),"Ctrl+7",tr("Redo"),this,SLOT(redo()));
    QAction *copyAct = makeAction("copy.png",tr("&Copy"), "Ctrl+8",tr("Copy this text"), this,SLOT(copy()));
    QAction *cutAct = makeAction("cut.png",tr("&Cut"),"Ctrl+9",tr("Cut this text"),this,SLOT(cut()));
    QAction *pasteAct = makeAction("paste.png",tr("&Paste"),"Ctrl+D",tr("Paste this text"),this,SLOT(paste()));
    QAction *zoomInAct = makeAction("zoomIn.svg",tr("&ZoomIn"),"Ctrl+E",tr("Zoom in this text"),this,SLOT(zoomIn()));
    QAction *zoomOutAct = makeAction("zoomOut.svg",tr("&ZoomOut"),"Ctrl+F",tr("Zoom out this text"),this,SLOT(zoomOut()));

    QAction *alignLeftAct = new QAction(tr("&Left"),this);
    connect(alignLeftAct, SIGNAL(triggered()),this,SLOT(alignText()));
    QAction *alignCenterAct = new QAction(tr("&Center"),this);
    connect(alignCenterAct, SIGNAL(triggered()),SLOT(alignText()));
    QAction *alignRightAct = new QAction(tr("&Right"),this);
    connect(alignRightAct, SIGNAL(triggered()),SLOT(alignText()));
    QAction *alignJustifyAct = new QAction(tr("&Justify"),this);
    connect(alignJustifyAct, SIGNAL(triggered()),SLOT(alignText()));

    QAction *fontAct = makeAction("font.svg",tr("&Font"),"Ctrl+G",tr("font in this program"),this,SLOT(font()));
    QAction *colorAct = makeAction("color.svg",tr("&Color"),"Ctrl+H",tr("color this program"),this,SLOT(color()));

    QAction *activateNextSubWindowAct = new QAction(tr("&ActivateNextSubWindow"),this);
    connect(activateNextSubWindowAct, SIGNAL(triggered()), mdiArea, SLOT(activateNextSubWindow()));
    QAction *activatePreviousSubWindowAct = new QAction(tr("&ActivateNextSubWindow"),this);
    connect(activatePreviousSubWindowAct, SIGNAL(triggered()), mdiArea, SLOT(activatePreviousSubWindow()));
    QAction *cascadeSubWindowsAct = new QAction(tr("&CascadeSubWindows"),this);
    connect(cascadeSubWindowsAct, SIGNAL(triggered()), mdiArea, SLOT(cascadeSubWindows()));
    QAction *closeActiveSubWindowAct = new QAction(tr("&CloseActiveSubWindow"),this);
    connect(closeActiveSubWindowAct, SIGNAL(triggered()), mdiArea, SLOT(closeActiveSubWindow()));
    QAction *closeAllSubWindowsAct = new QAction(tr("&CloseAllSubWindows"),this);
    connect(closeAllSubWindowsAct, SIGNAL(triggered()), mdiArea, SLOT(closeAllSubWindows()));
//    QAction *setActiveSubWindowAct = new QAction("&SetActiveSubWindow",this);
    //connect(setActiveSubWindowAct, SIGNAL(triggered()), mdiArea, SLOT());
    QAction *tileSubWindowsAct = new QAction(tr("&TileSubWindows"),this);
    connect(tileSubWindowsAct, SIGNAL(triggered()), mdiArea, SLOT(tileSubWindows()));

    QAction *aboutAct = makeAction("", tr("&About"), tr("Ctrl+J"), tr("About"), this, SLOT(about()));
    //QAction *aboutQtAct = makeAction("", "&About Qt", tr("Ctrl+K"), tr("AboutQt"), this, SLOT(aboutQt()));
    QAction *aboutQtAct = new QAction(tr("&About Qt"),this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp , SLOT(aboutQt()));


    QMenu *fileMenu = menubar->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(printAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveasAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    QToolBar *fileToolBar = addToolBar(tr("&File"));
    fileToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    fileToolBar->addAction(newAct);
    fileToolBar->addSeparator();
    fileToolBar->addAction(quitAct);
    fileToolBar->addAction(undoAct);
    fileToolBar->addAction(redoAct);


    windowMenu = menubar->addMenu(tr("&Window"));
    windowMenu->addAction(fileToolBar->toggleViewAction());

    fontComboBox = new QFontComboBox(this);
    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)),this,SLOT(setTextFont(QFont)));
    sizeSpinBox = new QDoubleSpinBox(this);
    connect(sizeSpinBox, SIGNAL(valueChanged(double)),this,SLOT(setTextSize(qreal)));
    addToolBarBreak();

    QToolBar *formatToolbar = addToolBar(tr("&Format"));
    formatToolbar->addSeparator();
    formatToolbar->addWidget(fontComboBox);
    formatToolbar->addWidget(sizeSpinBox);
    fileToolBar->addAction(quitAct);

    QStatusBar* statusbar = statusBar();//하단 상태 (시작할때 왼쪽 하단 started)
    QLabel* statusLabel = new QLabel(tr("Qt Editor"),statusbar);
    statusLabel->setObjectName("StautsLabel");
    statusbar->addPermanentWidget(statusLabel);
    statusbar->showMessage("started", 1500);

    QMenu *alignMenu = new QMenu(tr("&Align"), this);
    alignMenu->addAction(alignLeftAct);
    alignMenu->addAction(alignCenterAct);
    alignMenu->addAction(alignRightAct);
    alignMenu->addAction(alignJustifyAct);

    QMenu *editMenu = menubar->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(cutAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(zoomInAct);
    editMenu->addAction(zoomOutAct);
    editMenu->addSeparator();

    QMenu *formatMenu = menubar->addMenu(tr("&Format"));
    formatMenu->addAction(fontAct);
    formatMenu->addAction(colorAct);
    formatMenu->addMenu(alignMenu);
    formatMenu->addMenu(alignMenu);

    QMenu *windowsMenu = menubar->addMenu(tr("&Windows"));
    windowsMenu->addAction(activateNextSubWindowAct);
    windowsMenu->addAction(activatePreviousSubWindowAct);
    windowsMenu->addAction(cascadeSubWindowsAct);
    windowsMenu->addAction(closeActiveSubWindowAct);
    windowsMenu->addAction(closeAllSubWindowsAct);
//    windowsMenu->addAction(setActiveSubWindowAct);
    windowsMenu->addAction(tileSubWindowsAct);

    QMenu *helpMenu = menubar->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    QLabel * label = new QLabel(tr("Dock Widget"), this);
    QDockWidget *dock = new QDockWidget(tr("Dock Widget"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    dock->setWidget(label);

    //textedit = new QTextEdit(this);

    windowMenu->addAction(dock->toggleViewAction());

    actions.append(undoAct);         /* QList에 QAction들을 추가 */
    actions.append(redoAct);
    actions.append(copyAct);
    actions.append(cutAct);
    actions.append(pasteAct);
    actions.append(zoomInAct);
    actions.append(zoomOutAct);
    connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            SLOT(connectWindow(QMdiSubWindow*)));

    newFile();

}

QAction *QtEditor::makeAction(QString icon, QString name, QString shortCut, QString toolTip, QObject* recv, const char* slot)

{
    QAction *act = new QAction(name, this);
    if(icon.length())
        act->setIcon(QIcon(icon));
    act->setShortcut(shortCut);
    act->setStatusTip(toolTip);
    connect(act, SIGNAL(triggered()),recv,slot);
    return act;
}


void QtEditor::alignText(){

    QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
    if(subWindow == nullptr)
        return;
    QTextEdit *textedit = qobject_cast<QTextEdit*>(subWindow->widget());
    QAction *action = qobject_cast<QAction*>(sender());

    if(action->text()==tr("&Left"))textedit->setAlignment(Qt::AlignLeft);
    else if(action->text()==tr("&Center"))textedit->setAlignment(Qt::AlignCenter);
    else if(action->text()==tr("&Right"))textedit->setAlignment(Qt::AlignRight);
    else if(action->text()==tr("&Justify"))textedit->setAlignment(Qt::AlignJustify);

}   //if(action->text().contains("Center",Qt::CaseInsensitive))


void QtEditor::newFile()
{
    qDebug("Make New File");
    QAction* windowAct=new QAction("New File",this);
    windowMenu->addAction(windowAct);
    QTextEdit *textedit = new QTextEdit;
    connect(textedit, SIGNAL(destroyed(QObject*)), textedit, SLOT(deleteLater()));
    connect(textedit, SIGNAL(destroyed(QObject*)), windowAct, SLOT(deleteLater()));
    //connect(textedit, SIGNAL(destroyed(QObject*)), this, SLOT(closeWindow()));
    connect(textedit, SIGNAL(cursorPositionChanged()), SLOT(setFontWidget()));
    mdiArea->addSubWindow(textedit);
    windowHash[windowAct]=textedit;
    connect(windowAct, SIGNAL(triggered()), SLOT(selectWindow()));
    textedit->show();
    textedit->installEventFilter(this);

}

void QtEditor::selectWindow(){
    QTextEdit* textedit = (QTextEdit*)windowHash[(QAction*)sender()];
    if(textedit) textedit->setFocus();
}

//void QtEditor::closeWindow()
//{
//    QTextEdit* textedit=(QTextEdit*)sender();
//    windowMenu->removeAction(windowHash.key(textedit));
//    delete windowHash.key(this);
//}

void QtEditor::connectWindow(QMdiSubWindow* window)
{
    if(window == nullptr) {
        prevTextEdit = nullptr;
        return;
    }
    QTextEdit *textEdit = qobject_cast<QTextEdit*>(window->widget( ));
    if(textEdit == nullptr) return;
    if(prevTextEdit != nullptr) {
        Q_FOREACH(QAction *action, actions)      /* 모든 QAction에 연결된 슬롯 해제 */
            action->disconnect(prevTextEdit);
    }
    prevTextEdit = textEdit;         /* 현재 객체를 다음 처리를 위해 저장 */

    // 슬롯들을 위한 배열
    const char *methods[7] = {
        SLOT(undo( )), SLOT(redo( )), SLOT(copy( )), SLOT(cut( )),
        SLOT(paste( )), SLOT(zoomIn( )), SLOT(zoomOut( ))
    };

    /* QAction에 현재 선택된 객체의 슬롯을 연결 */
    int cnt = 0;
    Q_FOREACH(QAction *action, actions) {
        connect(action, SIGNAL(triggered()), textEdit, methods[cnt++]);
    }
}

//void QtEditor::makeEdit()
//{
//     QAction *action = qobject_cast<QAction*>(sender());
//     QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
//     if(subWindow != nullptr){
//         QTextEdit *textedit = dynamic_cast<QTextEdit*>(subWindow->widget());
//         mdiArea->setActiveSubWindow(subWindow);
//         if(action->text()=="&Undo")textedit->undo();
//         else if(action->text()=="&Redo")textedit->redo();
//         else if(action->text()=="&Copy")textedit->copy();
//         else if(action->text()=="&Cut")textedit->cut();
//         else if(action->text()=="&Paste")textedit->paste();
//         else if(action->text()=="&ZoomIn")textedit->zoomIn();
//         else if(action->text()=="&ZoomOut")textedit->zoomOut();
//    }
//}


void QtEditor::undo()
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
    if(subWindow != nullptr){
        QTextEdit *textedit =
                dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->undo();
    }
}

void QtEditor::redo()
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
    if(subWindow != nullptr){
        QTextEdit *textedit =
                dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->redo();
    }
}

void QtEditor::copy()
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
    if(subWindow != nullptr){
        QTextEdit *textedit =
                dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->copy();
    }
}


void QtEditor::cut()
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
    if(subWindow != nullptr){
        QTextEdit *textedit =
                dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->cut();
    }
}

void QtEditor::paste()
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
    if(subWindow != nullptr){
        QTextEdit *textedit =
                dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->paste();
    }
}

void QtEditor::zoomIn()
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
    if(subWindow != nullptr){
        QTextEdit *textedit =
                dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->zoomIn();
    }
}

void QtEditor::zoomOut()
{
    QMdiSubWindow *subWindow = mdiArea->currentSubWindow();
    if(subWindow != nullptr){
        QTextEdit *textedit =
                dynamic_cast<QTextEdit*>(subWindow->widget());
        textedit->zoomOut();
    }
}

void QtEditor::setTextFont(QFont font)
{
   // QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QMdiSubWindow* subwindow=mdiArea->currentSubWindow();
    if (subwindow==nullptr) return;
    QTextEdit* textedit = dynamic_cast<QTextEdit*>(subwindow->widget());
    textedit->setCurrentFont(font);
}

void QtEditor::setTextSize(qreal size)
{
   // QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
    QMdiSubWindow* subwindow=mdiArea->currentSubWindow();
    if (subwindow==nullptr) return;
    QTextEdit* textedit = dynamic_cast<QTextEdit*>(subwindow->widget());
    QFont font = textedit->currentFont();
    font.setPointSizeF(size);
    textedit->setCurrentFont(font);
}

void QtEditor::setFontWidget()
{
    QMdiSubWindow* subwindow=mdiArea->currentSubWindow();
    if (subwindow==nullptr) return;
    QTextEdit* textedit = dynamic_cast<QTextEdit*>(subwindow->widget());

    //QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();

    QFont font = textedit->currentFont();
    fontComboBox->setCurrentFont(font);
    sizeSpinBox->setValue(font.pointSizeF());

  //  connect(mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), SLOT(setFontWidget()));
}

void QtEditor::open()
{
//   // qDebug("open File");
////    QMdiArea * mdiarea = new QMdiArea;
////    mdiArea->activateNextSubWindow();
////    mdiarea->show();
//    qDebug("open File");
//    QString filename = QFileDialog::getOpenFileName(this, "Select a file to open", ".", "Text File(*.txt *.html *.htm *.c *.cpp *.h)");
//    qDebug()<<filename;

//    QFileInfo fileInfo(filename);
//    if(fileInfo.isReadable()){
//        QFile* file=new QFile(filename);
//        file->open(QIODevice::ReadOnly);
//        QByteArray msg=file->readAll();
//        file->close();
//        delete file;

//        QTextEdit* textedit = new QTextEdit(this);
//        textedit->setWindowTitle(filename);
//        textedit->setHtml(msg);
//        mdiArea->addSubWindow(textedit);
//        textedit->show();
//    }else{
//        QMessageBox::warning(this, "Error", "Can't Read this file",QMessageBox::Ok);

//    }


    qDebug("Open a File");
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "Select a file to open", ".",
                                                    "Text File(*.text *.txt *.html *.htm *.c *.cpp *.h)");
    qDebug() << filename;

    QFileInfo fileInfo(filename);
    if(fileInfo.isReadable()) {
        QFile file(filename);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QByteArray msg = file.readAll();
        file.close();

        newFile();
        QTextEdit* textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();
        textedit->setWindowTitle(filename);
        windowHash.key(textedit)->setText(filename);
        if(fileInfo.suffix() == "htm" || fileInfo.suffix() == "html")
            textedit->setHtml(msg);
        else
            textedit->setPlainText(msg);
    } else {
        QMessageBox::warning(this, "Error", "Can't Read this file", QMessageBox::Ok);
    }

}

void QtEditor::save()
{   
    qDebug("save File");
    QMdiSubWindow* subwindow=mdiArea->currentSubWindow();
    if (subwindow!=nullptr) {
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subwindow->widget());
        QString filename = textedit->windowTitle();

        if(!filename.length()){
            filename = QFileDialog::getSaveFileName(this,
                                                    "Select a file to open", ".",
                                                    "Text File(*.text *.txt *.html *.htm *.c *.cpp *.h)");
            textedit->setWindowTitle(filename);
        }

        QFile*file=new QFile(filename);
        file->open(QIODevice::WriteOnly|QIODevice::Text);
        QFileInfo fileInfo(filename);
        if(fileInfo.isWritable()){//if(file0>error()!=QFile::OpenError){
            QByteArray msg = textedit->toHtml( ).toUtf8( );   // QString을 QByteArray로 변환
            file->write(msg);
        }else{
            QMessageBox::warning(this, "Error", "Can't Save this file", QMessageBox::Ok);

        }
        file->close();
        delete file;
    }
//    QString filename = QFileDialog::getSaveFileName(this, "Select file to save", ".", "Text File(*.text *.txt *.html *.htm *.c *.cpp *.h)");
//    qDebug()<<filename;
//    windowHash.key(this)->setText(filename);
}

void QtEditor::saveAs()
{
    qDebug("save File");
    QMdiSubWindow* subwindow=mdiArea->currentSubWindow();
    if (subwindow!=nullptr) {
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subwindow->widget());
        QString filename = QFileDialog::getSaveFileName(this,
                                                        "Select a file to open", ".",
                                                        "Text File(*.text *.txt *.html *.htm *.c *.cpp *.h)");
        textedit->setWindowTitle(filename);
        QFile* file = new QFile(filename);
        file->open(QIODevice::WriteOnly|QIODevice::Text);
        QFileInfo fileInfo(filename);
        if(fileInfo.isWritable()){//if(file0>error()!=QFile::OpenError){
            QByteArray msg = textedit->toHtml( ).toUtf8( );   // QString을 QByteArray로 변환
            file->write(msg);
        }else{
            QMessageBox::warning(this, "Error", "Can't Save this file", QMessageBox::Ok);

        }
        file->close();
        delete file;
    }
}
void QtEditor::print()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setFullPage(true);
    QPrintDialog printDialog(&printer, this);
    if(printDialog.exec()==QDialog::Accepted){
        QMdiSubWindow* subwindow=mdiArea->currentSubWindow();
        if (subwindow!=nullptr) {
            QTextEdit* textedit = dynamic_cast<QTextEdit*>(subwindow->widget());
            textedit->print(&printer);
        }
    }
}

void QtEditor::font()
{
   // QTextEdit* textedit = dynamic_cast<QTextEdit*>(subwindow->widget());

    bool ok;
    QMdiSubWindow* subwindow=mdiArea->currentSubWindow();
    if (subwindow!=nullptr) {
        QTextEdit* textedit = dynamic_cast<QTextEdit*>(subwindow->widget());
        QFont font = QFontDialog::getFont(&ok, textedit->currentFont(), this);
        if(ok) textedit->setCurrentFont(font);
    }
}

void QtEditor::color()
{

    QMdiSubWindow* subwindow=mdiArea->currentSubWindow();
    if (subwindow==nullptr) return;
    QTextEdit* textedit = dynamic_cast<QTextEdit*>(subwindow->widget());

//    QMdiSubWindow* subwindow=mdiArea->currentSubWindow();
//    if (subwindow==nullptr) return;
//    QTextEdit *textedit = (QTextEdit*)mdiArea->currentSubWindow()->widget();

    QColor color = QColorDialog::getColor(textedit->textColor(), this);
    if(color.isValid()) textedit->setTextColor(color);
}

void QtEditor::about()
{
    QMessageBox::question(this, "QMessageBox::showQuestion()", "Question Message", QMessageBox::Yes|QMessageBox::No| QMessageBox::Cancel);
}

bool QtEditor::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPress){
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        qDebug("Key press %d", keyEvent->key());
        return true;
    }else{
        return QObject::eventFilter(obj, event);
    }
}



QtEditor::~QtEditor()
{
}

