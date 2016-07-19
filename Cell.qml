import QtQuick 2.5
import shape 1.0
Item {

    property string iconSource
    property real elementX
    property real elementY
    id: root
    width: 26
    height: 26

    x: elementX
    y: elementY

    Image {
        id: img
        source: iconSource
        width: root.width
        height: root.height
    }
}
