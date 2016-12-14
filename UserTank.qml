import QtQuick 2.5
import shape 1.0
FocusScope{

    signal up()
    signal right()
    signal down()
    signal left()
    signal shooted()
    property MyObject cell
    property MyGame game
    focus: true

    id: root
    width: 52
    height: 52
    x: cell.xCoord
    y: cell.yCoord


    Image {
        id: img
        source: root.cell.source
        width: root.cell.width
        height: root.cell.height
        anchors.centerIn: root
        rotation: root.cell.direction * 90
    }

    Keys.onPressed: {
        if (event.key === Qt.Key_Up) {
            up();
        }
        if (event.key === Qt.Key_Right) {
            right();
        }
        if (event.key === Qt.Key_Down) {
            down();
        }
        if (event.key === Qt.Key_Left ) {
            left();
        }
        if (event.key === Qt.Key_Space) {
            shooted();
        }
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
