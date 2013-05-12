#include <string>
#include "filesystem/file.h"
#include "filesystem/file_type.h"
#ifndef __memory_file_h__
#define __memory_file_h__
namespace ut {
    
    class MemoryFile : public File {
    public:
    	MemoryFile() : File("", FILE_TYPE_TEXT, NULL) {}
    	
    	int write(void *buffer, int length)	{
        	return 0;
        }
        
        int read(void **buffer, int bytes) {
        	return 0;
        }
    };
    
};
#endif
