#ifndef BODYCONTAINER_H
#define BODYCONTAINER_H

#include "BaseClass/wtheaders.h"
#include "widget/itemwidget.h"

class BodyContainer : public WContainerWidget, public UtilityWt
{
public:
    BodyContainer(SerikBLDCore::DB* mDB);
    ~BodyContainer();


    void initBody();


    void initHakkinda();
    void initIletisim();



    void setType(AZ::Key::Type newType);

private:
    AZ::ItemManager* mItemManager;

    void loadLastAkis(WContainerWidget* mAkisContainer);
    void loadAkis();


    WContainerWidget* mMainContainer;

    std::int64_t mLimit = 20;
    std::int64_t mSkip = 0;
    std::int64_t mCount;

    AZ::Key::Type mType = AZ::Key::Type::NOP;

};

#endif // BODYCONTAINER_H
