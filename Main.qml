import QtQuick 2.15
import QtQuick.Window
import QtLocation 5.15
import QtPositioning 5.15
//import "UI/Car/Car"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Car Map"+carList.length)

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(47.7511, 7.3357) // Mulhouse, France
        zoomLevel: 14

        Component.onCompleted: {
            for (var i = 0; i < carList.length; ++i) {
                var car = carList[i];


                /*Car{
                    geoCoordinate: car.location
                    carID: car.carID
                    isMoving: car.isMoving
                }*/
            }
        }
    }
}
