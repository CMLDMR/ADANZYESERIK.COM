#ifndef FOOTERCONTAINER_H
#define FOOTERCONTAINER_H

#include "BaseClass/wtheaders.h"


class FooterContainer : public WContainerWidget
{
public:
    FooterContainer();

    void initDesktop();


    void addLogo( WHBoxLayout *hLayout,
                  const std::string &backGroundUrl,
                  const std::string &url,
                  const int &width = 100, const int &height = 55);
};

#endif // FOOTERCONTAINER_H
