#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "message.h"

#include <QObject>
#include <QThread>
#include <QScopedPointer>
#include <QSharedPointer>

class Dispatcher : public QObject
{
	friend class QSharedPointer<Dispatcher>;

	Q_OBJECT

private:
	std::atomic_bool active_;
	QObject *rootItem_;
	QScopedPointer<QThread> thread_;
	Message message_;

private:
	explicit Dispatcher(QObject *parent = nullptr);

public:
	virtual ~Dispatcher();

signals:
	void newMessage(const QString &text);

private slots:
	void getText(int cid, const QString &text);

public:
	bool start(QObject *rootItem);
	void stop();

private:
	void run();
};

using DispatcherPtr = QSharedPointer<Dispatcher>;

inline DispatcherPtr GetDispatcher()
{
	static DispatcherPtr dispatcher = nullptr;
	if (dispatcher == nullptr)
		dispatcher = QSharedPointer<Dispatcher>::create();
	return dispatcher;
}

#endif // DISPATCHER_H
