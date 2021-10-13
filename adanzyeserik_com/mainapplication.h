#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "db.h"
#include <mongoheaders.h>
#include "mainpage.h"
#include "Response.h"


class MainApplication : public WApplication
{
public:
    MainApplication(const WEnvironment &env);
    ~MainApplication();


    MainPage* mMainPage;

    bool EnvParameters();

private:
    mongocxx::client* mClient;
    mongocxx::database db;
    std::shared_ptr<Wt::WBootstrapTheme> p_wtTheme;


};

#endif // MAINAPPLICATION_H
