#include "filesystem/folder.h"
#ifndef __local_folder_h__
#define __local_folder_h__
namespace ut {
    
    class LocalFolder : public Folder {
    public:
    	LocalFolder(std::string path, Folder *parent) : Folder(path, parent) {}
        std::forward_list<File *> locate(std::string name);
        void load_children();
    };
    
};
#endif
