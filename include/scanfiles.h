#ifndef SCAN_FILES_H
#define SCAN_FILES_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <QDir>

#include "includespdlog.h"


QVector<QString> static scanAllImages(QString path)
{
    QVector<QString> temp;
    QDir directory(path);
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.png" << "*.PNG" << "*.JPG", QDir::Files);

    foreach(QString filename, images)
    {
        temp.push_back(filename);
    }
    return temp;
}

QVector<QString> static scanAllImagesNames(QString path)
{
    QVector<QString> temp;
    QDir directory(path);
    QStringList images = directory.entryList(QStringList() << "*.jpg" << "*.png" << "*.PNG" << "*.JPG", QDir::Files);

    foreach(QString filename, images)
    {
        QStringList sl = filename.split(".");
        temp.push_back(sl[0]);
    }
    return temp;
}

QVector<QString> static scanAllVideo(QString path)
{
    QVector<QString> temp;
    QDir directory(path);
    QStringList images = directory.entryList(QStringList() << "*.MP4" << "*.mp4", QDir::Files);

    foreach(QString filename, images)
    {
        QStringList sl = filename.split(".");
        temp.push_back(sl[0]);
    }
    return temp;
}

#endif // SCAN_FILES_H
