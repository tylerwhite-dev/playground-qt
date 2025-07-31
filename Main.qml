import QtQuick
import QtQuick.Controls
import com.example.models
import Qt.labs.platform
import QtQuick.Layouts

Window {
    visible: true
    width: 500
    height: 400
    title: "My Application"

    minimumHeight: 400
    minimumWidth: 500

    MyListModel {
        id: myModel
    }

    RowLayout {

        anchors.fill: parent

        ColumnLayout {
            Layout.alignment: Qt.AlignVCenter

            spacing: 10

            Text {
                Layout.alignment: Qt.AlignCenter

                text: "First Item"
                font.pointSize: 20
            }

            ListView {
                Layout.alignment: Qt.AlignCenter

                Layout.minimumHeight: 100
                Layout.fillWidth: true

                model: myModel
                delegate: Text {
                    text: model.display
                }
            }

            Rectangle {
                Layout.alignment: Qt.AlignCenter

                width: 150
                height: 100
                color: "blue"
            }

            Button {
                Layout.alignment: Qt.AlignCenter

                text: "Click Me"
                Layout.fillWidth: true
            }
        }

        ColumnLayout {
            Layout.alignment: Qt.AlignVCenter

            spacing: 10

            Text {
                Layout.alignment: Qt.AlignCenter

                text: "First Item"
                font.pointSize: 20
            }

            ListView {
                Layout.alignment: Qt.AlignCenter

                Layout.minimumHeight: 100
                Layout.fillWidth: true

                model: myModel
                delegate: Text {
                    text: model.display
                }
            }

            Rectangle {
                Layout.alignment: Qt.AlignCenter

                width: 150
                height: 100
                color: "blue"
            }

            Button {
                Layout.alignment: Qt.AlignCenter

                text: "Click Me"
                Layout.fillWidth: true
            }
        }
    }
}
