QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp

HEADERS += \
    widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../opencv-4.7.0-windows/opencv/build/x64/vc16/lib/ -lopencv_world470
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../opencv-4.7.0-windows/opencv/build/x64/vc16/lib/ -lopencv_world470d
else:unix: LIBS += -L$$PWD/../../../opencv-4.7.0-windows/opencv/build/x64/vc16/lib/ -lopencv_world470

INCLUDEPATH += $$PWD/../../../opencv-4.7.0-windows/opencv/build/x64/vc16
DEPENDPATH += $$PWD/../../../opencv-4.7.0-windows/opencv/build/x64/vc16

INCLUDEPATH += $$PWD/../../../opencv-4.7.0-windows/opencv/build/include

