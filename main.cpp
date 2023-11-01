#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "car.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Create and manage Car objects in C++
    QList<Car*> carList;

    for (int i = 0; i < 10; ++i) {
        QGeoCoordinate carLocation(47.7511 + (i * 0.001), 7.3357); // Example locations
        Car* car = new Car(carLocation);
        carList.append(car);
    }

    // Expose carList as a context property to QML
    engine.rootContext()->setContextProperty("carList", QVariant::fromValue(carList));

    const QUrl url(u"qrc:/untitled_del/Main.qml"_qs);
    /*QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);*/
    engine.load(url);

    return app.exec();
}
