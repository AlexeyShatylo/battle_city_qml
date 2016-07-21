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
            width: 676 //
            height: 676 //

            color: "black"
            anchors.centerIn: parent
            Component.onCompleted: {
                var game;
                var cmpnt = Qt.createComponent("Game.qml")
                if (cmpnt.status === Component.Ready){
                    game = cmpnt.createObject(scene);

                    for (var i = 0; i < game.gamedata.qty ; i++) {
                        switch (game.gamedata.getItem(i).type) {
                        case 0:
                            break;
                        case 1:
                            game.gamedata.getItem(i).source = "qrc:/img/Brick_quarter.png";
                            var Brick = Qt.createComponent("Cell.qml");
                            if (Brick.status === Component.Ready){
                                Brick.createObject(scene,{"cell": game.gamedata.getItem(i)});
                            }
                            break;
                        case 2:
                            game.gamedata.getItem(i).source = "qrc:/img/Сoncrete_quarter.png";
                            var Сoncrete = Qt.createComponent("Cell.qml");
                            if (Сoncrete.status === Component.Ready){
                                Сoncrete.createObject(scene,{"cell": game.gamedata.getItem(i)});
                            }
                            break;
                        case 7:
                            game.gamedata.getItem(i).source = "qrc:/img/EnemyUp.png";
                            var usetTankCmpnt = Qt.createComponent("aiTank.qml");
                            if(usetTankCmpnt.status === Component.Ready) {
                                console.log("I`m here")
                                usetTankCmpnt.createObject(scene, {"cell": game.gamedata.getItem(i)});
                            }
                            break;
                        case 9:
                            game.gamedata.getItem(i).source = "qrc:/img/PlayerUp.png";
                            var aiTank = Qt.createComponent("UserTank.qml");
                            if(aiTank.status === Component.Ready) {
                                console.log("I`m here")
                                aiTank.createObject(scene, {"cell": game.gamedata.getItem(i)});
                            }
                            break;
                        case 10:
                            game.gamedata.getItem(i).source = "qrc:/img/base.png";
                            var Base = Qt.createComponent("Base.qml");
                            if (Base.status === Component.Ready) {

                                Base.createObject(scene,{"cell": game.gamedata.getItem(i)});
                            }
                            break;
                        }
                    }
                }
            }
        }

    }
}





