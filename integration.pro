QT       += core gui serialport
QT += core gui sql printsupport network serialport
QT += core gui charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduino_alarm.cpp \
    arduinocarte.cpp \
    bondescommandes.cpp \
    carte_ithen.cpp \
    chantiers.cpp \
    client.cpp \
    conges.cpp \
    connection.cpp \
    don.cpp \
    employe.cpp \
    famille.cpp \
    first.cpp \
    fournisseurs.cpp \
    gestion_chantiers.cpp \
    gestion_dons.cpp \
    gestion_employe.cpp \
    gestion_evenement.cpp \
    gestion_fournisseurs.cpp \
    gestion_materiaux.cpp \
    main.cpp \
    mainwindow.cpp \
    materiauxmanq.cpp \
    materiauxposs.cpp \
    matmaint.cpp \
    produit.cpp \
    salles.cpp \
    smtp.cpp \
    societes.cpp \
    tache.cpp

HEADERS += \
    arduino.h \
    arduino_alarm.h \
    arduinocarte.h \
    bondescommandes.h \
    carte_ithen.h \
    chantiers.h \
    client.h \
    conges.h \
    connection.h \
    don.h \
    employe.h \
    famille.h \
    first.h \
    fournisseurs.h \
    gestion_chantiers.h \
    gestion_dons.h \
    gestion_employe.h \
    gestion_evenement.h \
    gestion_fournisseurs.h \
    gestion_materiaux.h \
    mainwindow.h \
    materiauxmanq.h \
    materiauxposs.h \
    matmaint.h \
    produit.h \
    salles.h \
    smtp.h \
    societes.h \
    tache.h

FORMS += \
    arduino.ui \
    carte_ithen.ui \
    first.ui \
    gestion_chantiers.ui \
    gestion_dons.ui \
    gestion_employe.ui \
    gestion_evenement.ui \
    gestion_fournisseurs.ui \
    gestion_materiaux.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
