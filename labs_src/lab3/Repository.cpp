#include "Repository.h"

Repository::Repository(RestorePoint newRS, string newPath) : restorePoint(newRS) {
    if (!(std::filesystem::exists(path))) {
        cout << "Path " << path << " does not exist." << endl;
        throw invalid_argument("Path does not exist.");
    }
    this->path = newPath;
}

string Repository::getPath() { return path; }

RestorePoint Repository::getRS() { return restorePoint; }

void Repository::setPath(string newPath) {
    if (!(std::filesystem::exists(path))) {
        cout << "Path " << path << " does not exist." << endl;
        throw invalid_argument("Path does not exist.");
    }
    this->path = newPath;
}

void Repository::setRS(RestorePoint newRS) {
    this->restorePoint = newRS;
}

void Repository::addFile(JobObject file) { restorePoint.addStorage(Storage(file)); }

void Repository::addFile(Storage storage) { restorePoint.addStorage(storage); }

void Repository::deleteFile(JobObject file) { restorePoint.deleteStorage(Storage(file)); }

void Repository::deleteFile(Storage storage) { restorePoint.deleteStorage(storage); }

void Repository::saveRS(string zipType) {
    if (zipType == "split") {
        vector <Storage> storages = restorePoint.getStorages();
        for (int i = 0; i < storages.size(); i++) {
            string path_storage = path + storages[i].getStorageName();
            string cmd = "mkdir " + path_storage;
            system(cmd.c_str());
            string storageToSave = storages[i].getStorageName();
            string baseFileName = storageToSave;
            string where_save = path_storage + "\\" + baseFileName;
            copyFile(storageToSave, where_save);
        }
    } else if (zipType == "single") {
        Storage storage = restorePoint.getStorages()[0];
        string pathStorage = path + storage.getStorageName();
        string cmd = "mkdir " + pathStorage;
        system(cmd.c_str());
        vector <Storage> storagesToSave = restorePoint.getStorages();
        for (int i = 0; i < storagesToSave.size(); i++) {
            string baseFilename_ = storagesToSave[i].getStorageName();
            string pathToSave = pathStorage + "\\" + baseFilename_;
            copyFile(baseFilename_, pathToSave);
        }
    }
}

void Repository::copyFile(string pathFrom, string pathTo) {
    string command;
    ifstream inputFile{pathFrom};
    ofstream outputFile{pathTo};
    if (inputFile && outputFile) {
        while (getline(inputFile, command)) outputFile << command << "\n";
        cout << "CopyFile finished \n";
    } else printf("Cannot read file");
    inputFile.close();
    outputFile.close();
}