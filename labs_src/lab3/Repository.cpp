#include "Repository.h"

FileSys::~FileSys() {}

std::vector<Storage *> RealFileSys::save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const {

  std::string newPath;
    std::string cp;
    std::string mkdir;
    std::vector<Storage *> storage;

    for (int i = 0; i < listOfFiles.size(); i++) {
        if (type == "Single storage") {
            newPath = path;
            newPath.append(listOfFiles[i]->getName()).append(name);
        } else if (type == "Split storage") {
            newPath = path;
            newPath.append(std::to_string(i) + "/").append(listOfFiles[i]->getName()).append(name);
            mkdir = "mkdir " + path + std::to_string(i) + "/";
            system(mkdir.c_str());
        }
        cp = "cp " + listOfFiles[i]->getPath() + " " + newPath;
        system(cp.c_str());
        storage.push_back(new Storage(newPath));
    }
    return storage;
}

std::vector<Storage *> MockFileSys::save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) const {
    std::string newPath;
    std::vector<Storage *> storage;

    for (int i = 0; i < listOfFiles.size(); i++) {
        if (type == "Single storage") {
            newPath = path.append(listOfFiles[i]->getName()).append(name);
        } else if (type == "Split storage") {
            newPath = path.append(std::to_string(i) + "/").append(listOfFiles[i]->getName()).append(name);
        }
        storage.push_back(new Storage(newPath));
    }
    return storage;
}

Repository::Repository(FileSys *fileSys) : fileSys(fileSys) {}

std::vector<Storage *> Repository::save(std::vector<JobObject *> listOfFiles, std::string name, std::string type, std::string path) {
    return this->fileSys->save(listOfFiles, name, type, path);
}

Repository::~Repository() {}
