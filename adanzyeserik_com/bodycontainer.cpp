#include "bodycontainer.h"

BodyContainer::BodyContainer(SerikBLDCore::DB *mDB)
{

    mItemManager = new AZ::ItemManager(mDB);
//    this->addStyleClass(Bootstrap::Grid::Hidden::hidden_xs);
    this->setMargin(75,Side::Top);
    this->setMargin(100,Side::Bottom);



    this->setMaximumSize(1080,WLength::Auto);

    this->setContentAlignment(AlignmentFlag::Center);

    mMainContainer = this->addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->addStyleClass(Bootstrap::Grid::row);
    mMainContainer->setMaximumSize(1080,WLength::Auto);

    this->initBody();



}

BodyContainer::~BodyContainer()
{

    delete mItemManager;
    mItemManager = nullptr;

}

void BodyContainer::loadLastAkis(WContainerWidget *mAkisContainer)
{

    AZ::Item filter;
    if( mType != AZ::Key::Type::NOP ){
        filter.setType(mType);
    }

    mCount = mItemManager->countItem(filter);

    auto mlist = mItemManager->GetList(filter,mLimit,mSkip);

    for( const auto &item : qAsConst(mlist) ){

        auto list = item.getfileOidList();
        std::vector<std::string> fileList;
        for( const auto &fotoOidList : list ){
            auto fileName = mItemManager->getDB()->downloadFileWeb(fotoOidList.c_str());
            fileList.push_back(fileName);
        }

        mAkisContainer->addWidget(cpp14::make_unique<ItemWidget>(item,fileList));
    }



    mSkip += mLimit;

    if( mSkip + mLimit < mCount ){
        auto container = mAkisContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setPadding(5,Side::Top|Side::Bottom);

        auto devamBtn = container->addWidget(cpp14::make_unique<WPushButton>("Devamı..."));
        devamBtn->addStyleClass(Bootstrap::Button::Danger);
        devamBtn->clicked().connect([=](){
            mAkisContainer->removeWidget(container);
            this->loadLastAkis(mAkisContainer);
        });
    }



}

void BodyContainer::loadAkis()
{
    mMainContainer->clear();
    auto AkisContainer_ = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());

    AkisContainer_->addStyleClass(Bootstrap::Grid::Offset::Large::col_lg_2+
                                  Bootstrap::Grid::Offset::Medium::col_md_2+
                                  Bootstrap::Grid::Offset::Small::col_sm_2);


    AkisContainer_->addStyleClass(Bootstrap::Grid::Large::col_lg_8+
                                  Bootstrap::Grid::Medium::col_md_8+
                                  Bootstrap::Grid::Small::col_sm_8+
                                  Bootstrap::Grid::ExtraSmall::col_xs_12);

    AkisContainer_->addStyleClass(Bootstrap::Grid::Offset::Large::col_lg_2+
                                  Bootstrap::Grid::Offset::Medium::col_md_2+
                                  Bootstrap::Grid::Offset::Small::col_sm_2);


    auto AkisContainer = AkisContainer_->addWidget(cpp14::make_unique<WContainerWidget>());
    AkisContainer->addStyleClass(Bootstrap::Grid::row);

    this->loadLastAkis(AkisContainer);
}

void BodyContainer::setType(AZ::Key::Type newType)
{
    mType = newType;
}

void BodyContainer::initBody()
{
    mSkip = 0;
    this->loadAkis();
}

void BodyContainer::initHakkinda()
{
    mMainContainer->clear();


    auto mContainer = mMainContainer->addWidget(cpp14::make_unique<WContainerWidget>());

    mContainer->addStyleClass(Bootstrap::Grid::Offset::Large::col_lg_2+
                                  Bootstrap::Grid::Offset::Medium::col_md_2+
                                  Bootstrap::Grid::Offset::Small::col_sm_2);


    mContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_8+
                                  Bootstrap::Grid::Medium::col_md_8+
                                  Bootstrap::Grid::Small::col_sm_8+
                                  Bootstrap::Grid::ExtraSmall::col_xs_12);

    mContainer->addStyleClass(Bootstrap::Grid::Offset::Large::col_lg_2+
                                  Bootstrap::Grid::Offset::Medium::col_md_2+
                                  Bootstrap::Grid::Offset::Small::col_sm_2);

    mContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::FloralWhite));
//    mContainer->setHeight(600);
    mContainer->addStyleClass("Hakkinda");
    mContainer->setContentAlignment(AlignmentFlag::Justify);

    auto container = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    container->setWidth(WLength("100%"));
//    container->setHeight(600);
    container->setPadding(25,Side::Top);
    container->setPadding(75,Side::Bottom);

    container->addWidget(cpp14::make_unique<WText>("<h3>AdanZyeSERİK</h3>"
                                                    "<p>\tProjemiz ile öğrenciler Serik’in gelenek göreneklerini, tarihi ve doğal güzelliklerini, "
                                                    "yöresel yemeklerini tanıma fırsatı bularak, genç yaşta geçmişten gelen değerlerimizin önemini "
                                                    "kavrayıp ileriki kuşaklara taşıma misyonunu üstleneceklerdir. Projemizde küçük yaş grubundaki "
                                                    "öğrencilerin öğrenme şekli dikkate alınıp; gezip, görüp, hissedip, dokunup, tadarak bizzat "
                                                    "kendilerinin tecrübe etmeleri amaçlanmaktadır</p>"
                                                    "<p>\tÖğrenciler ortak çalışma, sorumluluk alma, sorunlara çözüm bulma, yakın çevresinin farkına varma, "
                                                    "iletişim gibi temel becerilerini geliştirerek,  farklı etkinliklerle bulunduğu çevreye karşı farklı "
                                                    "bakış açısı kazanacaklar ve kişisel gelişimlerini daha da yukarıya taşıyacaklar. Sonuç olarak; "
                                                    "insani değerlerimizin her geçen gün unutulduğu, doğanın ve çevremizin tahrip edildiği bir dünyada, "
                                                    "küçük bir adımın bile yaşadığımız çevreyi güzelleştirebildiğini fark etmemizi sağlayan bir projedir.</p>"));

}

void BodyContainer::initIletisim()
{
    mMainContainer->clear();


}
