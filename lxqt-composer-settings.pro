QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui


DISTFILES += \
    resources/lxqt-composer.desktop \
    resources/lxqt-compositor.sh \
    resources/org.ys.lxqt-composer-settings.desktop \
    resources/picom.conf

TARGET = lxqt-composer-settings

isEmpty(PREFIX) {
    PREFIX = /data/data/com.termux/files/usr
  }

        target.path = $${PREFIX}/bin

        service.files = "./resources/lxqt-composer.desktop"
        service.path = $${PREFIX}/etc/xdg/autostart

        desktop.files = "./resources/org.ys.lxqt-composer-settings.desktop"
        desktop.path = $${PREFIX}/share/applications

        picom-conf.files = "./resources/picom.conf"
        picom-conf.path = $${PREFIX}/var/lib/lxqt-compositor

        scripts.files = "./resources/lxqt-compositor.sh"
        scripts.path = $${PREFIX}/var/lib/lxqt-compositor

INSTALLS += target service desktop picom-conf scripts
