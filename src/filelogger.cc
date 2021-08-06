#include "filelogger.h"

//#define DEBUG

FileLogger::FileLogger()
{
	m_file = new QFile("temp.json");
}

void FileLogger::onConfigure(QString name)
{
	#ifdef DEBUG
	Logger->debug("FileLogger::configure() ");
	#endif
	if (name == "")
	{
		Logger->error("FileLogger::configure() filename not set");
		name = "error";
	}

	m_name = name;
	m_file->setFileName(name);
	#ifdef DEBUG
	Logger->debug("FileLogger::configure() <{}>", name.toStdString().c_str());
	#endif
}

void FileLogger::onAppendFileLogger(QStringList list)
{
	#ifdef DEBUG
	Logger->debug("FileLogger::appendFileLogger() ");
	#endif
	FileLogger::onAppend(list, m_file);
}


void FileLogger::onAppend(QStringList list, QFile* file)
{
	#ifdef DEBUG
	Logger->debug("FileLogger::Append() clean:");
	#endif
	if (file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
	{
		QTextStream stream(file);
		for (int i = 0; i < list.size(); ++i)
		{
			stream << list.at(i).toLocal8Bit().constData();
		}
		file->close();
	}
	#ifdef DEBUG
	Logger->debug("FileLogger::Append() clean: done");
	#endif
}

void FileLogger::onClear()
{
	Logger->error("FileLogger::clear()");
	m_file->remove();
	if (m_file->open(QIODevice::WriteOnly | QIODevice::Text))
	{
		m_file->close();
	}
}

void FileLogger::onLogJsonBest(QJsonObject json)
{
	#ifdef DEBUG
	qDebug() << "FileLogger::logJsonBest:" << json;
	#endif
	auto test = QJsonDocument(json).toJson(QJsonDocument::Indented);
	m_file->open(QFile::WriteOnly);
	m_file->write(test);
	m_file->close();
}
