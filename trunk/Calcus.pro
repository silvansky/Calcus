#-------------------------------------------------
#
# Project created by QtCreator 2010-11-12T13:04:20
#
#-------------------------------------------------

QT       += core gui script

TARGET = Calcus
TEMPLATE = app


SOURCES += main.cpp\
	calcusdlg.cpp \
    autosizetextedit.cpp \
    logoutput.cpp

HEADERS  += calcusdlg.h \
    mathwrappers.h \
    autosizetextedit.h \
    logoutput.h

FORMS    += calcusdlg.ui

RESOURCES += \
    icons.qrc

win32: {
    RC_FILE = calcus.rc
}

macx: {
    ICON = Calcus.icns
}

OTHER_FILES += \
    calcus.rc
