
#include <QApplication>

#include "mainapplication.h"
#include <Wt/WServer.h>


std::unique_ptr<WApplication> createApplication(const WEnvironment& env)
{
    std::unique_ptr<MainApplication> app = cpp14::make_unique<MainApplication>(env);
    return app;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mongocxx::instance ins{};

    return Wt::WRun(argc,argv,[](const Wt::WEnvironment &env){
        return Wt::cpp14::make_unique<MainApplication>(env);
    });


}
