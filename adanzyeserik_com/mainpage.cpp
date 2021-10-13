#include "mainpage.h"

MainPage::MainPage()
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
    auto content = this->Content()->addWidget(cpp14::make_unique<BodyContainer>());

    header->HakkindaClicked().connect(content,&BodyContainer::initHakkinda);
    header->MainPageClicked().connect(content,&BodyContainer::initIletisim);



    this->Footer()->addWidget(cpp14::make_unique<FooterContainer>());
}
