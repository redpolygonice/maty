import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Button {
	id: control
	Layout.minimumWidth: 70
	Layout.maximumHeight: 35
	Layout.preferredHeight: 35
	Layout.preferredWidth: 70
	Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

	background: Rectangle {
		color: {
			if (mouseArea.containsMouse)
			{
				//opacity = 0.4
				return "#eeeeee"
			}
			else
				return "transparent"
		}
		radius: 7
	}

	contentItem: Text {
		text: control.text
		font.pointSize: 12
		color: "black"
		horizontalAlignment: Text.AlignHCenter
		verticalAlignment: Text.AlignVCenter
		elide: Text.ElideRight
	}

	MouseArea {
		id: mouseArea
		anchors.fill: parent
		hoverEnabled: true
		cursorShape: Qt.PointingHandCursor
		onClicked: control.clicked()
	}
}
