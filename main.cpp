#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "mainviewmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    qmlRegisterType<MyListModel>("com.example.models", 1, 0, "MyListModel");

    engine.loadFromModule("playground-qt", "Main");

    return app.exec();
}
