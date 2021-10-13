#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H
#include "BaseClass/wtheaders.h"
#include "root/azitem.h"


class ItemWidget : public WContainerWidget,  public UtilityWt
{
public:



    ItemWidget(const AZ::Key::Type _mType);

    void initBasin();
    void initDuyuru();
    void initEtkinlik();
    void initVideo();
    void initPhoto();

    WContainerWidget* mContent;
    WContainerWidget* mTypeContainer;
    void initTypeContainer();

    WContainerWidget* mLikeContainer;
    void initLikeContainer();

    void setIcerikText(const std::string &newIcerikText);

private:
    AZ::Key::Type mType;

    std::string icerikText;
};

#endif // ITEMWIDGET_H
