#ifndef FILELOGGER_H
#define FILELOGGER_H

#include <QDebug>
#include <QFile>
#include <QObject>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "includespdlog.h"


class FileLogger : public QObject {
	Q_OBJECT
	public:
		explicit FileLogger();

	signals:

	public slots:
		void onConfigure(QString name);
		void onAppendFileLogger(QStringList list);

		void onAppend(QStringList list, QFile* file);
		void onClear();
		void onLogJsonBest(QJsonObject json);

	private:
		QString m_name;
		QFile* m_file;
};

#endif // FILELOGGER_H
