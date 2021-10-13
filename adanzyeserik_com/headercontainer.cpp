#include "headercontainer.h"

HeaderContainer::HeaderContainer()
{

    this->setPositionScheme(PositionScheme::Fixed);
    this->setOffsets(0,Side::Top|Side::Right|Side::Left);
    this->setZIndex(1000);
    this->setContentAlignment(AlignmentFlag::Center);

    this->addStyleClass("header");

    this->initDesktop();
    this->initMobile();

}

void HeaderContainer::initDesktop()
{
    mSeritContainer = this->addWidget(cpp14::make_unique<WContainerWidget>());

    mSeritContainer->setMaximumSize(1280,WLength::Auto);

    mSeritContainer->setHeight(60);

    mSeritContainer->setPositionScheme(PositionScheme::Relative);
    mSeritContainer->addStyleClass(Bootstrap::Grid::Hidden::hidden_xs);

    mSeritContainer->addWidget(cpp14::make_unique<LogoContainer>());

    {
        auto container = wApp->root()->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setPositionScheme(PositionScheme::Fixed);
        container->setOffsets(150,Side::Top);
        container->setOffsets(0,Side::Right);
        container->setWidth(150);
        container->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(200,255),this->getRandom(200,255),this->getRandom(200,255))
                                     +Style::Border::borderRardius("15","0","15","0"));
        container->decorationStyle().setCursor(Cursor::PointingHand);

        container->setContentAlignment(AlignmentFlag::Center);
        container->setPadding(25,Side::Top|Side::Bottom);

        auto colorContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
        colorContainer->setPositionScheme(PositionScheme::Absolute);
        colorContainer->setWidth(WLength("100%"));
        colorContainer->setHeight(WLength("100%"));
        colorContainer->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(),this->getRandom(),this->getRandom()));
        colorContainer->setAttributeValue(Style::style,Style::background::url("serikokuyor.png")
                                     +Style::color::color(Style::color::White::AliceBlue)
                                     +Style::background::size::contain
                                     +Style::background::repeat::norepeat
                                     +Style::background::position::center_center);
        colorContainer->setOffsets(0,Side::Top);

        colorContainer->clicked().connect([=](){
           this->doJavaScript("window.open('http://www.serikokuyor.com','_blank');");
        });
    }

    {
        auto container = wApp->root()->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setPositionScheme(PositionScheme::Fixed);
        container->setOffsets(205,Side::Top);
        container->setOffsets(0,Side::Right);
        container->setWidth(150);
        container->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(200,255),this->getRandom(200,255),this->getRandom(200,255))
                                     +Style::Border::borderRardius("15","0","15","0"));
        container->decorationStyle().setCursor(Cursor::PointingHand);
        container->setOverflow(Overflow::Hidden);

        container->setContentAlignment(AlignmentFlag::Center);
        container->setPadding(25,Side::Top|Side::Bottom);

        auto colorContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
        colorContainer->setPositionScheme(PositionScheme::Absolute);
        colorContainer->setWidth(WLength("100%"));
        colorContainer->setHeight(WLength("100%"));
        colorContainer->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(),this->getRandom(),this->getRandom()));
        colorContainer->setAttributeValue(Style::style,Style::background::url("facebook.jpg")
                                     +Style::color::color(Style::color::White::AliceBlue)
                                     +Style::background::size::cover
                                     +Style::background::repeat::norepeat
                                     +Style::background::position::center_center);
        colorContainer->setOffsets(0,Side::Top);

        colorContainer->clicked().connect([=](){
           this->doJavaScript("window.open('https://www.facebook.com/profile.php?id=100073145300624','_blank');");
        });
    }

    {
        auto container = wApp->root()->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setPositionScheme(PositionScheme::Fixed);
        container->setOffsets(260,Side::Top);
        container->setOffsets(0,Side::Right);
        container->setWidth(150);
        container->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(200,255),this->getRandom(200,255),this->getRandom(200,255))
                                     +Style::Border::borderRardius("15","0","15","0"));
        container->decorationStyle().setCursor(Cursor::PointingHand);
        container->setOverflow(Overflow::Hidden);

        container->setContentAlignment(AlignmentFlag::Center);
        container->setPadding(25,Side::Top|Side::Bottom);

        auto colorContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
        colorContainer->setPositionScheme(PositionScheme::Absolute);
        colorContainer->setWidth(WLength("100%"));
        colorContainer->setHeight(WLength("100%"));
        colorContainer->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(),this->getRandom(),this->getRandom()));
        colorContainer->setAttributeValue(Style::style,Style::background::url("twitter.jpg")
                                     +Style::color::color(Style::color::White::AliceBlue)
                                     +Style::background::size::cover
                                     +Style::background::repeat::norepeat
                                     +Style::background::position::center_center);
        colorContainer->setOffsets(0,Side::Top);

        colorContainer->clicked().connect([=](){
           this->doJavaScript("window.open('https://twitter.com/adanzyeserik','_blank');");
        });
    }

    {
        auto container = wApp->root()->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setPositionScheme(PositionScheme::Fixed);
        container->setOffsets(315,Side::Top);
        container->setOffsets(0,Side::Right);
        container->setWidth(150);
        container->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(200,255),this->getRandom(200,255),this->getRandom(200,255))
                                     +Style::Border::borderRardius("15","0","15","0"));
        container->decorationStyle().setCursor(Cursor::PointingHand);
        container->setOverflow(Overflow::Hidden);

        container->setContentAlignment(AlignmentFlag::Center);
        container->setPadding(25,Side::Top|Side::Bottom);

        auto colorContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
        colorContainer->setPositionScheme(PositionScheme::Absolute);
        colorContainer->setWidth(WLength("100%"));
        colorContainer->setHeight(WLength("100%"));
        colorContainer->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(),this->getRandom(),this->getRandom()));
        colorContainer->setAttributeValue(Style::style,Style::background::url("instagram.jpg")
                                     +Style::color::color(Style::color::White::AliceBlue)
                                     +Style::background::size::cover
                                     +Style::background::repeat::norepeat
                                     +Style::background::position::center_center);
        colorContainer->setOffsets(0,Side::Top);

        colorContainer->clicked().connect([=](){
           this->doJavaScript("window.open('https://www.instagram.com/adanzyeserik/','_blank');");
        });
    }




    mMenuContainer = mSeritContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    mMenuContainer->setPositionScheme(PositionScheme::Absolute);
    mMenuContainer->setOffsets(0,Side::Top|Side::Right|Side::Bottom);
    mMenuContainer->setOffsets(150,Side::Left);

    {
        auto hLayout = mMenuContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
        hLayout->addSpacing(50);
        auto etkinlikMenu = hLayout->addWidget(cpp14::make_unique<WText>("<p><span style=\"font-size:20px;font-weight:bold;\">E</span>TKİNLİKLER</p>"));
        etkinlikMenu->setMinimumSize(100,WLength::Auto);
        etkinlikMenu->addStyleClass("menuItem-btn-grad");
        etkinlikMenu->clicked().connect([=](){
            auto mDialog = wApp->instance()->root()->addChild (cpp14::make_unique<WDialog>());


            mDialog->titleBar ()->addWidget (cpp14::make_unique<WText>("<h3><b>! Uyarı</b></h3>"));
            mDialog->titleBar ()->addStyleClass (Bootstrap::ContextualBackGround::bg_warning);


            mDialog->contents ()->addWidget (cpp14::make_unique<WText>("Yapım Aşamasında"));
            mDialog->contents ()->addStyleClass (Bootstrap::ContextualBackGround::bg_info);

            auto closeBtn = mDialog->footer ()->addWidget (cpp14::make_unique<WPushButton>("Tamam"));
            closeBtn->addStyleClass (Bootstrap::Button::Warning);

            closeBtn->clicked ().connect ([=](){
                wApp->instance()->root()->removeChild(mDialog);
            });
            mDialog->show ();
        });

        auto galeriText = hLayout->addWidget(cpp14::make_unique<WText>("<p><span style=\"font-size:20px;font-weight:bold;\">G</span>ALERİ</p>"));
        galeriText->setMinimumSize(100,WLength::Auto);
        galeriText->addStyleClass("menuItem-btn-grad");
        galeriText->clicked().connect([=](){
            auto mDialog = wApp->instance()->root()->addChild (cpp14::make_unique<WDialog>());


            mDialog->titleBar ()->addWidget (cpp14::make_unique<WText>("<h3><b>! Uyarı</b></h3>"));
            mDialog->titleBar ()->addStyleClass (Bootstrap::ContextualBackGround::bg_warning);


            mDialog->contents ()->addWidget (cpp14::make_unique<WText>("Yapım Aşamasında"));
            mDialog->contents ()->addStyleClass (Bootstrap::ContextualBackGround::bg_info);

            auto closeBtn = mDialog->footer ()->addWidget (cpp14::make_unique<WPushButton>("Tamam"));
            closeBtn->addStyleClass (Bootstrap::Button::Warning);

            closeBtn->clicked ().connect ([=](){
                wApp->instance()->root()->removeChild(mDialog);
            });
            mDialog->show ();
        });

        auto basindaText = hLayout->addWidget(cpp14::make_unique<WText>("<p><span style=\"font-size:20px;font-weight:bold;\">B</span>ASINDA</p>"));
        basindaText->setMinimumSize(100,WLength::Auto);
        basindaText->addStyleClass("menuItem-btn-grad");
        basindaText->clicked().connect([=](){
            auto mDialog = wApp->instance()->root()->addChild (cpp14::make_unique<WDialog>());


            mDialog->titleBar ()->addWidget (cpp14::make_unique<WText>("<h3><b>! Uyarı</b></h3>"));
            mDialog->titleBar ()->addStyleClass (Bootstrap::ContextualBackGround::bg_warning);


            mDialog->contents ()->addWidget (cpp14::make_unique<WText>("Yapım Aşamasında"));
            mDialog->contents ()->addStyleClass (Bootstrap::ContextualBackGround::bg_info);

            auto closeBtn = mDialog->footer ()->addWidget (cpp14::make_unique<WPushButton>("Tamam"));
            closeBtn->addStyleClass (Bootstrap::Button::Warning);

            closeBtn->clicked ().connect ([=](){
                wApp->instance()->root()->removeChild(mDialog);
            });
            mDialog->show ();
        });


        auto duyuruText = hLayout->addWidget(cpp14::make_unique<WText>("<p><span style=\"font-size:20px;font-weight:bold;\">D</span>UYURULAR</p>"));
        duyuruText->setMinimumSize(100,WLength::Auto);
        duyuruText->addStyleClass("menuItem-btn-grad");
        duyuruText->clicked().connect([=](){
            auto mDialog = wApp->instance()->root()->addChild (cpp14::make_unique<WDialog>());


            mDialog->titleBar ()->addWidget (cpp14::make_unique<WText>("<h3><b>! Uyarı</b></h3>"));
            mDialog->titleBar ()->addStyleClass (Bootstrap::ContextualBackGround::bg_warning);


            mDialog->contents ()->addWidget (cpp14::make_unique<WText>("Yapım Aşamasında"));
            mDialog->contents ()->addStyleClass (Bootstrap::ContextualBackGround::bg_info);

            auto closeBtn = mDialog->footer ()->addWidget (cpp14::make_unique<WPushButton>("Tamam"));
            closeBtn->addStyleClass (Bootstrap::Button::Warning);

            closeBtn->clicked ().connect ([=](){
                wApp->instance()->root()->removeChild(mDialog);
            });
            mDialog->show ();
        });


        hLayout->addStretch(1);

        auto hakkimizdaText = hLayout->addWidget(cpp14::make_unique<WText>("<p><span style=\"font-size:20px;font-weight:bold;\">H</span>AKKIMIZDA</p>"));
        hakkimizdaText->setMinimumSize(100,WLength::Auto);
        hakkimizdaText->addStyleClass("menuItem-btn-grad");
        hakkimizdaText->clicked().connect([=](){
           _mHakkindaClicked.emit(NoClass());
        });

        auto iletisimText = hLayout->addWidget(cpp14::make_unique<WText>("<p><span style=\"font-size:20px;font-weight:bold;\"></span>444 9 722</p>"));
        iletisimText->setMinimumSize(100,WLength::Auto);
        iletisimText->addStyleClass("menuItem-btn-grad");

    }

}

void HeaderContainer::initMobile()
{
    mSeritContainer = this->addWidget(cpp14::make_unique<WContainerWidget>());

    mSeritContainer->setMaximumSize(1280,WLength::Auto);

//    mSeritContainer->setHeight(50);

    mSeritContainer->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(),this->getRandom(),this->getRandom()));

    mSeritContainer->setPositionScheme(PositionScheme::Relative);

    mSeritContainer->addStyleClass(Bootstrap::Grid::Hidden::hidden_lg+
                                   Bootstrap::Grid::Hidden::hidden_md+
                                   Bootstrap::Grid::Hidden::hidden_sm);

//    mSeritContainer->addWidget(cpp14::make_unique<LogoContainer>());


    mSeritContainer->addWidget(cpp14::make_unique<WText>("<h3 style=\"color:white;\">Mobile Version Yapım Aşamasında</h3>"));

}

Signal<NoClass> &HeaderContainer::HakkindaClicked()
{
    return _mHakkindaClicked;
}

Signal<NoClass> &HeaderContainer::MainPageClicked()
{
    return _mMainPageClicked;
}

LogoContainer::LogoContainer()
{

    auto logo = this->addWidget(cpp14::make_unique<WContainerWidget>());
    logo->setWidth(WLength(150));
    logo->setHeight(WLength(150));
    logo->setPositionScheme(PositionScheme::Absolute);
    logo->setZIndex(101);
    logo->setOffsets(0,Side::Right|Side::Top);

    logo->setAttributeValue(Style::style,Style::background::url("logo.png")+Style::background::size::contain
                            +Style::background::position::center_center
                            +Style::background::repeat::norepeat);

    this->setPositionScheme(PositionScheme::Absolute);
    this->setOffsets(0,Side::Top|Side::Left);
    this->setWidth(150);
    this->setHeight(150);
    this->setZIndex(100);
//    this->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(),this->getRandom(),this->getRandom()));



}
