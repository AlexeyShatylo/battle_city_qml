import QtQuick 2.5
import shape 1.0
Item {
    property MyObject cell
    property bool passeble

    id: root
    width: 26
    height: 26

    x: cell.xCoord
    y: cell.yCoord

    Image {
        id: img
        source: cell.source
        width: root.width
        height: root.height
    }
    Connections{
        target: cell
        onHpChanged: {
            if (cell.hp === 0) {
                root.visible = 0;
            }
        }
    }
}
