#include "settings.h"

#include <QCoreApplication>
#include <QDir>

Settings::Settings(QObject *parent)
	: QObject{parent}
{
}

QString Settings::imagePath() const
{
	return Settings::dataPath() + QDir::separator() + "img";
}

QString Settings::dataPath()
{
	QDir appDir = QCoreApplication::applicationDirPath();

#ifdef QT_DEBUG
	appDir.cdUp();
#endif

	QDir dataDir = appDir.path() + QDir::separator() + "data";
	if (!dataDir.exists())
		dataDir.mkpath(".");

	return dataDir.path();
}
