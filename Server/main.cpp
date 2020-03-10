#include <QCoreApplication>

#include "dataengine.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DataEngine d;

    QRemoteObjectHost sourceNode(QUrl(QStringLiteral("local:switch")));
    sourceNode.enableRemoting(&d);

    d.Start();

    return a.exec();
}
