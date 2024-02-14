#include "message.h"

Message::Message(QObject *parent)
	: QObject{parent}
{
}

QString Message::generateText()
{
	return "Hello!";
}
