import QtQuick 2.0
import shape 1.0
Rectangle{
    property MyObject cell
    border.color: "white"
    border.width: 2
    id: root
    width: cell.width
    height: cell.height

    x: cell.shapeRect.x - 13
    y: cell.shapeRect.y - 13

    Image {
        id: img
        source: "qrc:/img/BulletUp.png"
        width: root.width
        height: root.height
        rotation: cell.direction * 90
    }
    Connections{
        target: root
        onXChanged: {
            console.log(root.x)
        }
    }
}
