import QtQuick 2.0
import shape 1.0
Rectangle {
    property string iconSource: ""
    property real elementX: 0
    property real elementY: 0
    width: 26
    height: 26
    Image {
        id: img
        source: parent.iconSource
    }
    Behavior on x {
        NumberAnimation {
            duration: 200
            easing.type: Easing.Linear
        }
    }
    Behavior on y {
        NumberAnimation {
            duration: 500
            easing.type: Easing.InOutQuad
        }
    }
}
