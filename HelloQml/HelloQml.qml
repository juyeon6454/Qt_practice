import QtQuick 2.0


//Rectangle {//파스칼 표기법 (요소) 카멜 표기법 (속성) qml은 값을 넣을때 = 이 아닌 :을 넣는다
//    id:page
//    width: 200
//    height: 200
//    color:"lightgray"
//    //visible: true
//    //title: qsTr("Hello World")
//    Text{
//        id : helloText
//        text:"Hello world!"
//        x : 66
//        y : 93
//        color : "blue"
//        anchors.horizontalCenter: page.horizontalCenter
//        font.pointSize: 24;font.bold:true
//       // text : qsTr("<font color='blue'>Hello, World!</font>")
//       // text : "Hello World"
//    }
//}


Rectangle {

    id:page
    width:200;
    height:200
    color:"lightgray"
    border.color: "black"
    border.width:5
    radius:10

    Text{
        id:helloText
        text:"Hello world"
        x:66
        y:93
        color:"blue"
        anchors.horizontalCenter: page.horizontalCenter
        font{pointSize:24; bold: true}

    }

    Grid{
        id:colorPicker
        x: 4; anchors.bottom:page.bottom; anchors.bottomMargin:4
        rows:2; columns:3; spacing:3

        Cell{cellColor: "red"; onClicked: helloText.color = cellColor}
        Cell{cellColor: "green"; onClicked: helloText.color = cellColor}
        Cell{cellColor: "blue"; onClicked: helloText.color = cellColor}
        Cell{cellColor: "yellow"; onClicked: helloText.color = cellColor}
        Cell{cellColor: "steelblue"; onClicked: helloText.color = cellColor}
        Cell{cellColor: "black"; onClicked: helloText.color = cellColor}


    }
}
