import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15
import "common.js" as Common

ApplicationWindow {
	id: mainWindow
	width: 800
	height: 600
	visible: true
	title: "Maty"

	signal newText(int id, string text)

	Component.onCompleted: {
		x = Screen.width / 2 - width / 2
		y = Screen.height / 2 - height / 2
		historyModel.update(-1)
		contactsModel.update()
	}

	ActionsMenu {
		id: actionsMenu
	}

	CardDlg {
		id: cardDlg
	}

	SplitView {
		id: splitView
		anchors.fill: parent
		orientation: Qt.Horizontal

		handle: Rectangle {
			implicitWidth: 3
			color: Common.backColor1
		}

		ContactsView {
			id: contactsView
			SplitView.fillWidth: false
			SplitView.fillHeight: true
			SplitView.minimumWidth: 200
		}

		Rectangle {
			id: contentRect
			SplitView.fillWidth: true
			SplitView.fillHeight: true
			SplitView.minimumWidth: 200

			Column {
				anchors.fill: parent

				HistoryView {
					id: historyView
					width: mainWindow.contentItem.width - contactsView.width
					height: contactsView.currentIndex === -1 ? mainWindow.contentItem.height :
															   mainWindow.contentItem.height - messageView.height
				}

				MessageView {
					id: messageView
					width: mainWindow.contentItem.width - contactsView.width
				}
			}
		}
	}
}
