import QtQuick
import QtQuick.Window
import com.example.models

Window {
    visible: true
    width: 500
    height: 400

    MyListModel {
        id: myModel
    }

    ListView {
        anchors.fill: parent
        model: myModel
        delegate: Text {
            text: model.display
        }
    }
}
