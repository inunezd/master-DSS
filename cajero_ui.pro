QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    altawindow.cpp \
    encriptado.cpp \
    ingresosaldo.cpp \
    login.cpp \
    main.cpp \
    mainuser.cpp \
    mostrardetalle.cpp \
    retiradasaldo.cpp \
    simplecrypt.cpp \
    validaciones.cpp

HEADERS += \
    altawindow.h \
    encriptado.h \
    ingresosaldo.h \
    login.h \
    mainuser.h \
    mostrardetalle.h \
    retiradasaldo.h \
    simplecrypt.h \
    validaciones.h

FORMS += \
    altawindow.ui \
    ingresosaldo.ui \
    login.ui \
    mainuser.ui \
    mostrardetalle.ui \
    retiradasaldo.ui

TRANSLATIONS += \
    cajero_ui_es_ES.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target




