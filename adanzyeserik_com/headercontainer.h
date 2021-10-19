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
    Signal<NoClass> &EtkinlikClicked();
    Signal<NoClass> &GaleriClicked();
    Signal<NoClass> &BasinClicked();
    Signal<NoClass> &DuyuruClicked();
private:
    WContainerWidget* mSeritContainer;
    WContainerWidget* mMenuContainer;


    Signal<NoClass> _mMainPageClicked;
    Signal<NoClass> _mHakkindaClicked;
    Signal<NoClass> _mEtkinlikClicked;
    Signal<NoClass> _mGaleriClicked;
    Signal<NoClass> _mBasinClicked;
    Signal<NoClass> _mDuyuruClicked;
};







class LogoContainer : public WContainerWidget, public UtilityWt
{
public:
    LogoContainer(const int &width = 150 , const int &height = 150 );
};

class MobileMenu : public WContainerWidget, public UtilityWt
{
public:
    MobileMenu();

    void init();
    void initSocialMedia();
    void initController();

    void setVisible(bool visible = false );

    bool visible() const;

private:
    bool mVisible = false;

    WText *mText;

    WContainerWidget* mrContainer;


};

#endif // HEADERCONTAINER_H
