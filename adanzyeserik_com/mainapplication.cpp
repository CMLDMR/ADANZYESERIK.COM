#include "mainapplication.h"



MainApplication::MainApplication(const WEnvironment &env)
    :WApplication(env)
{


    wApp->addMetaHeader(MetaHeaderType::Meta,"Content-Type","text/html; charset=windows-1254");

    wApp->addMetaHeader("description","adabzyeserik","text/html; charset=utf-8");

    WApplication::useStyleSheet(WLink("css.css"));

    p_wtTheme = std::make_shared<Wt::WBootstrapTheme>();

    p_wtTheme->setVersion(Wt::WBootstrapTheme::Version::v3);

    p_wtTheme.get()->setResponsive(true);

    Wt::WApplication::instance()->setTheme(p_wtTheme);

    Wt::WApplication::instance()->useStyleSheet("resources/themes/bootstrap/3/bootstrap-theme.min.css");

    Wt::WApplication::instance()->addMetaLink("logo.ico","shortcut icon","","","image/x-icon","16x16",false);
    Wt::WApplication::instance()->setTitle("ADANZYE SERİK");







    root()->setContentAlignment(AlignmentFlag::Center);

    root()->addStyleClass("body");
    root()->setPositionScheme(PositionScheme::Relative);



    {
        auto container = root()->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setPositionScheme(PositionScheme::Fixed);
        container->setOffsets(0,AllSides);
        container->addStyleClass("backpick");
        container->setAttributeValue(Style::style,Style::background::url("backPick/"+std::to_string(mMainPage->getRandom(1,7))+".jpg")+
                                  Style::background::size::cover);
        container->setZIndex(-100);


        auto bimage = container->addWidget(cpp14::make_unique<WContainerWidget>());
        bimage->setOffsets(0,AllSides);
        bimage->addStyleClass("bacGround");
        bimage->setPositionScheme(PositionScheme::Absolute);

    }


    if( EnvParameters() ){
        root()->addWidget(cpp14::make_unique<WText>("<h1>Hello World REQ</h1>"));
    }else{
        mMainPage = root()->addWidget(cpp14::make_unique<MainPage>());
    }





}

MainApplication::~MainApplication()
{

    LOG << "Destructor" << LOGEND;
//    delete mResource;
//    mResource = nullptr;

}

bool MainApplication::EnvParameters()
{

    bool anyAttemp = false;

    QMap<QString,QString> mapList;
    //    test Link : http://192.168.0.31:8080/?type=dilekce&_id=5daee97a6435000043002489 cevaplanmis
    // http://192.168.0.31:8080/?type=dilekce&_id=5daeebd8222400005d0005dc Cevaplanmamis
    for (const auto &str : this->environment().getParameterMap() ) {
        //        std::cout << "First: " << str.first << " " << str.second.size() << " " << str.second.back() << std::endl;
        for( const auto &sec : str.second )
        {
            mapList[str.first.c_str ()] = QString::fromStdString (sec);
        }
    }



    //http://192.168.0.31:8080/?type=_login&ph=05335018051
    if( mapList.contains ("type") )
    {
        if( mapList["type"] == "login" )
        {
            auto username = mapList["user"];
            if( username == "admin" ){
                anyAttemp = true;
            }
        }
    }

    return anyAttemp;

}


