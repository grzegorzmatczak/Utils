#ifndef FOLDER_MANAGEMENT_H
#define FOLDER_MANAGEMENT_H

#include <QDir>
#include <QObject>

#include "includespdlog.h"


static bool createFolder(QString name)
{
	#ifdef DEBUG
	Logger->debug("FolderManagement::checkAndCreateFolder({})",name.toStdString());
	#endif
	
	if(!QDir(name).exists())
	{
		if (!QDir().mkdir(name))
		{
			return true;
		}
	}
	return false;
}

static void checkAndCreateFolder(QString name)
{
	if(createFolder(name))
	{
		Logger->error("createFolder can not create:{}", name.toStdString());
	}
}

class FolderManagement : public QObject {
	Q_OBJECT
	public:
		explicit FolderManagement();
		
	signals:

	public slots:

	private:

};

#endif // FOLDER_MANAGEMENT_H
