import QtQuick 2.0
import shape 1.0
Item{

    property MyObject cell
    id: root
    width: cell.width
    height: cell.height

    x: cell.xCoord - 26
    y: cell.yCoord - 26
    Image {
        id: img
        source: "qrc:/img/BulletUp.png"
        width: root.width
        height: root.height
        rotation: cell.direction * 90
        scale : 0.5
    }

    Connections{
        target: cell
        onHpChanged: {
            if (cell.hp === 0) {
                root.destroy();
            }
        }
    }
}
