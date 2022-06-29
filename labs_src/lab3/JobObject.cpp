#include "JobObject.h"

JobObject::JobObject(string name) {
    if(name.empty()) throw invalid_argument("Wrong input for file name");
    this->fileName = name;
}

string JobObject::getName() {
    return fileName;
}

JobObject::~JobObject() {
    delete this;
}

void JobObject::operator=(JobObject other) {
    this->fileName = other.getName();
}

bool JobObject::operator==(JobObject other) {
    if(this->getName() == other.getName()) return true;
    return false;
}