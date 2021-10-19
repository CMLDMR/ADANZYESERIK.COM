#ifndef ADMINPANEL_H
#define ADMINPANEL_H


#include "BaseClass/containerwiget.h"
#include "root/azitem.h"
#include "widget/itemwidget.h"


class LoginPanel : public WDialog
{
public:
    LoginPanel();


    Signal<bool> &SuccesLogin();

private:
    Signal<bool> _SuccesLogin;
};




class AdminPanel : public ContainerWidget, public AZ::ItemManager
{
public:
    AdminPanel(SerikBLDCore::DB* _mDB);

    void initPanel();

    void addIcerik();

    void addBasin();
    void addEtkinlik();
    void addFoto();
    void addVideo();
    void addDuyuru();

    WContainerWidget* mContainer;

    virtual void onList(const QVector<AZ::Item> *mlist) override;


    virtual void errorOccured(const std::string &errorText) override;

    std::vector<std::string> tempFileOidList;
};

#endif // ADMINPANEL_H
