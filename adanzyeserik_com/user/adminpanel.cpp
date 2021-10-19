#include "adminpanel.h"


LoginPanel::LoginPanel()
{
    auto userNameLineEdit = this->contents()->addWidget(cpp14::make_unique<WLineEdit>());
    userNameLineEdit->setPlaceholderText("Kullanıcı Adı Giriniz");

    auto passwordLineEdit = this->contents()->addWidget(cpp14::make_unique<WLineEdit>());
    passwordLineEdit->setPlaceholderText("Şifrenizi Giriniz");
    passwordLineEdit->setEchoMode(EchoMode::Password);

    auto controlButtons = this->footer()->addWidget(cpp14::make_unique<WContainerWidget>());
    auto hLayout = controlButtons->setLayout(cpp14::make_unique<WHBoxLayout>());
    hLayout->addStretch(1);
    auto loginBtn = hLayout->addWidget(cpp14::make_unique<WPushButton>("Giriş"));

    loginBtn->clicked().connect([=](){
       _SuccesLogin.emit(true);
    });

    auto cancelBtn = hLayout->addWidget(cpp14::make_unique<WPushButton>("İptal"));
    cancelBtn->clicked().connect([=](){
       _SuccesLogin.emit(false);
    });
    this->show();
}

Signal<bool> &LoginPanel::SuccesLogin()
{
    return _SuccesLogin;
}





AdminPanel::AdminPanel(DB *_mDB)
    :AZ::ItemManager(_mDB)
{
    auto _loginWidget = this->addChild(cpp14::make_unique<LoginPanel>());
    _loginWidget->SuccesLogin().connect([=](const bool &succes){

        this->initPanel();
        this->removeChild(_loginWidget);
    });

    this->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::AliceBlue));
}

void AdminPanel::initPanel()
{
    auto icerikEkle = this->Header()->addWidget(cpp14::make_unique<WText>("İçerik Ekle"));
    icerikEkle->addStyleClass(Bootstrap::Grid::Large::col_lg_3+
                              Bootstrap::Grid::Medium::col_md_3+
                              Bootstrap::Grid::Small::col_sm_4+
                              Bootstrap::Grid::ExtraSmall::col_xs_6+
                              Bootstrap::ContextualBackGround::bg_primary);
    icerikEkle->setInline(true);
    icerikEkle->setPadding(10,Side::Top|Side::Bottom);
    icerikEkle->decorationStyle().setCursor(Cursor::PointingHand);
    icerikEkle->clicked().connect(this,&AdminPanel::addIcerik);


    auto listele = this->Header()->addWidget(cpp14::make_unique<WText>("Listele"));
    listele->addStyleClass(Bootstrap::Grid::Large::col_lg_3+
                              Bootstrap::Grid::Medium::col_md_3+
                              Bootstrap::Grid::Small::col_sm_4+
                              Bootstrap::Grid::ExtraSmall::col_xs_6+
                              Bootstrap::ContextualBackGround::bg_primary);
    listele->setInline(true);
    listele->setPadding(10,Side::Top|Side::Bottom);
    listele->decorationStyle().setCursor(Cursor::PointingHand);
    listele->clicked().connect([=](){
       this->UpdateList();
    });
}

void AdminPanel::addIcerik()
{
    this->Content()->clear();


    auto tipContainer = this->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
    tipContainer->addStyleClass(Bootstrap::Grid::col_full_12);

    auto tipComboBox = tipContainer->addWidget(cpp14::make_unique<WComboBox>());
    tipComboBox->addItem("Basın");
    tipComboBox->addItem("Duyuru");
    tipComboBox->addItem("Fotoğraf");
    tipComboBox->addItem("Video");
    tipComboBox->addItem("Etkinlik");



    mContainer = this->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
    mContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    mContainer->setMargin(15,Side::Top|Side::Bottom);





    tipComboBox->sactivated().connect([=](const WString &str){

        if( str.toUTF8() == "Basın" ){
            this->addBasin();
        }else if( str.toUTF8() == "Duyuru" ){
            this->addDuyuru();
        }else if( str.toUTF8() == "Fotoğraf" ){
            this->addFoto();
        }else if( str.toUTF8() == "Video" ){
            this->addFoto();
        }else if( str.toUTF8() == "Etkinlik" ){
            this->addEtkinlik();
        }

    });

    this->addBasin();

}

void AdminPanel::addBasin()
{
    mContainer->clear();

    tempFileOidList.clear();


    auto rContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);
    rContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::AliceBlue));

    auto title_Text = rContainer->addWidget(cpp14::make_unique<WText>("<h3>BASIN/HABER EKLE</h3>"));
    title_Text->addStyleClass(Bootstrap::Grid::col_full_12);

    auto title_LineEdit = rContainer->addWidget(cpp14::make_unique<WLineEdit>());
    title_LineEdit->addStyleClass(Bootstrap::Grid::col_full_12);
    title_LineEdit->setPlaceholderText("Başlık Giriniz");
    title_LineEdit->setMargin(15,Side::Bottom);

    auto editContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    editContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    auto textEdit = editContainer->addWidget(cpp14::make_unique<WTextEdit>());
    textEdit->setHeight(350);
    textEdit->setMargin(30,Side::Top);




    auto _fotoContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    _fotoContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    auto _rFotoContainer = _fotoContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    _rFotoContainer->addStyleClass(Bootstrap::Grid::row);


    auto addFotoBtn = rContainer->addWidget(cpp14::make_unique<FileUploaderWidget>("Resim Yükle"));
    addFotoBtn->addStyleClass(Bootstrap::Grid::col_full_12);

    addFotoBtn->Uploaded().connect([=](){

        auto container = _rFotoContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_3+
                                 Bootstrap::Grid::Medium::col_md_3+
                                 Bootstrap::Grid::Small::col_sm_6+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);
        container->setHeight(200);
        container->setAttributeValue(Style::style,Style::background::url(addFotoBtn->doocRootLocation().toStdString())+
                                     Style::background::size::contain+
                                     Style::background::position::center_center+
                                     Style::background::repeat::norepeat);


        tempFileOidList.push_back(addFotoBtn->fileLocation().toStdString());

    });


    auto kaydetBtn = rContainer->addWidget(cpp14::make_unique<WPushButton>("Kaydet"));
    kaydetBtn->addStyleClass(Bootstrap::Button::Primary);

    kaydetBtn->clicked().connect([=](){

        if( textEdit->text().toUTF8().size() < 10 ){
            this->warnDialog("Yetersiz İçerik, min 10 karakter");
            return;
        }

        if( title_LineEdit->text().toUTF8().size() < 5 ){
            this->warnDialog("Yetersiz Başlık, min 5 karakter");
            return;
        }

        AZ::Item item(AZ::Key::Type::BASINDA);
        item.setContent(textEdit->text().toUTF8());
        item.setTitle(title_LineEdit->text().toUTF8());

        for( const auto &fileItem : tempFileOidList ){

            auto fileOid = this->getDB()->uploadfile(fileItem.c_str());

            if( fileOid.type() == bsoncxx::type::k_oid ){
                item.addFileOid(fileOid.get_oid().value.to_string());

            }else{
                this->warnDialog("Fotoğraf Yüklemede Hata Oluştu: " + this->getDB()->getLastError().toStdString());
                return;
            }
        }

        auto ins = this->InsertItem(item);
        if( ins.size() ){
            this->informDialog("Basın Bilgisi Eklendi");
        }else{
            this->warnDialog("Bir Hata Oluştu: " + this->getLastError().toStdString());
        }



    });



}

void AdminPanel::addEtkinlik()
{
    mContainer->clear();

    tempFileOidList.clear();


    auto rContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);
    rContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::AliceBlue));

    auto title_Text = rContainer->addWidget(cpp14::make_unique<WText>("<h3>ETKİNLİK EKLE</h3>"));
    title_Text->addStyleClass(Bootstrap::Grid::col_full_12);

    auto title_LineEdit = rContainer->addWidget(cpp14::make_unique<WLineEdit>());
    title_LineEdit->addStyleClass(Bootstrap::Grid::col_full_12);
    title_LineEdit->setPlaceholderText("Başlık Giriniz");
    title_LineEdit->setMargin(15,Side::Bottom);

    auto date_date = rContainer->addWidget(cpp14::make_unique<WDateEdit>());
    date_date->addStyleClass(Bootstrap::Grid::col_full_12);
    date_date->setMargin(15,Side::Bottom);
    date_date->setDate(WDate::currentDate());

    auto time_edit = rContainer->addWidget(cpp14::make_unique<WTimeEdit>());
    time_edit->addStyleClass(Bootstrap::Grid::col_full_12);
    time_edit->setMargin(15,Side::Bottom);
    time_edit->setTime(WTime::currentServerTime());

    auto editContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    editContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    auto textEdit = editContainer->addWidget(cpp14::make_unique<WTextEdit>());
    textEdit->setHeight(350);
    textEdit->setMargin(30,Side::Top);




    auto _fotoContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    _fotoContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    auto _rFotoContainer = _fotoContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    _rFotoContainer->addStyleClass(Bootstrap::Grid::row);


    auto addFotoBtn = rContainer->addWidget(cpp14::make_unique<FileUploaderWidget>("Resim Yükle"));
    addFotoBtn->addStyleClass(Bootstrap::Grid::col_full_12);

    addFotoBtn->Uploaded().connect([=](){

        auto container = _rFotoContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_3+
                                 Bootstrap::Grid::Medium::col_md_3+
                                 Bootstrap::Grid::Small::col_sm_6+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);
        container->setHeight(200);
        container->setAttributeValue(Style::style,Style::background::url(addFotoBtn->doocRootLocation().toStdString())+
                                     Style::background::size::contain+
                                     Style::background::position::center_center+
                                     Style::background::repeat::norepeat);


        tempFileOidList.push_back(addFotoBtn->fileLocation().toStdString());

    });


    auto kaydetBtn = rContainer->addWidget(cpp14::make_unique<WPushButton>("Kaydet"));
    kaydetBtn->addStyleClass(Bootstrap::Button::Primary);

    kaydetBtn->clicked().connect([=](){

        if( textEdit->text().toUTF8().size() < 10 ){
            this->warnDialog("Yetersiz İçerik, min 10 karakter");
            return;
        }

        if( title_LineEdit->text().toUTF8().size() < 5 ){
            this->warnDialog("Yetersiz Başlık, min 5 karakter");
            return;
        }

        AZ::Item item(AZ::Key::Type::ETKINLIK);
        item.setContent(textEdit->text().toUTF8());
        item.setTitle(title_LineEdit->text().toUTF8());

        for( const auto &fileItem : tempFileOidList ){

            auto fileOid = this->getDB()->uploadfile(fileItem.c_str());

            if( fileOid.type() == bsoncxx::type::k_oid ){
                item.addFileOid(fileOid.get_oid().value.to_string());

            }else{
                this->warnDialog("Fotoğraf Yüklemede Hata Oluştu: " + this->getDB()->getLastError().toStdString());
                return;
            }
        }

        auto ins = this->InsertItem(item);
        if( ins.size() ){
            this->informDialog("Basın Bilgisi Eklendi");
        }else{
            this->warnDialog("Bir Hata Oluştu: " + this->getLastError().toStdString());
        }



    });
}

void AdminPanel::addFoto()
{
    mContainer->clear();

    tempFileOidList.clear();


    auto rContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);
    rContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::AliceBlue));

    auto title_Text = rContainer->addWidget(cpp14::make_unique<WText>("<h3>FOTOĞRAF EKLE</h3>"));
    title_Text->addStyleClass(Bootstrap::Grid::col_full_12);

    auto title_LineEdit = rContainer->addWidget(cpp14::make_unique<WLineEdit>());
    title_LineEdit->addStyleClass(Bootstrap::Grid::col_full_12);
    title_LineEdit->setPlaceholderText("Başlık Giriniz");
    title_LineEdit->setMargin(15,Side::Bottom);

    auto date_date = rContainer->addWidget(cpp14::make_unique<WDateEdit>());
    date_date->addStyleClass(Bootstrap::Grid::col_full_12);
    date_date->setMargin(15,Side::Bottom);
    date_date->setDate(WDate::currentDate());

    auto time_edit = rContainer->addWidget(cpp14::make_unique<WTimeEdit>());
    time_edit->addStyleClass(Bootstrap::Grid::col_full_12);
    time_edit->setMargin(15,Side::Bottom);
    time_edit->setTime(WTime::currentServerTime());

    auto editContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    editContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    auto textEdit = editContainer->addWidget(cpp14::make_unique<WTextEdit>());
    textEdit->setHeight(350);
    textEdit->setMargin(30,Side::Top);




    auto _fotoContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    _fotoContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    auto _rFotoContainer = _fotoContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    _rFotoContainer->addStyleClass(Bootstrap::Grid::row);


    auto addFotoBtn = rContainer->addWidget(cpp14::make_unique<FileUploaderWidget>("Resim Yükle"));
    addFotoBtn->addStyleClass(Bootstrap::Grid::col_full_12);

    addFotoBtn->Uploaded().connect([=](){

        auto container = _rFotoContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_3+
                                 Bootstrap::Grid::Medium::col_md_3+
                                 Bootstrap::Grid::Small::col_sm_6+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);
        container->setHeight(200);
        container->setAttributeValue(Style::style,Style::background::url(addFotoBtn->doocRootLocation().toStdString())+
                                     Style::background::size::contain+
                                     Style::background::position::center_center+
                                     Style::background::repeat::norepeat);


        tempFileOidList.push_back(addFotoBtn->fileLocation().toStdString());

    });


    auto kaydetBtn = rContainer->addWidget(cpp14::make_unique<WPushButton>("Kaydet"));
    kaydetBtn->addStyleClass(Bootstrap::Button::Primary);

    kaydetBtn->clicked().connect([=](){

        if( textEdit->text().toUTF8().size() < 10 ){
            this->warnDialog("Yetersiz İçerik, min 10 karakter");
            return;
        }

        if( title_LineEdit->text().toUTF8().size() < 5 ){
            this->warnDialog("Yetersiz Başlık, min 5 karakter");
            return;
        }

        AZ::Item item(AZ::Key::Type::PHOTO);
        item.setContent(textEdit->text().toUTF8());
        item.setTitle(title_LineEdit->text().toUTF8());

        for( const auto &fileItem : tempFileOidList ){

            auto fileOid = this->getDB()->uploadfile(fileItem.c_str());

            if( fileOid.type() == bsoncxx::type::k_oid ){
                item.addFileOid(fileOid.get_oid().value.to_string());

            }else{
                this->warnDialog("Fotoğraf Yüklemede Hata Oluştu: " + this->getDB()->getLastError().toStdString());
                return;
            }
        }

        auto ins = this->InsertItem(item);
        if( ins.size() ){
            this->informDialog("Basın Bilgisi Eklendi");
        }else{
            this->warnDialog("Bir Hata Oluştu: " + this->getLastError().toStdString());
        }



    });
}

void AdminPanel::addVideo()
{

}

void AdminPanel::addDuyuru()
{
    mContainer->clear();

    tempFileOidList.clear();


    auto rContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);
    rContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::AliceBlue));

    auto title_Text = rContainer->addWidget(cpp14::make_unique<WText>("<h3>DUYURU EKLE</h3>"));
    title_Text->addStyleClass(Bootstrap::Grid::col_full_12);

    auto title_LineEdit = rContainer->addWidget(cpp14::make_unique<WLineEdit>());
    title_LineEdit->addStyleClass(Bootstrap::Grid::col_full_12);
    title_LineEdit->setPlaceholderText("Başlık Giriniz");
    title_LineEdit->setMargin(15,Side::Bottom);

    auto date_date = rContainer->addWidget(cpp14::make_unique<WDateEdit>());
    date_date->addStyleClass(Bootstrap::Grid::col_full_12);
    date_date->setMargin(15,Side::Bottom);
    date_date->setDate(WDate::currentDate());

    auto time_edit = rContainer->addWidget(cpp14::make_unique<WTimeEdit>());
    time_edit->addStyleClass(Bootstrap::Grid::col_full_12);
    time_edit->setMargin(15,Side::Bottom);
    time_edit->setTime(WTime::currentServerTime());

    auto editContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    editContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    auto textEdit = editContainer->addWidget(cpp14::make_unique<WTextEdit>());
    textEdit->setHeight(350);
    textEdit->setMargin(30,Side::Top);




    auto _fotoContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    _fotoContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    auto _rFotoContainer = _fotoContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    _rFotoContainer->addStyleClass(Bootstrap::Grid::row);


    auto addFotoBtn = rContainer->addWidget(cpp14::make_unique<FileUploaderWidget>("Resim Yükle"));
    addFotoBtn->addStyleClass(Bootstrap::Grid::col_full_12);

    addFotoBtn->Uploaded().connect([=](){

        auto container = _rFotoContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_3+
                                 Bootstrap::Grid::Medium::col_md_3+
                                 Bootstrap::Grid::Small::col_sm_6+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);
        container->setHeight(200);
        container->setAttributeValue(Style::style,Style::background::url(addFotoBtn->doocRootLocation().toStdString())+
                                     Style::background::size::contain+
                                     Style::background::position::center_center+
                                     Style::background::repeat::norepeat);


        tempFileOidList.push_back(addFotoBtn->fileLocation().toStdString());

    });


    auto kaydetBtn = rContainer->addWidget(cpp14::make_unique<WPushButton>("Kaydet"));
    kaydetBtn->addStyleClass(Bootstrap::Button::Primary);

    kaydetBtn->clicked().connect([=](){

        if( textEdit->text().toUTF8().size() < 10 ){
            this->warnDialog("Yetersiz İçerik, min 10 karakter");
            return;
        }

        if( title_LineEdit->text().toUTF8().size() < 5 ){
            this->warnDialog("Yetersiz Başlık, min 5 karakter");
            return;
        }

        AZ::Item item(AZ::Key::Type::DUYURU);
        item.setContent(textEdit->text().toUTF8());
        item.setTitle(title_LineEdit->text().toUTF8());

        for( const auto &fileItem : tempFileOidList ){

            auto fileOid = this->getDB()->uploadfile(fileItem.c_str());

            if( fileOid.type() == bsoncxx::type::k_oid ){
                item.addFileOid(fileOid.get_oid().value.to_string());

            }else{
                this->warnDialog("Fotoğraf Yüklemede Hata Oluştu: " + this->getDB()->getLastError().toStdString());
                return;
            }
        }

        auto ins = this->InsertItem(item);
        if( ins.size() ){
            this->informDialog("Basın Bilgisi Eklendi");
        }else{
            this->warnDialog("Bir Hata Oluştu: " + this->getLastError().toStdString());
        }



    });
}

void AdminPanel::onList(const QVector<AZ::Item> *mlist)
{
    this->Content()->clear();


    for( const auto &item : *mlist ){

        auto list = item.getfileOidList();
        std::vector<std::string> fileList;
        for( const auto &fotoOidList : list ){
            auto fileName = this->getDB()->downloadFileWeb(fotoOidList.c_str());
            fileList.push_back(fileName);
        }

        auto itemContainer = this->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
        auto _itemWidget = itemContainer->addWidget(cpp14::make_unique<ItemWidget>(item,fileList));
        _itemWidget->setPublic(false);
        _itemWidget->deleteReq().connect([=](){

            auto delList = _itemWidget->getfileOidList();

            for( const auto &delFileOid : delList ){
                LOG << "file: " << delFileOid << LOGEND;
                if( this->getDB()->deleteGridFS(delFileOid.c_str()) ){
                    LOG << "silindi" << LOGEND;
                }else{
                    LOG << this->getLastError().toStdString() << LOGEND;
                }
            }
            AZ::Item _item;
            _item.setOid(_itemWidget->oid().value().to_string());
            if( this->DeleteItem(_item) ){
                this->UpdateList();
            }else{
                this->informDialog("Silindi");
            }


        });






    }

}

void AdminPanel::errorOccured(const std::string &errorText)
{

}

