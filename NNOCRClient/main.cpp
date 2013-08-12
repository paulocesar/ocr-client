#include <QCoreApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    new Client();
    return app.exec();
}
