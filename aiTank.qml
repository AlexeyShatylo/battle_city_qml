import QtQuick 2.0
import shape 1.0

Item {
    property MyObject cell
    id: root
    focus: true
    width: 52
    height: 52
    x: cell.xCoord
    y: cell.yCoord

    Image {
        id: img
        source: cell.source
        width: 52
        height: 52
        anchors.centerIn: root

    }
    Connections {
        target: cell
        onDirectionChanged:{
            if(cell.direction === 0)
                img.rotation = 0
            console.log(root.x)
            if(cell.direction === 1) {
                img.rotation = 90;
            }
            if(cell.direction === 2) {
                img.rotation = 180;
            }
            if(cell.direction === 3) {
                img.rotation = 270;
            }
        }
    }
}
