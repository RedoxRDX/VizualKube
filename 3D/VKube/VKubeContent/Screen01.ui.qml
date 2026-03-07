

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import QtQuick3D
import QtQuick3D.Effects
import QtQuick3D.Helpers
import VKube

Rectangle {
    width: Constants.width
    height: 600
    color: "#000000"

    View3D {
        id: extendedView3D
        anchors.fill: parent
        anchors.leftMargin: 0
        anchors.rightMargin: 0
        anchors.topMargin: 140
        anchors.bottomMargin: -140

        environment: sceneEnvironment

        ExtendedSceneEnvironment {
            id: sceneEnvironment
            antialiasingMode: SceneEnvironment.MSAA
            antialiasingQuality: SceneEnvironment.High
        }

        Node {
            id: scene
            DirectionalLight {
                id: directionalLight
            }

            PerspectiveCamera {
                id: sceneCamera
                z: 350
            }

            Model {
                id: cubeModel
                x: 0
                y: 0
                eulerRotation.y: 0
                eulerRotation.x: 0
                materials: defaultMaterial
                source: "#Cube"
                eulerRotation.z: 0
                z: 0
            }
        }

        Slider {
            id: slider
            x: 0
            y: -67
            width: 155
            height: 48
            value: 0.5

            Text {
                id: text1
                x: 8
                y: 0
                color: "#ffffff"
                text: qsTr("Cube angle")
                font.pixelSize: 12
                rotation: -0.045
            }
        }
    }

    Item {
        id: __materialLibrary__
        PrincipledMaterial {
            id: defaultMaterial
            objectName: "Default Material"
            baseColor: "#ffffff"
        }
    }

    Text {
        color: "#ffffff"
        text: qsTr("VKube3D")
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 8
        anchors.horizontalCenterOffset: -167
        font.family: Constants.font.family
    }
}

/*##^##
Designer {
    D{i:0}D{i:3;cameraSpeed3d:40;cameraSpeed3dMultiplier:1}
}
##^##*/

