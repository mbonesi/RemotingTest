#include "dataclient.h"

DataClient::DataClient(QSharedPointer<ServerNodeReplica> ptr) :
    QObject(nullptr),
    replicaPtr(ptr)
{
    initConnections();

    tm.setInterval(2000L);
    connect(&tm, SIGNAL(timeout()), this, SLOT(tick()));
    tm.start();
}

DataClient::~DataClient()
{
    tm.stop();
}

void DataClient::tick()
{
    TakePicture();
}

void DataClient::initConnections()
{
    connect(replicaPtr.data(), SIGNAL(CountersChanged(NodeCountersClass)), this, SLOT(onCountersChanged(NodeCountersClass)));
}

void DataClient::TakePicture()
{
    qInfo() << "client sending takepicture request";
    replicaPtr->TakeSnapshot();
}

void DataClient::onCountersChanged(NodeCountersClass c)
{
    for(int i=0; i<8; i++)
    {
        qInfo() << "Vis,  val" << i << c.VisibleClassesCounts[i];
        qInfo() << "SWIR, val" << i << c.SWIRClassesCounts[i];
    }
    qInfo() << "Data was recorded at" << c.TimeTaken.toString();
}
