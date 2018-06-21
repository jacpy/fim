#include "mainwindow.h"
#include <QApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Fim");
    w.show();

    return a.exec();
    */

    QApplication app(argc, argv);
    QApplication::setApplicationDisplayName(Server::tr("Fortune Server"));
    Server server;
    server.show();
    return app.exec();
}
