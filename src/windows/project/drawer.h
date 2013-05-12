#include "project/project.h"
#include "filesystem/file.h"
#ifndef __drawer_h__
#define __drawer_h__
namespace ut {

    class Drawer {
        Folder *folder;
        
    public:
        Drawer(Project &project, int width = 0) :
            folder(project.folder),
            selection(NULL)
        {
            if (width != 0)
                set_width(width)
            else
                set_width(project.settings.get_int("drawer_width"));
        }
            
        void set_width(int width) {
            this->width = width;
        }
        
        void set_selection(File *file) {
            this->selection = file;
        }
        
        int width;
        File *selection;
    };
    
}
#endif
