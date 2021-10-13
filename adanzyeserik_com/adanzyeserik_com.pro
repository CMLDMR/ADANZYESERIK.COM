QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += c++17 console
CONFIG -= app_bundle
CONFIG += no_keywords


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BaseClass/containerwiget.cpp \
    bodycontainer.cpp \
    footercontainer.cpp \
    headercontainer.cpp \
    main.cpp \
    mainapplication.cpp \
    mainpage.cpp \
    root/azitem.cpp \
    user/adminpanel.cpp \
    widget/itemwidget.cpp

HEADERS += \
    BaseClass/containerwiget.h \
    Response.h \
    bodycontainer.h \
    footercontainer.h \
    headercontainer.h \
    mainapplication.h \
    mainpage.h \
    root/azitem.h \
    user/adminpanel.h \
    widget/itemwidget.h

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




win32: LIBS += -LC:/Mongo/msvc2017x64/lib/ -lbsoncxx

INCLUDEPATH += C:/Mongo/msvc2017x64/include/bsoncxx/v_noabi
DEPENDPATH += C:/Mongo/msvc2017x64/include/bsoncxx/v_noabi



win32: LIBS += -LC:/Mongo/msvc2017x64/lib/ -lmongocxx

INCLUDEPATH += C:/Mongo/msvc2017x64/include/mongocxx/v_noabi
DEPENDPATH += C:/Mongo/msvc2017x64/include/mongocxx/v_noabi

DISTFILES += \
    ../build-adanzyeserik_com-Desktop_Qt_5_13_2_MSVC2017_64bit-Release/docroot/css.css
