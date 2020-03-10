#ifndef DATAENGINE_H
#define DATAENGINE_H

#include <QObject>
#include <QTimer>

#include "rep_servernode_source.h"

class DataEngine : public ServerNodeSimpleSource
{
    Q_OBJECT
public:
    DataEngine(QObject *parent = nullptr);
    virtual ~DataEngine() override;

    void Start();
    void Stop();

    // ServerNodeSource interface
public:
    virtual NodeCountersClass Counters() const override;
    //void setCounters(NodeCountersClass counts) override;

public slots:
    virtual void TakeSnapshot() override;

private:
    NodeCountersClass data;
    QTimer m_Beat;

private slots:
    void tick();
};

#endif // DATAENGINE_H
