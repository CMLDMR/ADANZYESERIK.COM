#include "itemwidget.h"

ItemWidget::ItemWidget(const AZ::Key::Type _mType)
    :mType(_mType)
{
    this->addStyleClass(Bootstrap::Grid::col_full_12);
    setMargin(10,Side::Top|Side::Bottom);
    this->setPositionScheme(PositionScheme::Relative);

    mContent = addWidget(cpp14::make_unique<WContainerWidget>());

    mContent->setWidth(WLength("100%"));

    mContent->addStyleClass("ItemWidget");
    mContent->setOverflow(Overflow::Hidden);
    mContent->setPadding(20,Side::Top);
//    mContent->setPositionScheme(PositionScheme::Absolute);


    this->initTypeContainer();

//    this->initLikeContainer();




//    this->setHeight(mContent->height());

}

void ItemWidget::initBasin()
{
    mContent->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::Azure));
    mContent->setPadding(10,Side::Left|Side::Right|Side::Top);
    mContent->setPadding(25,Side::Bottom);
    auto text = mContent->addWidget(cpp14::make_unique<WText>(icerikText,TextFormat::UnsafeXHTML));
    mContent->setContentAlignment(AlignmentFlag::Justify);
}

void ItemWidget::initDuyuru()
{
    mContent->addWidget(cpp14::make_unique<WText>(icerikText,TextFormat::UnsafeXHTML));
    mContent->setPadding(10,Side::Left|Side::Right|Side::Top);
    mContent->setPadding(25,Side::Bottom);
    mContent->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::GhostWhite));
    mContent->setContentAlignment(AlignmentFlag::Justify);


}

void ItemWidget::initEtkinlik()
{
    mContent->addWidget(cpp14::make_unique<WText>(icerikText,TextFormat::UnsafeXHTML));
    mContent->setPadding(10,Side::Left|Side::Right|Side::Top);
    mContent->setPadding(25,Side::Bottom);
    mContent->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::HoneyDew));
    mContent->setContentAlignment(AlignmentFlag::Justify);


}

void ItemWidget::initVideo()
{
    mContent->setAttributeValue(Style::style,Style::background::url("video.jpg")
                                +Style::background::size::cover
                                +Style::background::position::center_center
                                +Style::background::repeat::norepeat);
    mContent->setHeight(this->getRandom(200,300));

}

void ItemWidget::initPhoto()
{
    mContent->addWidget(cpp14::make_unique<WText>(icerikText,TextFormat::UnsafeXHTML));
    mContent->setPadding(10,Side::Left|Side::Right|Side::Top);
    mContent->setPadding(25,Side::Bottom);
    mContent->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::HoneyDew));
    mContent->setContentAlignment(AlignmentFlag::Justify);


}

void ItemWidget::initTypeContainer()
{
    mTypeContainer = mContent->addWidget(cpp14::make_unique<WContainerWidget>());
    mTypeContainer->setPositionScheme(PositionScheme::Absolute);
    mTypeContainer->setOffsets(0,Side::Top);

    mTypeContainer->setOffsets(0,Side::Left|Side::Right);
    mTypeContainer->addStyleClass("mContenBaslik");

    mTypeContainer->setContentAlignment(AlignmentFlag::Right);
    auto text = mTypeContainer->addWidget(cpp14::make_unique<WText>(""));
    std::string style = Style::color::color(Style::color::White::AliceBlue);
    switch (mType) {
    case AZ::Key::Type::BASINDA:
        text->setText("<b>Basın  </b><i>"+WDate::currentDate().toString("dd/MM/yyyy").toUTF8()+"</i>");
        this->initBasin();

        break;
    case AZ::Key::Type::DUYURU:
        text->setText("<b>Duyuru  </b><i>"+WDate::currentDate().toString("dd/MM/yyyy").toUTF8()+"</i>");
        this->initDuyuru();

        break;

    case AZ::Key::Type::ETKINLIK:
        text->setText("<b>Etkinlik  </b><i>"+WDate::currentDate().toString("dd/MM/yyyy").toUTF8()+"</i>");
        this->initEtkinlik();

        break;

    case AZ::Key::Type::PHOTO:
        text->setText("<b>Fotoğraf  </b><i>"+WDate::currentDate().toString("dd/MM/yyyy").toUTF8()+"</i>");
        this->initPhoto();
        break;

    case AZ::Key::Type::VIDEO:
        text->setText("<b>Video  </b><i>"+WDate::currentDate().toString("dd/MM/yyyy").toUTF8()+"</i>");
        this->initVideo();

        break;
    default:
        break;
    }

    mTypeContainer->setAttributeValue(Style::style,style);
}

void ItemWidget::initLikeContainer()
{
    if( mType != AZ::Key::Type::DUYURU){
        auto mLikeContainer = mContent->addWidget(cpp14::make_unique<WContainerWidget>());
        mLikeContainer->setPositionScheme(PositionScheme::Absolute);
        mLikeContainer->setOffsets(0,Side::Bottom|Side::Left|Side::Right);
        mLikeContainer->setHeight(60);
        mLikeContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::GhostWhite));

        {
            auto likeBtn = mLikeContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            likeBtn->setPositionScheme(PositionScheme::Absolute);
            likeBtn->setOffsets(15,Side::Top);
            likeBtn->setOffsets(10,Side::Left);

            likeBtn->setAttributeValue(Style::style,Style::background::url("logo/like.jpg")
                                       +Style::background::size::contain
                                       +Style::background::repeat::norepeat
                                       +Style::background::position::center_center);
            likeBtn->setWidth(30);
            likeBtn->setHeight(30);
            auto text = likeBtn->addWidget(cpp14::make_unique<WText>("<b><span style=\"color:gray;padding:2px;\">"+std::to_string(this->getRandom(5,50))+"</span></b>",TextFormat::UnsafeXHTML));
            text->setPadding(3,AllSides);
            text->setPositionScheme(PositionScheme::Absolute);
            text->setOffsets(-20,Side::Top);
        }

        {
            auto likeBtn = mLikeContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            likeBtn->setPositionScheme(PositionScheme::Absolute);
            likeBtn->setOffsets(15,Side::Top);
            likeBtn->setOffsets(10+45,Side::Left);

            likeBtn->setAttributeValue(Style::style,Style::background::url("logo/love.jpg")
                                       +Style::background::size::contain
                                       +Style::background::repeat::norepeat
                                       +Style::background::position::center_center);
            likeBtn->setWidth(30);
            likeBtn->setHeight(30);
            auto text = likeBtn->addWidget(cpp14::make_unique<WText>("<b><span style=\"color:gray;padding:2px;\">"+std::to_string(this->getRandom(5,50))+"</span></b>",TextFormat::UnsafeXHTML));
            text->setPadding(3,AllSides);
            text->setPositionScheme(PositionScheme::Absolute);
            text->setOffsets(-20,Side::Top);
        }

        {
            auto likeBtn = mLikeContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            likeBtn->setPositionScheme(PositionScheme::Absolute);
            likeBtn->setOffsets(15,Side::Top);
            likeBtn->setOffsets(10+45+45,Side::Left);

            likeBtn->setAttributeValue(Style::style,Style::background::url("logo/deny.jpg")
                                       +Style::background::size::contain
                                       +Style::background::repeat::norepeat
                                       +Style::background::position::center_center);
            likeBtn->setWidth(30);
            likeBtn->setHeight(30);
            auto text = likeBtn->addWidget(cpp14::make_unique<WText>("<b><span style=\"color:gray;padding:2px;\">"+std::to_string(this->getRandom(5,50))+"</span></b>",TextFormat::UnsafeXHTML));
            text->setPadding(3,AllSides);
            text->setPositionScheme(PositionScheme::Absolute);
            text->setOffsets(-20,Side::Top);
        }

    }
}

void ItemWidget::setIcerikText(const std::string &newIcerikText)
{
    icerikText = newIcerikText;
    this->initTypeContainer();
}
