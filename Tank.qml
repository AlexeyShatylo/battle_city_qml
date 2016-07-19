import QtQuick 2.0
import shape 1.0
Item {
    property string iconSource: tmp.source
    property real elementX: tmp.xCoord
    property real elementY: tmp.yCoord
    id: root
    focus: true
    width: 52
    height: 52
    x:tmp.xCoord
    y: tmp.yCoord
    MyObject{
        id: tmp
    }
    Image {
        id: img
        source: tmp.source
        width: root.width
        height: root.height
    }
    Keys.onPressed: {
        if (event.key === Qt.Key_Left || event.key === Qt.Key_Right
                || event.key === Qt.Key_Up || event.key === Qt.Key_Down) {
        }
        if (event.key === Qt.Key_Up) {
            tmp.direction = 0;
            if (tmp.yCoord > 0 ) {
                tmp.yCoord = tmp.yCoord - 5
                console.log(tmp.yCoord)
            }

        }
        if (event.key === Qt.Key_Right) {
            tmp.direction = 1;
            tmp.xCoord = tmp.xCoord + 5
        }
        if (event.key === Qt.Key_Down) {
            tmp.direction = 2;
            tmp.yCoord = tmp.yCoord + 5
        }
        if (event.key === Qt.Key_Left ) {
            tmp.direction = 3;
            tmp.xCoord = tmp.xCoord - 5
        }
    }
    Connections {
        target: tmp
        onDirectionChanged:{
            if(tmp.direction === 0)
                img.rotation = 0
            if(tmp.direction === 1) {
                img.rotation = 90;
            }
            if(tmp.direction === 2) {
                img.rotation = 180;
            }
            if(tmp.direction === 3) {
                img.rotation = 270;
            }
        }
    }
}
