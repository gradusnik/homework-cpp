import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Window {
    width: 860
    height: 640
    visible: true
    title: qsTr("Hello World")
    color: "steelblue"
    ColumnLayout {
        id: grid
        //width: parent.width
        Canvas {
            id: screen
            //color: "yellow"
            //ColorSpace
            //available: true
            height: 400
            width: parent.width
        }
        ProgressBar {
            height: 30
            width: 200
        }
        RowLayout {
            id: pannel
            Button {
                text: "play"
                width: pannel.width / 5
            }
            Button {
                text: "pause"
                width: pannel.width / 5
            }
            Button {
                text: "stop"
                width: pannel.width / 5
            }
            Button {
                text: "rewind"
                width: pannel.width / 5
            }
            Button {
                text: "forward"
                width: pannel.width / 5
            }
        }

    }
}
