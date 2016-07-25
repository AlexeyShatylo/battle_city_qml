import QtQuick 2.0
import shape 1.0

Item {
    property MyObject cell
    id: root
    focus: true
    width: cell.width
    height: cell.height
    x: cell.shapeRect.x - 26
    y: cell.shapeRect.y - 26

    Image {
        id: img
        source: cell.source
        width: cell.width
        height: cell.height
    }
    Connections {
        target: cell
        onDirectionChanged:{
            if(cell.direction === 0)
                img.rotation = 0
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
