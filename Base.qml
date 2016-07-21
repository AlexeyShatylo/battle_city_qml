import QtQuick 2.0
import shape 1.0

Item {
    property MyObject cell
    property bool passeble : false

    id: root
    width: 52
    height: 52

    x: cell.xCoord
    y: cell.yCoord

    Image {
        id: img
        source: cell.source
        width: root.width
        height: root.height
        anchors.fill: root
    }
}
