import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import CalcClass 1.0

Window {
    visible: true
    width: 370
    height: 200
    color: "lightgrey"

    Calculator {
        id: objCalc
    }

    GroupBox {
        title: "Choose operation:"
        x: 200
        y: 20

        Column {
            spacing: 5
            ExclusiveGroup { id: tabPositionGroup }
            RadioButton {
                id: sum
                text: "sum"
                checked: true
                exclusiveGroup: tabPositionGroup
            }
            RadioButton {
                id: sub
                text: "substraction"
                exclusiveGroup: tabPositionGroup
            }
            RadioButton {
                id: mul
                text: "multiplication"
                exclusiveGroup: tabPositionGroup
            }
            RadioButton {
                id: div
                text: "division"
                exclusiveGroup: tabPositionGroup
            }
        }
    }

    TextField {
        id: num1
        x: 50
        y: 35
        placeholderText: qsTr("Enter number 1")
    }
    TextField {
        id: num2
        x: 50
        y: 70
        placeholderText: qsTr("Enter number 2")
    }

    Label {
        x: 50
        y: 105
        font.pixelSize: 14
        text: "Result: "
    }

    Label {
        id: res
        x: 110
        y: 105
        font.pixelSize: 14
        text: "???"
    }

    Button {
        width: 80
        height: 35
        x: Window.width / 2 - width / 2
        y: 145
        text: "Calculate!"
        onClicked: {
            var oper
            if (sum.checked)
                oper = "sum"
            if (sub.checked)
                oper = "sub"
            if (mul.checked)
                oper = "mul"
            if (div.checked)
                oper = "div"
            objCalc.calcul(num1.text, num2.text, oper)
            res.text = objCalc.getRes()
        }
    }
}
