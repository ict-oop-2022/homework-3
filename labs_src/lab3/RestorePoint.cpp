#include "RestorePoint.h"

RestorePoint::RestorePoint(vector<JobObject> files, int restorePointVersion) {
    if(files.empty()) throw invalid_argument("Wrong input for RestorePoint");
    if(restorePointVersion <= 0) restorePointVersion = 1;
    vector <Storage> storagesTemp;
    for (int i = 0; i < files.size(); i++) {
        Storage newStorage = Storage(files[i]);
        storagesTemp.push_back(newStorage);
        delete &newStorage;
        if(!storageVersionControl[files[i].getName()]) storageVersionControl[files[i].getName()] = 1;
        else storageVersionControl[files[i].getName()]++;
    }
    this->storages = storagesTemp;
    this->restorePointName = storages[0].getStorageName() + "_" + to_string(restorePointVersion);
    this->restorePointVersion = restorePointVersion;
}

RestorePoint::RestorePoint(Storage storage, int restorePointVersion) {
    if(restorePointVersion <= 0) restorePointVersion = 1;
    this->storages.push_back(storage);
    this->storageVersionControl[storage.getStorageName()] = 1;
    this->restorePointName = storage.getStorageName() + "_" + to_string(restorePointVersion);
    this->restorePointVersion = restorePointVersion;
}

void RestorePoint::addStorage(Storage storage) {
    storages.push_back(storage);
    if(!storageVersionControl[storage.getStorageName()]) storageVersionControl[storage.getStorageName()] = 1;
    else storageVersionControl[storage.getName()]++;
}

void RestorePoint::deleteStorage(Storage storage) {
    if(!storageVersionControl[storage.getStorageName()]) throw invalid_argument("Wrong input for deleting storage");
    else {
        storageVersionControl[storage.getStorageName()]--;
        for(int i = 0; i < storages.size(); i++) {
            if(storages[i] == storage) {
                storages.erase(storages.begin() + i);
                break;
            }
        }
    }
}

void RestorePoint::operator=(RestorePoint &other) {
    this->restorePointName = other.getRestorePointName();
    this->restorePointVersion = other.getRestorePointVersion();
    this->storages = other.getStorages();
    delete [] &storageVersionControl;
    this->storageVersionControl = other.getStorageVCFull();
}

vector <Storage> RestorePoint::getStorages() { return storages; }

string RestorePoint::getRestorePointName() { return restorePointName; }

int RestorePoint::getRestorePointVersion() { return restorePointVersion; }

int RestorePoint::getStorageVC(string storageName) { return storageVersionControl[storageName]; }

map <string, int> RestorePoint::getStorageVCFull() { return storageVersionControl; }