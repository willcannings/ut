#include <libgen.h>
#include <string>

#ifndef __file_h__
#define __file_h__
namespace ut {
    
    class Folder;
    
    enum FileType {
		FILE_TYPE_UNKNOWN,
		FILE_TYPE_SOURCE,
		FILE_TYPE_TEXT,
		FILE_TYPE_IMAGE,
		FILE_TYPE_OTHER,
		FILE_TYPE_FOLDER
    };
    
    class File {
    protected:
    	std::string _name;
    	
    public:
        File(std::string path, FileType type, Folder *parent) :
        	path(path),
        	file_type(type),
        	parent(parent)
        	{}

        virtual ~File() {}
        bool operator==(File &other)  { return other.path == path; }
        
        // IO
        virtual void remove() = 0;
        virtual void rename(std::string path) = 0;
        virtual int read(void **buffer, int bytes) = 0;
        virtual int write(void *buffer, int length) = 0;
        
        // attributes
        virtual std::string name() {
			if (_name.empty() && !path.empty())
				_name = basename((char *)path.c_str());
			return _name;
        }
        
        std::string	path;
        FileType 	file_type;
        Folder 		*parent;
    };
    
};
#endif
