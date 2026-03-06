

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
    height: Constants.height

    color: Constants.backgroundColor

    View3D {
        id: extendedView3D
        anchors.fill: parent

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
                z: -0.25923
            }
        }
    }

    Item {
        id: __materialLibrary__
        PrincipledMaterial {
            id: defaultMaterial
            objectName: "Default Material"
            baseColor: "#4aee45"
        }
    }

    Text {
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
    D{i:0}D{i:3;cameraSpeed3d:25;cameraSpeed3dMultiplier:1}
}
##^##*/

