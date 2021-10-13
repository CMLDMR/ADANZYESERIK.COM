#ifndef HEADERCONTAINER_H
#define HEADERCONTAINER_H

#include "BaseClass/wtheaders.h"


class HeaderContainer : public WContainerWidget, public UtilityWt
{
public:
    HeaderContainer();

    void initDesktop();
    void initMobile();


    Signal<NoClass> &HakkindaClicked();
    Signal<NoClass> &MainPageClicked();
private:
    WContainerWidget* mSeritContainer;
    WContainerWidget* mMenuContainer;


    Signal<NoClass> _mMainPageClicked;
    Signal<NoClass> _mHakkindaClicked;
};







class LogoContainer : public WContainerWidget, public UtilityWt
{
public:
    LogoContainer();



};

#endif // HEADERCONTAINER_H
