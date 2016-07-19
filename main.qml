import QtQuick 2.5
import QtQuick.Window 2.2
import QtMultimedia 5.6
import QtQuick.Controls 1.4
import shape 1.0
import QtQml 2.2

ApplicationWindow {
    visible: true
    width: maximumWidth
    height: maximumHeight
    Rectangle{
        id: root
        anchors.fill: parent
        color: "gray"
        Rectangle {

            id:scene
            width: 676
            height: 676

            color: "black"
            anchors.centerIn: parent
            Component.onCompleted: {
                var game;
                var cmpnt = Qt.createComponent("Game.qml")
                if (cmpnt.status === Component.Ready){
                    game = cmpnt.createObject(scene);

                    for (var i = 0; i < game.gamedata.qty ; i++) {
                        switch (game.gamedata.getTile(i).type) {
                        case 0:
                            break;
                        case 1:
                            game.gamedata.getTile(i).source = "qrc:/img/Brick_quarter.png";
                            break;
                        case 2:
                            game.gamedata.getTile(i).source = "qrc:/img/Сoncrete_quarter.png";
                            break;
                        }
                        var component = Qt.createComponent("Cell.qml")
                        if (component.status === Component.Ready){
                            component.createObject(scene,{"iconSource": game.gamedata.getTile(i).source, "x": game.gamedata.getTile(i).xCoord, "y": game.gamedata.getTile(i).yCoord, });

                        }
                    }
                }
            }
        }
    }
}



