#include <forward_list>
#include <string>
#include "file.h"

#ifndef __folder_h__
#define __folder_h__
namespace ut {

    class Folder : public File {
    protected:
		std::forward_list<File *> _children;
        virtual void load_children() = 0;
        bool children_loaded;
        
    public:
        Folder(std::string path, Folder *parent) :
        	children_loaded(false),
        	File(path, FILE_TYPE_FOLDER, parent)
        	{}
    	
    	virtual std::forward_list<File *> locate(std::string name) = 0;
        
        virtual std::forward_list<File *> &children() {
        	if (!children_loaded)
        		load_children();
        	return _children;
        }
        
        virtual void load_descendents() {
        	for (File *file : children()) {
        		if (file->file_type == FILE_TYPE_FOLDER)
        			((Folder *)file)->load_descendents();
        	}
        }
        
        virtual void remove_child(File &file) {
            _children.remove(&file);
        }
        
        int write(void *buffer, int length)	{
        	return 0;
        }
        
        int read(void **buffer, int bytes) {
        	return 0;
        }
    };

};
#endif
