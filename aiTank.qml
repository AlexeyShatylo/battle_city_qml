import QtQuick 2.0
import shape 1.0

Item {
    property MyObject cell
    signal shooting()
    id: root
    focus: true
    width: cell.width
    height: cell.height
    x: cell.xCoord
    y: cell.yCoord

    Image {
        id: img
        source: cell.source
        width: cell.width
        height: cell.height
    }
    Connections {
        target: cell
        onDirectionChanged:{
            if(cell.direction === Direction.Up)
                img.rotation = 0
            if(cell.direction === Direction.Right) {
                img.rotation = 90;
            }
            if(cell.direction === Direction.Down) {
                img.rotation = 180;
            }
            if(cell.direction === Direction.Left) {
                img.rotation = 270;
            }
        }
    }
    Connections {
        target: cell
        onShooting: {
            shooting();
        }
    }
    Connections{
        target: cell
        onHpChanged: {
            if(cell.hp === 0) {
                root.destroy();
            }
        }

    }
}
