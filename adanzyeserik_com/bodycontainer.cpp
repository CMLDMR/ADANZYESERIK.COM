#include "bodycontainer.h"
#include "widget/itemwidget.h"

BodyContainer::BodyContainer()
{

    this->addStyleClass(Bootstrap::Grid::Hidden::hidden_xs);
    this->setMargin(75,Side::Top);
    this->setMargin(100,Side::Bottom);



    this->setMaximumSize(1080,WLength::Auto);

    this->setContentAlignment(AlignmentFlag::Center);

    mMainContainer = this->addWidget(cpp14::make_unique<WContainerWidget>());
    mMainContainer->addStyleClass(Bootstrap::Grid::row);
    mMainContainer->setMaximumSize(1080,WLength::Auto);

    this->loadAkis();



}

void BodyContainer::loadLastAkis(WContainerWidget *mAkisContainer)
{

//    for( int i = 0 ; i < 5 ; i++ ){
//        mAkisContainer->addWidget(cpp14::make_unique<ItemWidget>());
//    }

    {
        auto duyuru1 = mAkisContainer->addWidget(cpp14::make_unique<ItemWidget>(AZ::Key::Type::PHOTO));
        duyuru1->setIcerikText("<h4>İl Milli Eğitim Müdürüne Serik Çakısı Hediye Ettik</h4>"
                               "<img src=\"temp/4.jpg\" alt=\"İl Milli Eğitim\" width=\"100%\" height=\"400\">");

    }

    {
        auto duyuru1 = mAkisContainer->addWidget(cpp14::make_unique<ItemWidget>(AZ::Key::Type::PHOTO));
        duyuru1->setIcerikText("<h4>İl Milli Eğitim Müdürlüğü ile Toplantımızı Gerçekleştirdik</h4>"
                               "<img src=\"temp/3.jpg\" alt=\"İl Milli Eğitim\" width=\"100%\" height=\"400\">");

    }

    {
        auto duyuru1 = mAkisContainer->addWidget(cpp14::make_unique<ItemWidget>(AZ::Key::Type::PHOTO));
        duyuru1->setIcerikText("<h4>İlçe Milli Eğitim Müdürlüğü ile Toplantımızı Gerçekleştirdik</h4>"
                               "<img src=\"temp/2.jpg\" alt=\"Milli Eğitim Müdürümüz\" width=\"100%\" height=\"450\">");

    }

    {
        auto duyuru1 = mAkisContainer->addWidget(cpp14::make_unique<ItemWidget>(AZ::Key::Type::PHOTO));
        duyuru1->setIcerikText("<h4>Serik Belediyesi İle Toplantımızı Gerçekleştirdik</h4>"
                               "<img src=\"temp/1.jpg\" alt=\"Serik Belediyesi\" width=\"100%\" height=\"450\">");

    }

    {
        //☑
        auto duyuru1 = mAkisContainer->addWidget(cpp14::make_unique<ItemWidget>(AZ::Key::Type::ETKINLIK));
        duyuru1->setIcerikText("<h3>Yaklaşan Etkinlikler</h3>"
                               "<p><span style=\"font-size:25px;\">☑</span><b> Ekim Ayı</b>"
                               "<br>● Tarihi ve Doğal Güzelliklerini Keşfet</p>"
                               "<p></p>"

                               "<p><span style=\"font-size:25px;\">☑</span><b> Kasım Ayı</b>"
                               "<br>● Yeşilime Mevime Sahip Çıkıyorum</p>"
                               "<p></p>"

                               "<p><span style=\"font-size:25px;\">☑</span><b> Aralık Ayı</b>"
                               "<br>● Geçmişini Tanıyarak Ufkuna Güzellik Kat</p>"
                               "<p></p>"

                               "<p><span style=\"font-size:25px;\">☑</span><b> Ocak Ayı</b>"
                               "<br>● Kardeş Okulumla Kitabımi,Oyuncağımı Paylaşıyorum</p>"
                               "<p></p>"

                               "<p><span style=\"font-size:25px;\">☑</span><b> Şubat Ayı</b>"
                               "<br>● Tanı ve Yaşat</p>"
                               "<p></p>"

                               "<p><span style=\"font-size:25px;\">☑</span><b> Mart Ayı</b>"
                               "<br>● Hoşgeldin Atam</p>"
                               "<p></p>"

                               "<p><span style=\"font-size:25px;\">☑</span><b> Nisan Ayı</b>"
                               "<br>● Benim Ellerimden</p>"
                               "<p></p>"

                               "<p><span style=\"font-size:25px;\">☑</span><b> Mayıs Ayı</b>"
                               "<br>● Benim Festivalim</p>"
                               "<p></p>");
    }

    {
        auto basin1 = mAkisContainer->addWidget(cpp14::make_unique<ItemWidget>(AZ::Key::Type::BASINDA));
        basin1->setId("basin1");
        basin1->setIcerikText("<h3>A'dan Z'ye Serik Projesi Başlıyor</h3>"
                              "<p>Aşağıkocayatak İlkokulu öğretmenlerimiz Asuman Demiray, Gülsüm Koca, Nurcan Yıldırım, "
                              "Hatice Açıkalın; Deniztepesi İlkokulu öğretmenlerimiz Halime İltar, Arif Dağlı, Serap Taş; "
                              "Tekeli İlkokulu öğretmenlerimiz Ferit İltar, Elif Zengin ve Karadayı İlkokulu öğretmenimiz "
                              "Özlem Taş tarafında fikri altyapısı oluşturulan projeye Kaymakamlığımız, Belediyemiz ve "
                              "İlçe Milli Eğitim Müdürlüğümüzün verdiği destekle ‘A’dan Z’ye Serik’ projesi başlıyor</p>"
                              "<p>Belediyemiz, Serik Kaymakamlığımız, Serik İlçe Milli Eğitim Müdürlüğümüz, Aşağıkocayatak "
                              "İlkokulumuz, Deniztepesi İlkokulumuz, Karadayı İlkokulumuz ve Tekeli İlkokulumuz işbirliği ile "
                              "ortaya çıkan bu projede amaç öğrencilerimizin ilçemizin gelenek ve göreneklerini, tarihi ve "
                              "doğal güzelliklerini, yöresel yemeklerini tanıma fırsatı bulmaları, geçmişten gelen değerlerimizin "
                              "önemini kavrayıp ileriki kuşaklara taşımalarıdır.</p>"
                              "<p><b>Başkan Aputkan, ‘“Halkımızın yararına olacak her projeyi destekliyoruz.”</b></p>"
                              "<p>Başkanımız Sayın Enver Aputkan yaptığı açıklamada ‘A’dan Z’ye Serik projesi, Serik’te "
                              "okuyan öğrencilerimizin ilçemizin tarihini ve kültürünü öğrenmeleri ve tanıtımı için çok "
                              "önemli bir projedir. Öncelikle bu proje için emek veren öğretmenlerimize teşekkür ediyorum. "
                              "Çocuklarımız bizim geleceğimiz. Çocuklarımız başta olmak üzere halkımızın yararına olacak her "
                              "projeyi desteklemeye devam edeceğiz.’ dedi.</p>"
                              "<p><b>Proje Detayları</b></p>"
                              "<p>Proje ilk olarak Ekim ayında ‘Tarihi ve Doğal Güzellikleri Keşfet’ etkinliği ile başlayacaktır. "
                              "Ardından Kasım ayında ‘Yeşilime Mavime Sahip Çıkıyorum’, Aralık ayında ‘Geçmişini Tanıyarak Ufkuna "
                              "Güzellik Kat’, Ocak ayında ‘Kardeş Okulumla Kitabımı Oyuncağımı paylaşıyorum, Şubat ayında tanı ve "
                              "yaşat, Mart ayında ‘Hoşgeldin Atam’, Nisan ayında ‘Benim Ellerimden’ ve Mayıs ayında düzenlenecek "
                              "‘Benim Festivalim’ etkinliği ile son bulacaktır.</p>");
    }

    {
        auto duyuru1 = mAkisContainer->addWidget(cpp14::make_unique<ItemWidget>(AZ::Key::Type::DUYURU));
        duyuru1->setIcerikText("<h4>Web Sitesi Yayında</h4>"
                               "<p>Site Yayınlamaya Başlamış Olup Geliştirilmeye Devam Etmektedir.</p>");

    }





    auto container = mAkisContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::col_full_12);
    container->setPadding(5,Side::Top|Side::Bottom);

//    auto devamBtn = container->addWidget(cpp14::make_unique<WPushButton>("Devamı..."));
//    devamBtn->addStyleClass(Bootstrap::Button::Danger);
//    devamBtn->clicked().connect([=](){
//        mAkisContainer->removeWidget(container);
//        this->loadLastAkis(mAkisContainer);
//    });

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
