#ifndef ICT_HOMEWORK_3_BACKUPJOB_H
#define ICT_HOMEWORK_3_BACKUPJOB_H

#include "Repository.h"

class BackupJob
{
private:
    Repository repo;

public:
    BackupJob(Repository repo_);
    void checkZipType(string zipType);
    Repository getRepo();
    void makeZip(string path, string zipType);
    void addFile(JobObject file);
    void addFile(Storage storage);
    void deleteFile(JobObject file);
    void deleteFile(Storage storage);
};

#endif //ICT_HOMEWORK_3_BACKUPJOB_H
