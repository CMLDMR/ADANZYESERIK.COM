
#include <QApplication>
#include "db.h"
#include <mongoheaders.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mongocxx::instance ins{};


}
