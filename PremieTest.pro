    aQT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CBDD.cpp\
    CJsonTool.cpp \
    CProfil.cpp \
    CUser.cpp \
    CUserController.cpp \
    dialogaddprofil.cpp \
    dialogcreatuser.cpp \
    dialogquery.cpp \
    dialogremoveprofil.cpp \
    dialogremoveuser.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CBDD.h \
    CBDD.h\
    CJsonTool.h \
    CProfil.h \
    CUser.h \
    CUserController.h \
    dialogaddprofil.h \
    dialogcreatuser.h \
    dialogquery.h \
    dialogremoveprofil.h \
    dialogremoveuser.h \
    mainwindow.h

FORMS += \
    dialogaddprofil.ui \
    dialogcreatuser.ui \
    dialogquery.ui \
    dialogremoveprofil.ui \
    dialogremoveuser.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
