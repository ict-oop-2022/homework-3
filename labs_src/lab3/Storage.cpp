#include "Storage.h"

Storage::Storage(JobObject file) : JobObject(file) {}

Storage Storage::getStorage() { return *this; }

string Storage::getStorageName() { return getName(); }

Storage::~Storage() {
    delete this;
}