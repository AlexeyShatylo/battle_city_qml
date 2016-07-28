import QtQuick 2.5
import shape 1.0
Item {

    signal up()
    signal rigth()
    signal down()
    signal left()
    signal shooted()
    property MyObject cell
    property MyGame game

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
        rotation: cell.direction * 90
    }
    onXChanged: {
        console.log(root.x)
    }
    onYChanged: {
        console.log(root.y)
    }

    Keys.onPressed: {
        if (event.key === Qt.Key_Up) {
            up();
        }
        if (event.key === Qt.Key_Right) {
            rigth();

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

}
