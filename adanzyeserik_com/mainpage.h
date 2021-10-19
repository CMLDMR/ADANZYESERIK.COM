#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "BaseClass/containerwiget.h"

#include "headercontainer.h"
#include "bodycontainer.h"
#include "footercontainer.h"

class MainPage : public ContainerWidget
{
public:
    MainPage(SerikBLDCore::DB* _mDB);


    void initPage();

private:
    SerikBLDCore::DB *mDB;
};

#endif // MAINPAGE_H
