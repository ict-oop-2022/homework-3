#ifndef ICT_HOMEWORK_3_STORAGE_H
#define ICT_HOMEWORK_3_STORAGE_H

#include "JobObject.h"
#include <vector>
#include <string>
#include <filesystem>
using namespace std;

class Storage : public JobObject
{
public:
    explicit Storage(JobObject file);
    Storage getStorage();
    string getStorageName();
    bool operator==(Storage other);
    ~Storage();
};

#endif //ICT_HOMEWORK_3_STORAGE_H
