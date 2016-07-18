import QtQuick 2.5
import QtQuick.Window 2.2
import QtMultimedia 5.6
import QtQuick.Controls 1.4
import shape 1.0
import QtQml 2.2

ApplicationWindow {
    visible: true
    width: maximumWidth
    height: maximumHeight
    Rectangle{
        id: root
        anchors.fill: parent
        color: "gray"
        Rectangle {
            id:scene
            width: 700
            height: 700
            color: "black"
            anchors.centerIn: parent
            Component.onCompleted: {
                var component = Qt.createComponent("Tank.qml")
                if (component.status === Component.Ready)
                    component.createObject(scene, {"focus" : true});
            }
        }
    }
}
