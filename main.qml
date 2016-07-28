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
            property MyGame gameContainer
            property Item playerTank
            property Item aITank
            property var game

            id:scene
            width: 676
            height: 676

            color: "black"
            anchors.centerIn: parent
            Component.onCompleted: {
                var cmpnt = Qt.createComponent("Game.qml")
                if (cmpnt.status === Component.Ready){
                    game = cmpnt.createObject(scene);
                    gameContainer = game.gamedata
                    console.log(gameContainer.qty)
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
                                Сoncrete.createObject(scene,{"cell": game.gamedata.getItem(i),});
                            }
                            break;
                        case 7:
                            game.gamedata.getItem(i).source = "qrc:/img/EnemyUp.png";
                            var aiTank = Qt.createComponent("aiTank.qml");
                            if (aiTank.status === Component.Ready) {
                                aITank = aiTank.createObject(scene, {"cell": game.gamedata.getItem(i)});
                            }
                            break;
                        case 9:
                            game.gamedata.getItem(i).source = "qrc:/img/PlayerUp.png";
                            var userTankCmpnt = Qt.createComponent("UserTank.qml");
                            if(userTankCmpnt.status === Component.Ready) {
                                playerTank = userTankCmpnt.createObject(scene, {"cell": game.gamedata.getItem(i), "game": game.gamedata});
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

            Connections {
                target: scene.playerTank
                onShooted: {
                    var bullet = scene.gameContainer.shoot(scene.playerTank.cell, 0)
                    var bulletCmpnt = Qt.createComponent("Bullet.qml");
                    if(bulletCmpnt.status === Component.Ready){
                        bulletCmpnt.createObject(scene,{"cell": bullet})
                    }
                }
            }
            Connections {
                target: scene.aITank
                onShooting: {
                    var bullett = scene.gameContainer.shoot(scene.aITank.cell,0)
                    var bullettCmpnt = Qt.createComponent("Bullet.qml");
                    if (bullettCmpnt.status === Component.Ready) {
                        bullettCmpnt.createObject(scene,{"cell": bullett})
                    }
                }
            }
            Connections {
                target: scene.gameContainer
                onCreatePlayer: {
                    var tank = scene.gameContainer.createPlayerTank();
                    tank.source = "qrc:/img/EnemyUp.png";
                    var userTankCmpnt = Qt.createComponent("UserTank.qml");
                    if (userTankCmpnt.status === Component.Ready) {
                        scene.playerTank = userTankCmpnt.createObject(scene, {"cell": tank});
                    }
                }
            }
            Connections {
                target: scene.gameContainer
                onCreateEnemy: {
                    var tmp = scene.gameContainer.createEnemyTank();
                    tmp.source = "qrc:/img/EnemyUp.png";
                    var aiTank = Qt.createComponent("aiTank.qml");
                    if (aiTank.status === Component.Ready) {
                        scene.aITank = aiTank.createObject(scene, {"cell": tmp});
                    }
                }

            }
            Connections {
               target:scene.gameContainer
               onTankOnLevelChanged:{
                console.log("tanks left :" + scene.gameContainer.tanksOnLevel);
               }
            }
            Connections {
               target:scene.gameContainer
               onGameOver: {
                console.log("Game over! bye")
               }
            }
            Connections {
                target: scene.playerTank
                onUp: {
                    scene.gameContainer.move(scene.playerTank.cell,0);
                }
                onDown: {
                    scene.gameContainer.move(scene.playerTank.cell,2);
                }
                onLeft: {
                    scene.gameContainer.move(scene.playerTank.cell,3);
                }
                onRigth: {
                    scene.gameContainer.move(scene.playerTank.cell,1);
                }
            }
        }
    }

}





