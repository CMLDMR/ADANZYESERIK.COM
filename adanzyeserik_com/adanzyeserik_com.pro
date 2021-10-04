QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp

HEADERS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += C:/boost/boost
DEPENDPATH += C:/boost/boost


win32: LIBS += -LC:/SerikBLDCoreRelease/MSVC2017x64/lib/ -lSerikBLDCore

INCLUDEPATH += C:/SerikBLDCoreRelease/MSVC2017x64/include
DEPENDPATH += C:/SerikBLDCoreRelease/MSVC2017x64/include



win32: LIBS += -LC:/Wt_4.3.1_msvc2017_x64/lib/ -lwt -lwthttp

INCLUDEPATH += C:/Wt_4.3.1_msvc2017_x64/include
DEPENDPATH += C:/Wt_4.3.1_msvc2017_x64/include



INCLUDEPATH += $$PWD/../../../../Comman
DEPENDPATH += $$PWD/../../../../Comman


