#ifndef ICT_HOMEWORK_3_REPOSITORY_H
#define ICT_HOMEWORK_3_REPOSITORY_H

#include "RestorePoint.h"
#include "Storage.h"
#include <filesystem>
#include <fstream>
#include <iostream>

class Repository
{
private:
    RestorePoint restorePoint;
    string path;

protected:
    void copyFile(string pathFrom, string pathTo);

public:
    Repository(RestorePoint newRS, string newPath);
    void setRS(RestorePoint newRS);
    RestorePoint getRS();
    void setPath(string newPath);
    string getPath();
    void addFile(JobObject file);
    void addFile(Storage storage);
    void deleteFile(JobObject file);
    void deleteFile(Storage storage);
    void saveRS(string zipType);
};

#endif //ICT_HOMEWORK_3_REPOSITORY_H
