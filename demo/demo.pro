QT       += core gui
QT       += svg
QT       += testlib
QT       += printsupport
QT       +=sql
QT       +=xml
QT       +=network
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
    main.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(page01/page01.pri)
include(page02/page02.pri)
include(page03/page03.pri)
include(page04/page04.pri)
include(page05/page05.pri)
include(page06/page06.pri)
include(page07/page07.pri)
include(page08/page08.pri)
include(page09/page09.pri)
include(page10/page10.pri)
include(page11/page11.pri)
include(page12/page12.pri)
include(page13/page13.pri)
include(page14/page14.pri)
include(page15/page15.pri)
RESOURCES += \
    resource.qrc

TRANSLATIONS=$$PWD/res/langFile/MultiLangWidget.ts \
            $$PWD/res/langFile/lang_en.ts \
            $$PWD/res/langFile/lang_zh.ts \
            $$PWD/res/langFile/lang_la.ts \
