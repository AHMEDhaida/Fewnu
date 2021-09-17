QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authentication.cpp \
    classproduit.cpp \
    home.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp\
    produit.cpp \
    produitmodel.cpp \
    service.cpp \
    simplecrypt.cpp \
    stock.cpp \
    user.cpp \
    usermodel.cpp \
    dbaccess.cpp \
    flowcontroller.cpp\
    vente.cpp

HEADERS += \
    authentication.h \
    classproduit.h \
    home.h \
    login.h \
    mainwindow.h\
    produit.h \
    produitmodel.h \
    simplecrypt.h \
    stock.h \
    user.h \
    usermodel.h \
    service.h \
    dbaccess.h \
    flowcontroller.h\
    vente.h

FORMS += \
    authentication.ui \
    home.ui \
    login.ui \
    mainwindow.ui \
    produit.ui \
    stock.ui \
    vente.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
