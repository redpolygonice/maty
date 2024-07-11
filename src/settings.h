#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSharedPointer>

class Settings : public QObject
{
	friend class QSharedPointer<Settings>;

	Q_OBJECT

private:
	explicit Settings(QObject *parent = nullptr);

public:
	Q_INVOKABLE QString imagePath() const;

public:
	static QString dataPath();
};

using SettingsPtr = QSharedPointer<Settings>;

inline SettingsPtr GetSettings()
{
	static SettingsPtr settings = nullptr;
	if (settings == nullptr)
		settings = QSharedPointer<Settings>::create();
	return settings;
}

#endif // SETTINGS_H
