import QtQuick 2.5
import shape 1.0
Item {

    signal up()
    signal rigth()
    signal down()
    signal left()
    signal shooting()

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
        scale: 0.9
    }
    Keys.onPressed: {
        if (event.key === Qt.Key_Left || event.key === Qt.Key_Right
                || event.key === Qt.Key_Up || event.key === Qt.Key_Down) {
        }
        if (event.key === Qt.Key_Up) {
            cell.direction = 0;
            if (cell.yCoord > 0 ) {
                cell.yCoord = cell.yCoord - 13
                event.accepted = true;
                console.log("X" + cell.xCoord)
                console.log("Y" + cell.yCoord)
            }
        }
        if (event.key === Qt.Key_Right) {
            cell.direction = 1;
            if (cell.xCoord < 676 - root.width) {
                cell.xCoord = cell.xCoord + 13
                event.accepted = true;
            }
            console.log("X" + cell.xCoord)
            console.log("Y" + cell.yCoord)
        }
        if (event.key === Qt.Key_Down) {
            cell.direction = 2;
            if(cell.yCoord < 676 - root.height)
                cell.yCoord = cell.yCoord + 13
            event.accepted = true;
            console.log("X" + cell.xCoord)
            console.log("Y" + cell.yCoord)
        }
        if (event.key === Qt.Key_Left ) {
            cell.direction = 3;
            if(cell.xCoord > 0) {
                cell.xCoord = cell.xCoord - 13
                event.accepted = true;
                console.log("X" + cell.xCoord)
                console.log("Y" + cell.yCoord)
            }
        }
        if (event.key === Qt.Key_Space) {
            shooting();
        }
    }
    Connections {
        target: cell
        onDirectionChanged:{
            if(cell.direction === 0)
                console.log("X" + cell.xCoord)
            console.log("Y" + cell.yCoord)
            img.rotation = 0
            if(cell.direction === 1) {
                img.rotation = 90;
                console.log("X" + cell.xCoord)
                console.log("Y" + cell.yCoord)

            }
            if(cell.direction === 2) {
                img.rotation = 180;
                console.log("X" + cell.xCoord)
                console.log("Y" + cell.yCoord)

            }
            if(cell.direction === 3) {
                img.rotation = 270;
                console.log("X" + cell.xCoord)
                console.log("Y" + cell.yCoord)
            }
        }
    }
}
