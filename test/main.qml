﻿import QtQuick 2.0
import QtQuick.Window 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    
    MouseArea{
        anchors.fill: parent;
        onClicked: {
            Interface.test();
        }
    }
}
