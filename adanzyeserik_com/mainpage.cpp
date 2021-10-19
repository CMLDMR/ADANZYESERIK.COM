#include "mainpage.h"

MainPage::MainPage(SerikBLDCore::DB* _mDB)
    :mDB(_mDB)
{
    this->initPage();
}



void MainPage::initPage()
{

    this->setContentAlignment(AlignmentFlag::Center);

    this->Header()->clear();
    this->Content()->clear();
    this->Footer()->clear();

    this->Content()->setContentAlignment(AlignmentFlag::Center);


    auto header = this->Header()->addWidget(cpp14::make_unique<HeaderContainer>());
    auto content = this->Content()->addWidget(cpp14::make_unique<BodyContainer>(this->mDB));

    header->HakkindaClicked().connect(content,&BodyContainer::initHakkinda);
    header->MainPageClicked().connect([=](){
        content->setType(AZ::Key::Type::NOP);
        content->initBody();
    });

    header->EtkinlikClicked().connect([=](){
        content->setType(AZ::Key::Type::ETKINLIK);
        content->initBody();
    });

    header->GaleriClicked().connect([=](){
        content->setType(AZ::Key::Type::PHOTO);
        content->initBody();
    });

    header->BasinClicked().connect([=](){
        content->setType(AZ::Key::Type::BASINDA);
        content->initBody();
    });

    header->DuyuruClicked().connect([=](){
        content->setType(AZ::Key::Type::DUYURU);
        content->initBody();
    });


    this->Footer()->addWidget(cpp14::make_unique<FooterContainer>());
}
