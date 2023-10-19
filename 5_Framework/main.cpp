#include <QCoreApplication>
#include "settingsexample.h"
#include "qbufferexample.h"
#include "qfileexample.h"
#include "qdatastreamexample.h"
#include "qlogexample.h"
#include "Logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QSettings are used to store read data from the registry or .ini files
    SettingsExample settingExample(a);
    settingExample.RunExample();

    qInfo() << "============= Qt IO Classes =====================";
    //Qbuffer inherits from QIO and stores in Memory
    QBufferExample bufferExample;
    bufferExample.RunExample();

    //QFile inherits from QIO and stores data in file
    QFileExample fileExample;
    fileExample.RunExample(a);

    //QDataStream saves data as binary to file
    QDataStreamExample datastreamExample;
    datastreamExample.RunExample();

    fileExample.RunExampleWithLock();

    //Log Example
    QLogExample logExample;
    logExample.RunExample();

    Logger::Attach();
    qInfo() << "Hello , I am being logged!";
    Logger::Detach();



    return a.exec();
}