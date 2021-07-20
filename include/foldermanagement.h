#ifndef FOLDER_MANAGEMENT_H
#define FOLDER_MANAGEMENT_H

#include <QDir>
#include <QObject>

#include "includespdlog.h"


static bool checkAndCreateFolder(QString name)
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

class FolderManagement : public QObject {
	Q_OBJECT
	public:
		explicit FolderManagement();
		
	signals:

	public slots:

	private:

};

#endif // FOLDER_MANAGEMENT_H
