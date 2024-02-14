#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include <QString>

class Message : public QObject
{
	Q_OBJECT

public:
	explicit Message(QObject *parent = nullptr);

public:
	QString generateText();

};

#endif // MESSAGE_H
