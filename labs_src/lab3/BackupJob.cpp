#include "BackupJob.h"

BackupJob::BackupJob(Repository repo_) : repo(repo_) {}

void BackupJob::checkZipType(string zipType) {
    if(zipType != "single" && zipType != "split") throw invalid_argument("Wrong archive type");
}

Repository BackupJob::getRepo() { return repo; }

void BackupJob::makeZip(string path, string zipType) {
    repo.setPath(path);
    repo.saveRS(zipType);
}

void BackupJob::addFile(JobObject file) { repo.addFile(file); }

void BackupJob::addFile(Storage storage) { repo.addFile(storage); }

void BackupJob::deleteFile(JobObject file) { repo.deleteFile(file); }

void BackupJob::deleteFile(Storage storage) { repo.deleteFile(storage); }

