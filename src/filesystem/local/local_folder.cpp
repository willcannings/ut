#include <sys/types.h>
#include <sys/dir.h>
#include "local_folder.h"
using namespace std;
using namespace ut;

void LocalFolder::load_children() {
}

std::forward_list<File *> LocalFolder::locate(std::string name) {
    std::forward_list<File *> results;
    return results;
}
