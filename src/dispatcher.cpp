#include "dispatcher.h"
#include "database.h"

#include <QDebug>
#include <QVariantList>

Dispatcher::Dispatcher(QObject *parent)
	: QObject{parent}
	, active_(false)
	, rootItem_(nullptr)
{
}

Dispatcher::~Dispatcher()
{
	stop();
}

bool Dispatcher::start(QObject *rootItem)
{
	rootItem_ = rootItem;
	active_ = true;
	thread_.reset(QThread::create([this] () { run(); }));
	thread_->start();
	connect(rootItem_, SIGNAL(newText(int,QString)), this, SLOT(getText(int,QString)));
	return true;
}

void Dispatcher::stop()
{
	active_ = false;
	thread_->wait();
}

void Dispatcher::run()
{
	while (active_)
	{
		QThread::msleep(50);
	}
}

void Dispatcher::getText(int cid, const QString &text)
{
	QString answer = message_.generateText();
	QVariantList args{ cid, 1, answer };
	GetDatabase()->appendHistory(args);
}
