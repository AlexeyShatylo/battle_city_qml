import QtQuick 2.0
import shape 1.0
Item{

    property MyObject cell
    id: root
    width: cell.width
    height: cell.height

    x: cell.xCoord - 13
    y: cell.yCoord - 13
    Image {
        id: img
        source: "qrc:/img/BulletUp.png"
        width: root.width
        height: root.height
        rotation: cell.direction * 90
    }
    onXChanged: {
        if(root.x === 13 || root.x === 676 - 13){
            root.destroy();

        }
    }
}
