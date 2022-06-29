#ifndef ICT_HOMEWORK_3_RESTOREPOINT_H
#define ICT_HOMEWORK_3_RESTOREPOINT_H

#include "Storage.h"
#include <map>

class RestorePoint
{
private:
    string restorePointName;
    int restorePointVersion;
    vector <Storage> storages;
    map <string, int> storageVersionControl;

protected:
    int getStorageVC(string storageName);
    map <string, int> getStorageVCFull();

public:
    RestorePoint(vector <JobObject> files, int restorePointVersion);
    RestorePoint(Storage storage, int restorePointVersion);
    void addStorage(Storage storage);
    void deleteStorage(Storage storage);
    void operator=(RestorePoint &other);
    string getRestorePointName();
    vector <Storage> getStorages();
    int getRestorePointVersion();
};

#endif //ICT_HOMEWORK_3_RESTOREPOINT_H
