#ifndef ICT_HOMEWORK_3_JOBOBJECT_H
#define ICT_HOMEWORK_3_JOBOBJECT_H

#include <string>
#include <filesystem>
using namespace std;

class JobObject
{
private:
    string fileName;
public:
    JobObject(string fileName);
    string getName();
    ~JobObject();
    void operator=(JobObject other);
    bool operator==(JobObject other);
};

#endif //ICT_HOMEWORK_3_JOBOBJECT_H
