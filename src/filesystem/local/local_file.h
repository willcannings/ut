#include <string>
#include "filesystem/file.h"
#ifndef __local_file_h__
#define __local_file_h__
namespace ut {
    
    class LocalFile : public File {
    public:
    	LocalFile(std::string path, Folder *parent) : File(path, FILE_TYPE_UNKNOWN, parent) {}
        void rename(std::string path);
        void remove();
        int write(void *buffer, int length);
        int read(void **buffer, int bytes);
    };
    
};
#endif
