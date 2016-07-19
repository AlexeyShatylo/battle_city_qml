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
            width: 700
            height: 700

            color: "black"
            anchors.centerIn: parent
            Component.onCompleted: {
                var game;
                var cmpnt = Qt.createComponent("Game.qml")
                if (cmpnt.status === Component.Ready){
                    game = cmpnt.createObject(scene);

                    console.log(game.gamedata.getTile(1).type);
                }
                for (var i = 0; i < game.gamedata.qty ; i++) {
                    var tiletype = game.gamedata.getTile(i).type;
                    console.log( "Number" + i + " | " +  game.gamedata.getTile(i).type)
                    switch (tiletype) {
                    case 0:
                        game.gamedata.getTile(i).source = "";
                        break;
                    case 1:
                        game.gamedata.getTile(i).source = "qrc:/img/Brick_quarter.png";
                        break;
                    case 2:
                        game.gamedata.getTile(i).source = "qrc:/img/Сoncrete_quarter.png";
                        break;
                    }
                }
                for (var j = 0; j <game.gamedata.qty; j++ ) {
                    var component = Qt.createComponent("Cell.qml")
                    if (component.status === Component.Ready){
                        component.createObject(scene,{"tile": game.gamedata.getTile(j)});

                    }
                }
            }
        }
    }
    Connections{
        target: game
        onCreated:{
            console.log (lala)
        }
    }
}



