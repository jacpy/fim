#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QtNetwork>

class ServerSocket
{
public:
    ServerSocket();
    virtual ~ServerSocket();

    bool listen(quint16 port);

private slots:
    void sessionOpened();
    void sendFortune();

private:
    QTcpServer *tcpServer = nullptr;

};

#endif // SERVERSOCKET_H
