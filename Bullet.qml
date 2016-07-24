import QtQuick 2.0
import shape 1.0
Item {
    property MyObject cell

    id: root
    width: 26
    height: 26

    x: cell.xCoord -26
    y: cell.yCoord - 26
    Image {
        id: img
        source: "qrc:/img/BulletLeft.png"
        width: root.width
        height: root.height
    }
}
