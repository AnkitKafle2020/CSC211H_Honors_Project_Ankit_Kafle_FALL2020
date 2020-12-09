QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    createAccount.cpp \
    indstudentgrade.cpp \
    main.cpp \
    mainwindow.cpp \
    setquiz.cpp \
    studentQuizclass.cpp \
    studentchoice.cpp \
    studentgraderecord.cpp \
    teacherclass.cpp \
    testselector.cpp

HEADERS += \
    createAccount.h \
    indstudentgrade.h \
    mainwindow.h \
    setquiz.h \
    studentQuizclass.h \
    studentchoice.h \
    studentgraderecord.h \
    teacherclass.h \
    testselector.h

FORMS += \
    createAccount.ui \
    indstudentgrade.ui \
    mainwindow.ui \
    setquiz.ui \
    studentQuizclass.ui \
    studentchoice.ui \
    studentgraderecord.ui \
    teacherclass.ui \
    testselector.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
