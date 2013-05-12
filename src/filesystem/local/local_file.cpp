#include "filesystem/folder.h"
#include "local_file.h"
using namespace std;
using namespace ut;

void LocalFile::rename(std::string path) {
    this->path = path;
}

void LocalFile::remove() {
    parent->remove_child(*this);
}

int LocalFile::write(void *buffer, int length) {
	return 0;
}

int LocalFile::read(void **buffer, int bytes) {
	return 0;
}
