#include "dataengine.h"
#include <QDebug>

void DataEngine::tick()
{
    for(int i=0; i<8; i++)
    {
        data.VisibleClassesCounts[i]+=static_cast<quint64>(i+8);
        data.SWIRClassesCounts[i]+=static_cast<quint64>(i+8);
    }
    data.TimeTaken = QDateTime::currentDateTime();

    //setCounters(data);
    qInfo() << "Server: tick";
}

DataEngine::DataEngine(QObject *parent) : ServerNodeSimpleSource(parent)
{
    m_Beat.setInterval(1000L);
    connect(&m_Beat, SIGNAL(timeout()), this, SLOT(tick()));
}

DataEngine::~DataEngine()
{
    Stop();
}

void DataEngine::Start()
{
    m_Beat.start();
}

void DataEngine::Stop()
{
    m_Beat.stop();
}


NodeCountersClass DataEngine::Counters() const
{
    qInfo() << "Server: received a request for reading data";
    return data;
}

//void DataEngine::setCounters(NodeCountersClass counts)
//{
//    //qInfo() << "Server: received request for writing data";
//    data = counts;
//}

void DataEngine::TakeSnapshot()
{
    qInfo() << "Server: takes time snapshot";
    data.TimeTaken = QDateTime::currentDateTime();    
    setCounters(data);
}
