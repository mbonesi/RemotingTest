#include <QCoreApplication>

#include "rep_servernode_replica.h"
#include "dataclient.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QRemoteObjectNode replicaNode; // create remote object node
    replicaNode.connectToNode(QUrl(QStringLiteral("local:switch"))); // connect with remote host node

    QSharedPointer<ServerNodeReplica> ptr;
    ptr.reset(replicaNode.acquire<ServerNodeReplica>()); // acquire replica of source from host node

    DataClient cli(ptr);

    return a.exec();
}
