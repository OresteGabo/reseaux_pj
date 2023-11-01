// Car.qml

import QtQuick 2.15
import QtLocation 5.15
import QtPositioning 5.15

Item {
    property alias geoCoordinate: mapCircle.center
    property bool isMoving: false
    property int carID: 0

    width: 20
    height: 20

    MapCircle {
        id: mapCircle
        radius: 8
        color: isMoving ? "green" : "blue"
    }

    Text {
        anchors.centerIn: parent
        text: carID.toString()
        color: "white"
        font.pixelSize: 12
    }

    onGeoCoordinateChanged: {
        mapCircle.center = geoCoordinate;
    }
}
