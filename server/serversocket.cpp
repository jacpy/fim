#include "serversocket.h"

ServerSocket::ServerSocket()
{
    this->tcpServer = new QTcpServer();
}

bool ServerSocket::listen(quint16 port) {
    if (this->tcpServer->isListening()) {
//        QDebug() << "the port: " << port << " has aleady bind.";
        qDebug() << "the port: " << " has aleady bind.";
        return true;
    }

    return this->tcpServer->listen(QHostAddress::Any, port);
}

ServerSocket::~ServerSocket() {
    delete this->tcpServer;
}
