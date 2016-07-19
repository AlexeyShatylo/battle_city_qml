import QtQuick 2.5
import shape 1.0
Item {
    property MyObject tile

    property string iconSource: tile.source
    property real elementX: tile.xCoord
    property real elementY: tile.yCoord
    id: root
    focus: true
    width: 26
    height: 26
    x: tile.xCoord
    y: tile.yCoord

    Image {
        id: img
        source: tile.source
        width: root.width
        height: root.height
    }
    function open (tmpTile) {
        tile = tmpTile;
    }
}
