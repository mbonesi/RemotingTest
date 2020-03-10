#ifndef DATACLIENT_H
#define DATACLIENT_H

#include <QObject>
#include <QSharedPointer>
#include <QTimer>

#include "rep_servernode_replica.h"


class DataClient : public QObject
{
    Q_OBJECT

public:
    DataClient();
    DataClient(QSharedPointer<ServerNodeReplica> ptr);
    ~DataClient();

    void initConnections();// Function to connect signals and slots of source and client

    void TakePicture();

public slots:
    void onCountersChanged(NodeCountersClass c);

private:
    QSharedPointer<ServerNodeReplica> replicaPtr;
    QTimer tm;

private slots:
    void tick();

};

#endif // DATACLIENT_H
