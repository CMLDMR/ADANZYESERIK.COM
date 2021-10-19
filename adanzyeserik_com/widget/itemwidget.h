#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H
#include "BaseClass/wtheaders.h"
#include "root/azitem.h"


class ItemWidget : public WContainerWidget, public AZ::Item,  public UtilityWt
{
public:



    ItemWidget(const AZ::Item &other = AZ::Item(),const std::vector<std::string> &fileList = std::vector<std::string>());

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

    void setMfileList(const std::vector<std::string> &newMfileList);

    void setPublic(bool newPublic);


    Signal<std::string> &deleteReq();
    const std::vector<std::string> &getMfileList() const;

private:
//    AZ::Key::Type mType;

    std::vector<std::string> mfileList;

    bool mPublic = true;

    Signal<std::string> _deleteReq;

};

#endif // ITEMWIDGET_H
