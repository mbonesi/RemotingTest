#ifndef NODECOUNTERS_H
#define NODECOUNTERS_H

#include <QDateTime>
#include <QDataStream>

class NodeCountersClass
{
public:
    NodeCountersClass();
    NodeCountersClass(const NodeCountersClass &other);
    ~NodeCountersClass();

    NodeCountersClass &operator=(NodeCountersClass const &other);

    quint64 VisibleClassesCounts[8];
    quint64 SWIRClassesCounts[8];
    QDateTime TimeTaken;

    QDataStream &operator << (QDataStream &qds) const;
    QDataStream &operator >> (QDataStream &qds);

    //for serialization
    friend QDataStream &operator<<(QDataStream &qds, const NodeCountersClass &n);
    friend QDataStream &operator>>(QDataStream &qds, NodeCountersClass &n);
    friend bool operator!=(NodeCountersClass &l, const NodeCountersClass &r);

    //for making it printable like qDebug() << "Mesage:" << ((NodeCountersClass) instance);
    friend QDebug operator<<(QDebug dbg, const NodeCountersClass &instance);
};

Q_DECLARE_METATYPE(NodeCountersClass)


#endif // NODECOUNTERS_H
