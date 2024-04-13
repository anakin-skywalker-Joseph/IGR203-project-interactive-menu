QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = McDonald
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SOURCES += \
    carte2.cpp \
    carte3.cpp \
    carte4.cpp \
        main.cpp \
        mainwindow.cpp \
    payment.cpp \
    template.cpp \
    detail.cpp \
    commande.cpp \
    carte.cpp \
    catalogue.cpp \
    menu.cpp \
    accueil.cpp \
    connexion.cpp \
    espaceabo.cpp \
    inscription.cpp \
    catalogueitem.cpp \
    famille.cpp \
    recherche.cpp \
    menumodel.cpp \
    plat.cpp \
    membre.cpp \
    model.cpp \
    commandemodel.cpp \
    quantityspinbox.cpp

HEADERS += \
    carte2.h \
    carte3.h \
    carte4.h \
        mainwindow.h \
    payment.h \
    template.h \
    detail.h \
    commande.h \
    carte.h \
    catalogue.h \
    menu.h \
    accueil.h \
    connexion.h \
    espaceabo.h \
    inscription.h \
    model.h \
    catalogueitem.h \
    famille.h \
    recherche.h \
    menumodel.h \
    plat.h \
    membre.h \
    commandemodel.h \
    quantityspinbox.h \
    commandeitem.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
