#include "itemwidget.h"

ItemWidget::ItemWidget(const Item &other, const std::vector<std::string> &fileList)
{
    this->setMfileList(fileList);
    this->setDocumentView(other.view());
//    mType = this->getType();
    this->addStyleClass(Bootstrap::Grid::col_full_12);
    setMargin(10,Side::Top|Side::Bottom);
    this->setPositionScheme(PositionScheme::Relative);

    mContent = addWidget(cpp14::make_unique<WContainerWidget>());

    mContent->setWidth(WLength("100%"));

    mContent->addStyleClass("ItemWidget");
    mContent->setOverflow(Overflow::Hidden);
    mContent->setPadding(50,Side::Top);
//    mContent->setPositionScheme(PositionScheme::Absolute);
    mContent->setPadding(10,Side::Left|Side::Right);
    mContent->setPadding(25,Side::Bottom);

    this->initTypeContainer();

//    this->initLikeContainer();




//    this->setHeight(mContent->height());

}

void ItemWidget::initBasin()
{
    mContent->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::Azure));
    auto text = mContent->addWidget(cpp14::make_unique<WText>(this->getContent(),TextFormat::UnsafeXHTML));
    mContent->setContentAlignment(AlignmentFlag::Justify);


    auto rContainer = mContent->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);
    rContainer->setMargin(25,Side::Top);
    for( const auto &fileLink : mfileList ){

        auto hContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        hContainer->addStyleClass(Bootstrap::Grid::Medium::col_md_3+
                                 Bootstrap::Grid::Large::col_lg_3+
                                 Bootstrap::Grid::Small::col_sm_4+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);

        auto container = hContainer->addWidget(cpp14::make_unique<WContainerWidget>());
//        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setHeight(100);
        container->setAttributeValue(Style::style,Style::background::url(fileLink)+
                                     Style::background::position::center_center+
                                     Style::background::size::cover+
                                     Style::background::repeat::norepeat);

        container->clicked().connect([=](){

            auto _container_ = wApp->root()->addWidget(cpp14::make_unique<WContainerWidget>());
            _container_->setAttributeValue(Style::style,Style::background::color::rgba(0,0,0));
            _container_->setPositionScheme(PositionScheme::Fixed);
            _container_->setOffsets(0,AllSides);

            auto _container = _container_->addWidget(cpp14::make_unique<WContainerWidget>());

            _container->setPositionScheme(PositionScheme::Fixed);
            _container->setOffsets(0,AllSides);
            _container->setAttributeValue(Style::style,Style::background::url(fileLink)+
                                         Style::background::position::center_center+
                                         Style::background::size::contain+
                                         Style::background::repeat::norepeat);
            _container->setZIndex(1000);

            _container->clicked().connect([=](){
                wApp->root()->removeWidget(_container_);
            });


        });
    }
}

void ItemWidget::initDuyuru()
{
    mContent->addWidget(cpp14::make_unique<WText>(this->getContent(),TextFormat::UnsafeXHTML));
    mContent->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::GhostWhite));
    mContent->setContentAlignment(AlignmentFlag::Justify);

    auto rContainer = mContent->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);
    rContainer->setMargin(25,Side::Top);
    for( const auto &fileLink : mfileList ){

        auto hContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        hContainer->addStyleClass(Bootstrap::Grid::Medium::col_md_3+
                                 Bootstrap::Grid::Large::col_lg_3+
                                 Bootstrap::Grid::Small::col_sm_4+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);

        auto container = hContainer->addWidget(cpp14::make_unique<WContainerWidget>());
//        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setHeight(100);
        container->setAttributeValue(Style::style,Style::background::url(fileLink)+
                                     Style::background::position::center_center+
                                     Style::background::size::cover+
                                     Style::background::repeat::norepeat);

        container->clicked().connect([=](){

            auto _container_ = wApp->root()->addWidget(cpp14::make_unique<WContainerWidget>());
            _container_->setAttributeValue(Style::style,Style::background::color::rgba(0,0,0));
            _container_->setPositionScheme(PositionScheme::Fixed);
            _container_->setOffsets(0,AllSides);

            auto _container = _container_->addWidget(cpp14::make_unique<WContainerWidget>());

            _container->setPositionScheme(PositionScheme::Fixed);
            _container->setOffsets(0,AllSides);
            _container->setAttributeValue(Style::style,Style::background::url(fileLink)+
                                         Style::background::position::center_center+
                                         Style::background::size::contain+
                                         Style::background::repeat::norepeat);
            _container->setZIndex(1000);

            _container->clicked().connect([=](){
                wApp->root()->removeWidget(_container_);
            });


        });
    }
}

void ItemWidget::initEtkinlik()
{
    mContent->addWidget(cpp14::make_unique<WText>(this->getContent(),TextFormat::UnsafeXHTML));
    mContent->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::HoneyDew));
    mContent->setContentAlignment(AlignmentFlag::Justify);
    auto rContainer = mContent->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);
    rContainer->setMargin(25,Side::Top);
    for( const auto &fileLink : mfileList ){

        auto hContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        hContainer->addStyleClass(Bootstrap::Grid::Medium::col_md_3+
                                 Bootstrap::Grid::Large::col_lg_3+
                                 Bootstrap::Grid::Small::col_sm_4+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);

        auto container = hContainer->addWidget(cpp14::make_unique<WContainerWidget>());
//        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setHeight(100);
        container->setAttributeValue(Style::style,Style::background::url(fileLink)+
                                     Style::background::position::center_center+
                                     Style::background::size::cover+
                                     Style::background::repeat::norepeat);

        container->clicked().connect([=](){

            auto _container_ = wApp->root()->addWidget(cpp14::make_unique<WContainerWidget>());
            _container_->setAttributeValue(Style::style,Style::background::color::rgba(0,0,0));
            _container_->setPositionScheme(PositionScheme::Fixed);
            _container_->setOffsets(0,AllSides);

            auto _container = _container_->addWidget(cpp14::make_unique<WContainerWidget>());

            _container->setPositionScheme(PositionScheme::Fixed);
            _container->setOffsets(0,AllSides);
            _container->setAttributeValue(Style::style,Style::background::url(fileLink)+
                                         Style::background::position::center_center+
                                         Style::background::size::contain+
                                         Style::background::repeat::norepeat);
            _container->setZIndex(1000);

            _container->clicked().connect([=](){
                wApp->root()->removeWidget(_container_);
            });


        });
    }

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
    mContent->addWidget(cpp14::make_unique<WText>(this->getContent(),TextFormat::UnsafeXHTML));

    mContent->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::HoneyDew));
    mContent->setContentAlignment(AlignmentFlag::Justify);
    auto rContainer = mContent->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);
    rContainer->setMargin(25,Side::Top);
    for( const auto &fileLink : mfileList ){

        auto hContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        hContainer->addStyleClass(Bootstrap::Grid::Medium::col_md_3+
                                 Bootstrap::Grid::Large::col_lg_3+
                                 Bootstrap::Grid::Small::col_sm_4+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);

        auto container = hContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setHeight(100);
        container->setAttributeValue(Style::style,Style::background::url(fileLink)+
                                     Style::background::position::center_center+
                                     Style::background::size::cover+
                                     Style::background::repeat::norepeat);

        container->clicked().connect([=](){

            auto _container_ = wApp->root()->addWidget(cpp14::make_unique<WContainerWidget>());
            _container_->setAttributeValue(Style::style,Style::background::color::rgba(0,0,0));
            _container_->setPositionScheme(PositionScheme::Fixed);
            _container_->setOffsets(0,AllSides);

            auto _container = _container_->addWidget(cpp14::make_unique<WContainerWidget>());

            _container->setPositionScheme(PositionScheme::Fixed);
            _container->setOffsets(0,AllSides);
            _container->setAttributeValue(Style::style,Style::background::url(fileLink)+
                                         Style::background::position::center_center+
                                         Style::background::size::contain+
                                         Style::background::repeat::norepeat);
            _container->setZIndex(1000);

            _container->clicked().connect([=](){
                wApp->root()->removeWidget(_container_);
            });


        });
    }

}

void ItemWidget::initTypeContainer()
{
    mTypeContainer = mContent->addWidget(cpp14::make_unique<WContainerWidget>());
    mTypeContainer->setPositionScheme(PositionScheme::Absolute);
    mTypeContainer->setOffsets(0,Side::Top);

    mTypeContainer->setOffsets(0,Side::Left|Side::Right);

    mTypeContainer->setContentAlignment(AlignmentFlag::Right);
    auto text = mTypeContainer->addWidget(cpp14::make_unique<WText>(""));
    std::string style = Style::color::color(Style::color::White::AliceBlue);
    switch (this->getType()) {
    case AZ::Key::Type::BASINDA:
        text->setText("<b>Basın  </b><i>"+WDate::currentDate().toString("dd/MM/yyyy").toUTF8()+"</i>");
        mTypeContainer->addStyleClass("mContenBaslikBasin");
        this->initBasin();

        break;
    case AZ::Key::Type::DUYURU:
        text->setText("<b>Duyuru  </b><i>"+WDate::currentDate().toString("dd/MM/yyyy").toUTF8()+"</i>");
        mTypeContainer->addStyleClass("mContenBaslikDuyuru");
        this->initDuyuru();

        break;

    case AZ::Key::Type::ETKINLIK:
        text->setText("<b>Etkinlik  </b><i>"+WDate::currentDate().toString("dd/MM/yyyy").toUTF8()+"</i>");
        mTypeContainer->addStyleClass("mContenBaslikEtkinlik");
        this->initEtkinlik();

        break;

    case AZ::Key::Type::PHOTO:
        text->setText("<b>Fotoğraf  </b><i>"+WDate::currentDate().toString("dd/MM/yyyy").toUTF8()+"</i>");
        mTypeContainer->addStyleClass("mContenBaslikFotoVideo");
        this->initPhoto();
        break;

    case AZ::Key::Type::VIDEO:
        text->setText("<b>Video  </b><i>"+WDate::currentDate().toString("dd/MM/yyyy").toUTF8()+"</i>");
        mTypeContainer->addStyleClass("mContenBaslikFotoVideo");
        this->initVideo();

        break;
    default:
        break;
    }

    mTypeContainer->setAttributeValue(Style::style,style);
}

void ItemWidget::initLikeContainer()
{
    if( this->getType() != AZ::Key::Type::DUYURU){
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
//    icerikText = newIcerikText;
    this->initTypeContainer();
}

void ItemWidget::setMfileList(const std::vector<std::string> &newMfileList)
{
    mfileList = newMfileList;
}

void ItemWidget::setPublic(bool newPublic)
{
    mPublic = newPublic;

    auto controller = this->addWidget(cpp14::make_unique<WContainerWidget>());
    controller->addStyleClass(Bootstrap::Grid::row);
    controller->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::AliceBlue));
    controller->setMargin(5,Side::Top);
    controller->setPadding(10,Side::Top|Side::Bottom);

    auto editBtn = controller->addWidget(cpp14::make_unique<WContainerWidget>());
    auto text = editBtn->addWidget(cpp14::make_unique<WText>("Düzelt"));
    text->setAttributeValue(Style::style,Style::font::size::s16px);
    editBtn->addStyleClass(Bootstrap::Button::Primary);
    editBtn->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                           Bootstrap::Grid::Medium::col_md_6+
                           Bootstrap::Grid::Small::col_sm_6+
                           Bootstrap::Grid::ExtraSmall::col_xs_6);
    editBtn->decorationStyle().setCursor(Cursor::PointingHand);

    auto delBtn = controller->addWidget(cpp14::make_unique<WContainerWidget>());
    auto textDel = delBtn->addWidget(cpp14::make_unique<WText>("Sil"));
    textDel->setAttributeValue(Style::style,Style::font::size::s16px);
    delBtn->addStyleClass(Bootstrap::Button::Danger);
    delBtn->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                           Bootstrap::Grid::Medium::col_md_6+
                           Bootstrap::Grid::Small::col_sm_6+
                           Bootstrap::Grid::ExtraSmall::col_xs_6);

    delBtn->clicked().connect([=](){

        auto askDialog = this->askConfirm("Silmek İstediğinize Emin misiniz?");
        askDialog->clicked().connect([=](){
            _deleteReq.emit(this->oid().value().to_string());
        });
    });

}

Signal<std::string> &ItemWidget::deleteReq()
{

    return _deleteReq;

}

const std::vector<std::string> &ItemWidget::getMfileList() const
{
    return mfileList;
}
