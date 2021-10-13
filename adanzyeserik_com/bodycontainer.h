#ifndef BODYCONTAINER_H
#define BODYCONTAINER_H

#include "BaseClass/wtheaders.h"

class BodyContainer : public WContainerWidget, public UtilityWt
{
public:
    BodyContainer();

    void loadLastAkis(WContainerWidget* mAkisContainer);


    WContainerWidget* mMainContainer;


    // Geçici Olarak Yapılıyor Silinecek
    void loadAkis();


    void initHakkinda();
    void initIletisim();

};

#endif // BODYCONTAINER_H
