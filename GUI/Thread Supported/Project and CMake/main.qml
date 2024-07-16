import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtLocation 5.15
import QtPositioning 5.15

Window {
    width: 1000
    height: 640
    visible: true
    title: qsTr("Home Control Terminal")
    color: "#4f5252"
    property var now: new Date()
    Image {
        width: parent.width
        height: parent.height
        source: "./Images/bedroom.jpg"
        opacity: 0.6
    }

    Rectangle {
        id: rec1
        width: parent.width / 5
        height: parent.height / 5
        color: "#1f1f1f"
        radius: 20
        opacity: 0.5
        border.color: "black"
        border.width: 2
        anchors {
            left: parent.left
            bottom: parent.bottom
            leftMargin: 40
            bottomMargin: 20
        }
    }

    Image {
        id: spotlogo
        source: "./Images/spotify.png"
        width: 50
        height: 50
        anchors {
            left: rec1.left
            leftMargin: 10
            bottom: rec1.bottom
            bottomMargin: 60
        }
    }

    Rectangle {
        id: previousButtonBackground
        width: 30
        height: 30
        color: "transparent"
        radius: 20
        anchors {
            left: spotlogo.right
            leftMargin: 10
            bottom: spotlogo.bottom
            bottomMargin: 15
        }
        border.color: "transparent"
        border.width: 2

        Image {
            id: previousButton
            source: "./Images/backward.png"
            width: parent.width / 2
            height: parent.height / 2
            anchors.centerIn: parent
        }
        MouseArea {
            id: previousMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                previousButtonBackground.color = "#CCCCCC"
            } // Highlight color
            onExited: {
                previousButtonBackground.color = "transparent"
            }
            onClicked: {
                controller.sendCommand("$11,0#") // Previous command
            }
        }
    }

    Rectangle {
        id: playPauseButtonBackground
        width: 30
        height: 30
        color: "transparent"
        radius: 20
        anchors {
            left: previousButtonBackground.right
            leftMargin: 10
            bottom: previousButtonBackground.bottom
        }
        border.color: "transparent"
        border.width: 2

        Image {
            id: playPauseButton
            property bool isPlaying: false
            source: playPauseButton.isPlaying ? "./Images/pause.png" : "./Images/play.png"
            width: parent.width / 2
            height: parent.height / 2
            anchors.centerIn: parent
        }
        MouseArea {
            id: playPauseMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                playPauseButtonBackground.color = "#CCCCCC"
            } // Highlight color
            onExited: {
                playPauseButtonBackground.color = "transparent"
            }
            onClicked: {
                playPauseButton.isPlaying = !playPauseButton.isPlaying
                if (playPauseButton.isPlaying) {
                    controller.sendCommand("$10,1#") // Play command
                } else {
                    controller.sendCommand("$10,0#") // Pause command
                }
            }
        }
    }

    Rectangle {
        id: plusbut
        width: 30
        height: 30
        color: "transparent"
        radius: 20
        anchors {
            left: rec1.left
            leftMargin: 20
            bottom: rec1.bottom
            bottomMargin: 20
        }
        border.color: "transparent"
        border.width: 2

        Image {
            id: plusbutimg
            source: "./Images/plus.png"
            width: parent.width / 2
            height: parent.height / 2
            anchors.centerIn: parent
        }
        MouseArea {
            id: plusbutmouse
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                plusbut.color = "#CCCCCC"
            } // Highlight color
            onExited: {
                plusbut.color = "transparent"
            }
            onClicked: {
                controller.sendCommand("$12,1#") // Play command
                controller.incrementVol()
            }
        }
    }

    Rectangle {
        id: volbut
        width: 60
        height: 60
        color: "transparent"
        radius: 20
        anchors {
            left: plusbut.right
            leftMargin: 24
            bottom: rec1.bottom
            bottomMargin: 10
        }
        border.color: "transparent"
        border.width: 2

        Image {
            id: volbutimg
            source: {
                if (controller.volume === 0) {
                    return "./Images/0.png"
                } else if (controller.volume >= 1 && controller.volume <= 10) {
                    return "./Images/1.png"
                } else if (controller.volume >= 11 && controller.volume <= 20) {
                    return "./Images/2.png"
                } else {
                    return "./Images/3.png"
                }
            }
            width: parent.width / 2
            height: parent.height / 2
            anchors.centerIn: parent
        }
    }
    Rectangle {
        id: minusbut
        width: 30
        height: 30
        color: "transparent"
        radius: 20
        anchors {
            right: rec1.right
            rightMargin: 20
            bottom: rec1.bottom
            bottomMargin: 20
        }
        border.color: "transparent"
        border.width: 2

        Image {
            id: minusbutimg
            source: "./Images/minus.png"
            width: parent.width / 2
            height: parent.height / 2
            anchors.centerIn: parent
        }
        MouseArea {
            id: minusbutmouse
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                minusbut.color = "#CCCCCC"
            } // Highlight color
            onExited: {
                minusbut.color = "transparent"
            }
            onClicked: {
                controller.sendCommand("$12,-1#") // Play command
                controller.decrementVol()
            }
        }
    }

    Rectangle {
        id: nextButtonBackground
        width: 30
        height: 30
        color: "transparent"
        radius: 20
        anchors {
            left: playPauseButtonBackground.right
            leftMargin: 10
            bottom: playPauseButtonBackground.bottom
        }

        border.color: "transparent"
        border.width: 2

        Image {
            id: nextButton
            source: "./Images/forward.png"
            width: parent.width / 2
            height: parent.height / 2
            anchors.centerIn: parent
        }
        MouseArea {
            id: nextMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                nextButtonBackground.color = "#CCCCCC"
            } // Highlight color
            onExited: {
                nextButtonBackground.color = "transparent"
            }

            onClicked: {

                controller.sendCommand("$11,1#") // Next command
            }
        }
    }
    Rectangle {
        id: rec2
        width: parent.width / 5
        height: parent.height / 2
        color: "#1f1f1f"
        radius: 20
        opacity: 0.5

        border.color: "black"
        border.width: 2

        anchors {
            left: rec1.right
            bottom: parent.bottom
            leftMargin: 40
            bottomMargin: 20
        }
    }

    Column {
        width: rec2.width
        height: rec2.height
        spacing: 10
        anchors.centerIn: rec2

        Image {
            id: doorbellIcon
            source: "./Images/door-bell.png" // Path to your doorbell icon
            width: 60
            height: 60
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            spacing: 5
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                text: "Doorbell 1"
                color: "white"
                font.pointSize: 16
            }

            Text {
                id: doorbellStatus
                text: controller.doorBill === 1 ? "Active" : "Inactive"
                color: controller.doorBill === 1 ? "green" : "red"
                font.pointSize: 16
            }
        }

        Image {
            id: gateIcon
            source: "./Images/gate.png" // Path to your doorbell icon
            width: 50
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row {
            spacing: 5
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                text: "Gate 1"
                color: "white"
                font.pointSize: 16
            }

            Text {
                id: gateStatus
                text: controller.gate === 1 ? "Open" : "Closed"
                color: controller.gate === 1 ? "green" : "red"
                font.pointSize: 16
            }
        }

        Connections {
            target: controller
            onDoorBillChanged: {
                doorbellStatus.text = controller.doorBill === 1 ? "Active" : "Inactive"
                doorbellStatus.color = controller.doorBill === 1 ? "green" : "red"
            }
            onGateChanged: {
                gateStatus.text = controller.gate === 1 ? "Open" : "Closed"
                gateStatus.color = controller.gate === 1 ? "green" : "red"
            }
        }

        Row {
            spacing: 50
            anchors.horizontalCenter: parent.horizontalCenter

            Switch {
                id: garageSwitch
                checked: false

                onCheckedChanged: {
                    if (checked) {
                        gateTimer.start()
                        garageStatus.text = "Garage Opening"
                        garageStatus.color = "yellow"
                    } else {
                        gateTimer.start()
                        garageStatus.text = "Garage Closing"
                        garageStatus.color = "yellow"
                    }
                }
            }
        }
        Row {
            spacing: 50
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: garageStatus
                text: "Garage Closed"
                color: "red"
                font.pointSize: 16
            }
        }

        Timer {
            id: gateTimer
            interval: 1000
            repeat: true
            property int seconds: 0
            onTriggered: {
                if (garageSwitch.checked) {
                    if (seconds < 4) {
                        garageStatus.text += "."
                        seconds++
                    } else {
                        garageStatus.text = "Garage Open"
                        garageStatus.color = "green"
                        controller.sendCommand("$9,1#")
                        gateTimer.stop()
                        seconds = 0
                    }
                } else {
                    if (seconds < 4) {
                        garageStatus.text += "."
                        seconds++
                    } else {
                        garageStatus.text = "Garage Closed"
                        garageStatus.color = "red"
                        controller.sendCommand("$9,0#")
                        gateTimer.stop()
                        seconds = 0
                    }
                }
            }
        }
    }

    Item {
        id: rec3
        width: parent.width / 7
        height: parent.height

        // color: "#1f1f1f"
        // radius: 20 // Adjust this value to control the roundness of the corners
        // opacity: 0.5

        // border.color: "black" // Set the border color
        // border.width: 0 // Set the border width
        anchors {
            right: parent.right
            bottom: parent.bottom
            top: parent.top
            topMargin: 20
            rightMargin: 40
            bottomMargin: 20
        }

        Rectangle {
            id: recbot
            width: parent.width
            height: parent.height / 3
            opacity: 0.5
            color: "#1f1f1f"
            radius: 20 // Adjust this value to control the roundness of the corners

            border.color: "black" // Set the border color
            border.width: 2 // Set the border width

            anchors {
                bottom: parent.bottom
            }
        }
        Text {
            id: carbontexts
            font.pixelSize: 60
            color: "white"
            font.family: "Helvetica"
            text: "Co"

            anchors {
                top: recbot.top
                topMargin: 5
                horizontalCenter: recbot.horizontalCenter
            }
        }
        Text {
            id: carbonmes
            font.pixelSize: 15
            color: "white"
            font.family: "Helvetica"
            text: "ppm"

            anchors {
                top: carbontexts.bottom
                topMargin: 5
                horizontalCenter: carbontexts.horizontalCenter
            }
        }
        Text {
            id: carbonval
            font.pixelSize: 60
            color: "white"
            font.family: "Helvetica"
            text: controller.carbon

            anchors {
                horizontalCenter: recbot.horizontalCenter
                bottom: recbot.bottom
                bottomMargin: 5
            }
        }

        Rectangle {
            id: recmid
            width: parent.width
            height: parent.height / 3

            color: "#1f1f1f"
            radius: 20 // Adjust this value to control the roundness of the corners
            opacity: 0.5

            border.color: "black" // Set the border color
            border.width: 2 // Set the border width

            anchors {
                bottom: recbot.top
            }
        }
        Text {
            id: humtexts
            font.pixelSize: 30
            color: "white"
            font.family: "Helvetica"
            text: "Humidity"

            anchors {
                top: recmid.top
                topMargin: 5
                horizontalCenter: recmid.horizontalCenter
            }
        }
        Text {
            id: hummes
            font.pixelSize: 15
            color: "white"
            font.family: "Helvetica"
            text: "g/m³"

            anchors {
                top: humtexts.bottom
                topMargin: 5
                horizontalCenter: humtexts.horizontalCenter
            }
        }
        Text {
            id: humval
            font.pixelSize: 60
            color: "white"
            font.family: "Helvetica"
            text: controller.humidity

            anchors {
                horizontalCenter: recmid.horizontalCenter
                bottom: recmid.bottom
                bottomMargin: 5
            }
        }
        Rectangle {
            id: rectop
            width: parent.width
            height: parent.height / 3

            color: "#1f1f1f"
            radius: 20 // Adjust this value to control the roundness of the corners
            opacity: 0.5

            border.color: "black" // Set the border color
            border.width: 2 // Set the border width

            anchors {
                bottom: recmid.top
            }
        }

        Text {
            id: temptexts
            font.pixelSize: 23
            color: "white"
            font.family: "Helvetica"
            text: "Temperature"

            anchors {
                top: rectop.top
                topMargin: 5
                horizontalCenter: rectop.horizontalCenter
            }
        }
        Text {
            id: tempmes
            font.pixelSize: 15
            color: "white"
            font.family: "Helvetica"
            text: "°C"

            anchors {
                top: temptexts.bottom
                topMargin: 5
                horizontalCenter: temptexts.horizontalCenter
            }
        }
        Text {
            id: tempval
            font.pixelSize: 60
            color: "white"
            font.family: "Helvetica"
            text: controller.temperature

            anchors {
                horizontalCenter: rectop.horizontalCenter
                bottom: rectop.bottom
                bottomMargin: 5
            }
        }

        Text {
            id: serverstat
            font.pixelSize: 20
            color: "white"
            font.family: "Helvetica"
            text: "Server Status : "

            anchors {
                right: rectop.left
                rightMargin: 60
                top: rectop.top
            }
        }

        Text {
            id: serverstatval
            font.pixelSize: 20
            color: "#05f040"
            font.family: "Helvetica"
            text: "Online"

            anchors {
                left: serverstat.right
                top: rectop.top
            }
        }

        Text {
            id: nodestat
            font.pixelSize: 20
            color: "white"
            font.family: "Helvetica"
            text: "Nodes Active : "

            anchors {
                right: rectop.left
                rightMargin: 63
                top: serverstatval.bottom
                topMargin: 10
            }
        }

        Text {
            id: nodestatval
            font.pixelSize: 20
            color: "#05f040"
            font.family: "Helvetica"
            text: controller.clientsCount.toString(
                      ) // Bind to clientsCount property

            anchors {
                left: nodestat.right
                top: serverstatval.bottom
                topMargin: 10
            }
        }
    }

    Item {
        id: rec4
        height: parent.height / 2

        // color: "#1f1f1f"
        // radius: 20 // Adjust this value to control the roundness of the corners
        // opacity: 0.5

        // border.color: "black" // Set the border color
        // border.width: 2 // Set the border width
        anchors {
            left: rec2.right
            bottom: parent.bottom
            right: rec3.left
            leftMargin: 40
            rightMargin: 40
            bottomMargin: 20
        }

        Rectangle {
            id: slidebot
            width: parent.width
            height: parent.height / 6
            opacity: 0.5
            color: "#1f1f1f"
            radius: 20 // Adjust this value to control the roundness of the corners

            border.color: "black" // Set the border color
            border.width: 2 // Set the border width

            anchors {
                bottom: parent.bottom
            }

            Slider {
                id: airConSlider
                width: parent.width / 1.5
                from: 0
                to: 100
                value: 0
                stepSize: 1

                onValueChanged: {
                    console.log("Air Conditioner slider value:", value)
                    controller.sendCommand("$6," + value + "#")
                }
            }
        }

        Image {
            source: "./Images/fan.png"
            width: slidebot.height / 1.5
            height: slidebot.height / 1.5
            anchors.verticalCenter: slidebot.verticalCenter
            anchors.right: slidebot.right
            anchors.rightMargin: 10
        }

        Rectangle {
            id: slidemid
            width: parent.width
            height: parent.height / 6

            color: "#1f1f1f"
            radius: 20 // Adjust this value to control the roundness of the corners
            opacity: 0.5

            border.color: "black" // Set the border color
            border.width: 2 // Set the border width

            anchors {
                centerIn: parent
            }

            Slider {
                id: brightnessSlider
                width: parent.width / 1.5
                from: 0
                to: 100
                value: 0
                stepSize: 1

                onValueChanged: {
                    console.log("Brightness slider value:", value)
                    controller.sendCommand("$7," + value + "#")
                }
            }
        }

        Image {
            source: "./Images/brightness.png"
            width: slidemid.height / 1.5
            height: slidemid.height / 1.5
            anchors.verticalCenter: slidemid.verticalCenter
            anchors.right: slidemid.right
            anchors.rightMargin: 10
        }

        Rectangle {
            id: slidetop
            width: parent.width
            height: parent.height / 6

            color: "#1f1f1f"
            radius: 20 // Adjust this value to control the roundness of the corners
            opacity: 0.5

            border.color: "black" // Set the border color
            border.width: 2 // Set the border width

            anchors {
                top: parent.top
            }
            Slider {
                id: fanSlider
                width: parent.width / 1.5
                from: 0
                to: 100
                value: 0
                stepSize: 1

                onValueChanged: {
                    console.log("Fan slider value:", value)
                    controller.sendCommand("$8," + value + "#")
                }
            }
        }
        Image {
            source: "./Images/air-conditioner.png"
            width: slidetop.height / 1.5
            height: slidetop.height / 1.5
            anchors.verticalCenter: slidetop.verticalCenter
            anchors.right: slidetop.right
            anchors.rightMargin: 10
        }
    }

    // Clock display
    Text {
        id: clockText
        font.pixelSize: 100
        color: "white"
        font.family: "Helvetica"
        text: getTime()

        anchors {
            left: parent.left
            top: parent.top
            leftMargin: 40
            topMargin: 40
        }
    }

    Text {
        id: secText
        font.pixelSize: 20
        color: "white"
        font.family: "Helvetica"
        text: ":" + pad(now.getSeconds())

        anchors {
            left: clockText.right
            top: parent.top
            leftMargin: 5
            topMargin: 120
        }
    }

    Timer {
        interval: 1000 // 1 second
        running: true
        repeat: true
        onTriggered: {
            now = new Date()
            clockText.text = getTime()
            secText.text = ":" + pad(now.getSeconds())
        }
    }

    // Function to get current time
    function getTime() {
        var hours = now.getHours()
        var minutes = now.getMinutes()
        return pad(hours) + ":" + pad(minutes)
    }

    // Function to pad single digits with a leading zero
    function pad(number) {
        return (number < 10) ? "0" + number : number
    }
}
