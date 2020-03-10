#include "nodecounters.h"

#include <QDebug>

NodeCountersClass::NodeCountersClass()
{
    memset(VisibleClassesCounts, 0, 8*sizeof(quint64));
    memset(SWIRClassesCounts, 0, 8*sizeof(quint64));
    TimeTaken = QDateTime::currentDateTime();
}


NodeCountersClass::NodeCountersClass(NodeCountersClass const &other)
{
    for(int i=0; i<8; i++)
    {
        VisibleClassesCounts[i] = other.VisibleClassesCounts[i];
        SWIRClassesCounts[i] = other.SWIRClassesCounts[i];
    }

    TimeTaken = other.TimeTaken;
}

NodeCountersClass::~NodeCountersClass()
{

}

NodeCountersClass& NodeCountersClass::operator =(const NodeCountersClass &other)
{
    for(int i=0; i<8; i++)
    {
        VisibleClassesCounts[i] = other.VisibleClassesCounts[i];
        SWIRClassesCounts[i] = other.SWIRClassesCounts[i];
    }
    TimeTaken = other.TimeTaken;
    return *this;
}

QDataStream &NodeCountersClass::operator <<(QDataStream &qds) const
{
    for(int i=0; i<8; i++)
    {
        qds << VisibleClassesCounts[i];
        qds << SWIRClassesCounts[i];
    }
    qds << TimeTaken;

    return qds;
}

QDataStream &NodeCountersClass::operator >>(QDataStream &qds)
{
    for(int i=0; i<8; i++)
    {
        qds >> VisibleClassesCounts[i];
        qds >> SWIRClassesCounts[i];
    }
    qds >> TimeTaken;

    return qds;
}

//friend functions
QDataStream &operator<<(QDataStream &qds, const NodeCountersClass &n)
{
    return n.operator<<(qds);
}

QDataStream &operator>>(QDataStream &qds, NodeCountersClass &n)
{
    return n.operator>>(qds);
}

bool operator!=(NodeCountersClass &l, const NodeCountersClass &r)
{
    bool bRetVal = true;
    for(int i=0; i<8; i++)
    {
        if((l.VisibleClassesCounts[i] != r.VisibleClassesCounts[i]) ||
           (l.SWIRClassesCounts[i] != r.SWIRClassesCounts[i]) )
            goto done;
    }

    bRetVal |= (l.TimeTaken != r.TimeTaken);

done:
    return bRetVal;
}

QDebug operator<<(QDebug dbg, const NodeCountersClass &instance)
{
    dbg.nospace() << "NodeCounters " << instance.TimeTaken.toString();
    return dbg.maybeSpace();
}
