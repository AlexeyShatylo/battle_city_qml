import QtQuick 2.5
import QtQuick.Window 2.2
import QtMultimedia 5.6
import QtQuick.Controls 1.4
import shape 1.0
import QtQml 2.2
import QtQuick.Layouts 1.3
ApplicationWindow {

    id: mainWindow
    visible: true

    width: maximumWidth
    height: maximumHeight
    color: "black"
    onActiveFocusItemChanged: print("activeFocusItem", activeFocusItem)
    Audio {
        property string audioSource: ""
        id: audioPlayer
        source: audioSource
    }

    RowLayout {

        anchors.fill: parent

        Rectangle {
            id: root
            width: 800
            height: 800
            anchors.centerIn: parent
            color: "gray"
            Rectangle {
                property MyGame gameContainer
                property Item playerTank
                property Item aITank
                property var game
                property var tmp

                id:scene
                width: 676
                height: 676
                color: "black"
                anchors.centerIn: parent
                Component.onCompleted: {
                    var cmpnt = Qt.createComponent("Game.qml")
                    if (cmpnt.status === Component.Ready) {
                        game = cmpnt.createObject(scene);
                        gameContainer = game.gamedata
                        console.log(gameContainer.qty)
                        for (var i = 0; i < game.gamedata.qty ; i++) {
                            switch (game.gamedata.getItem(i).type) {
                            case ShapeType.Empty:
                                break;
                            case ShapeType.Brick:
                                game.gamedata.getItem(i).source = "qrc:/img/Brick_quarter.png";
                                var Brick = Qt.createComponent("Cell.qml");
                                if (Brick.status === Component.Ready) {
                                    Brick.createObject(scene,{"cell": game.gamedata.getItem(i)});
                                }
                                break;
                            case ShapeType.Concrete:
                                game.gamedata.getItem(i).source = "qrc:/img/Сoncrete_quarter.png";
                                var Сoncrete = Qt.createComponent("Cell.qml");
                                if (Сoncrete.status === Component.Ready){
                                    Сoncrete.createObject(scene, {"cell": game.gamedata.getItem(i)});
                                }
                                break;
                            case ShapeType.AiTank:
                                game.gamedata.getItem(i).source = "qrc:/img/EnemyUp.png";
                                var aiTank = Qt.createComponent("aiTank.qml");
                                if (aiTank.status === Component.Ready) {
                                    aITank = aiTank.createObject(scene, {"cell": game.gamedata.getItem(i)});
                                }
                                break;
                            case ShapeType.PlayerTank:
                                game.gamedata.getItem(i).source = "qrc:/img/PlayerUp.png";
                                var userTankCmpnt = Qt.createComponent("UserTank.qml");
                                if(userTankCmpnt.status === Component.Ready) {
                                    playerTank = userTankCmpnt.createObject(scene, {"cell": game.gamedata.getItem(i), "game" : game.gamedata});
                                }
                                break;
                            case ShapeType.Base:
                                game.gamedata.getItem(i).source = "qrc:/img/base.png";
                                var Base = Qt.createComponent("Base.qml");
                                if (Base.status === Component.Ready) {
                                    Base.createObject(scene, {"cell": game.gamedata.getItem(i)});
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
                            bulletCmpnt.createObject(scene,{"cell" : bullet})
                        }
                        audioPlayer.audioSource = "./music/shoot.wav";
                        audioPlayer.play();
                    }
                }
                Connections {
                    target: scene.aITank
                    onShooting: {
                        var bullet = scene.gameContainer.shoot(scene.aITank.cell, 0)
                        var bullettCmpnt = Qt.createComponent("Bullet.qml");
                        if (bullettCmpnt.status === Component.Ready) {
                            bullettCmpnt.createObject(scene,{"cell": bullet})
                        }
                    }
                }
                Connections {
                    target: scene.gameContainer
                    onCreatePlayer: {
                        audioPlayer.audioSource = "./music/fexplosion.wav"
                        var playerTank = scene.gameContainer.createPlayerTank();
                        playerTank .source = "qrc:/img/PlayerUp.png";
                        var userTankCmpnt = Qt.createComponent("UserTank.qml");
                        if (userTankCmpnt.status === Component.Ready) {
                            scene.playerTank = userTankCmpnt.createObject(scene, {"cell": playerTank, "focus": true});
                        }
                    }
                }
                Connections {
                    target: scene.gameContainer
                    onCreateEnemy: {
                        var enemyTank= scene.gameContainer.createEnemyTank();
                        enemyTank.source = "qrc:/img/EnemyUp.png";
                        var aiTank = Qt.createComponent("aiTank.qml");
                        if (aiTank.status === Component.Ready) {
                            scene.aITank = aiTank.createObject(scene, {"cell": enemyTank});
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
                        console.log("Game over! bye");
                        audioPlayer.audioSource = "./music/gameover.mp3";
                        audioPlayer.play();

                    }
                }
                Connections {
                    target: scene.playerTank
                    onUp: {
                        scene.gameContainer.move(scene.playerTank.cell, Direction.Up);
                    }
                    onRight: {
                        scene.gameContainer.move(scene.playerTank.cell, Direction.Right);
                    }
                    onDown: {
                        scene.gameContainer.move(scene.playerTank.cell, Direction.Down);
                    }
                    onLeft: {
                        scene.gameContainer.move(scene.playerTank.cell, Direction.Left);
                    }
                }
            }
        }
        Rectangle {
            color: "gray"
            height: 676
            width: 100
            Rectangle {
                id: tanksLeft
                width: 100
                height: 100
                color:"green"

                Text {
                    text: "Enemy left" + scene.gameContainer.lifes  + "\n" + scene.gameContainer.tanksOnLevel;
                    font.family: "Helvetica"
                    font.pointSize: 16
                }
            }
        }
    }
}





