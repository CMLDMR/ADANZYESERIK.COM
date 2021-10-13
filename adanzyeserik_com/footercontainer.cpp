#include "footercontainer.h"

FooterContainer::FooterContainer()
{
   this->initDesktop();
}

void FooterContainer::initDesktop()
{

    this->addStyleClass(Bootstrap::Grid::Hidden::hidden_xs);
    this->setPositionScheme(PositionScheme::Fixed);
    this->setOffsets(0,Side::Bottom);

    this->setMargin(15,Side::Top);
    this->addStyleClass(Bootstrap::Grid::col_full_12);
    this->setContentAlignment(AlignmentFlag::Center);

    auto container = this->addWidget(cpp14::make_unique<WContainerWidget>());
    container->setPositionScheme(PositionScheme::Relative);
    container->setMaximumSize(1280,WLength::Auto);
    container->setOverflow(Overflow::Hidden);
    container->setHeight(75);
    container->setPadding(10,AllSides);

    auto logoContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
    logoContainer->addStyleClass("footer");
    logoContainer->setOverflow(Overflow::Hidden);

    auto altContainer = logoContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    altContainer->setPositionScheme(PositionScheme::Absolute);
    altContainer->setOffsets(0,Side::Top|Side::Left);
    altContainer->setWidth(WLength("100%"));
    altContainer->setHeight(WLength("50%"));
    altContainer->setPadding(0,AllSides);
    altContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::White));

    auto hLayout = altContainer->setLayout(cpp14::make_unique<WHBoxLayout>());

    hLayout->addStretch(1);

    this->addLogo(hLayout,"logo/kaymakamlik.jpg","http://www.serik.gov.tr/",200);
    this->addLogo(hLayout,"logo/serik.jpg","http://www.serik.bel.tr");
    this->addLogo(hLayout,"logo/milliegitim.jpg","http://serik.meb.gov.tr/");
    this->addLogo(hLayout,"logo/deniztepesi.jpg","https://serikdeniztepesiilkokulu.meb.k12.tr/");
    this->addLogo(hLayout,"logo/asagikocayatak.jpg","https://asagikocayatakilkokulu.meb.k12.tr/tema/index.php");
    this->addLogo(hLayout,"logo/tekeli.jpg","https://seriktekeliortaokulu.meb.k12.tr/");
    this->addLogo(hLayout,"logo/karadayi.jpg","https://serikkaradayiio.meb.k12.tr/07/13/702914/okulumuz_hakkinda.html");
    this->addLogo(hLayout,"logo/twinning.jpg","https://www.etwinning.net/tr/pub/index.htm");

    hLayout->addStretch(1);


}

void FooterContainer::addLogo(WHBoxLayout *hLayout, const std::string &backGroundUrl, const std::string &url, const int &width, const int &height)
{
    auto container = hLayout->addWidget(cpp14::make_unique<WContainerWidget>());
    container->setHeight(height);
    container->setWidth(width);
    container->setAttributeValue(Style::style,Style::background::url(backGroundUrl)
                                 +Style::background::size::contain
                                 +Style::background::repeat::norepeat
                                 +Style::background::position::center_center);
    if( url.size() ){
        container->clicked().connect([=](){
            container->doJavaScript("window.open('"+url+"', '_blank');");
        });
        container->decorationStyle().setCursor(Cursor::PointingHand);
    }

}


