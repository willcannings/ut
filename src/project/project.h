#include "runtime/runtime.h"
#include "filesystem/folder.h"
#include "display/workspace.h"
#include "display/windows/project_window.h"

#ifndef __project_h__
#define __project_h__
namespace ut {

    class Project {
        Runtime *runtime;
        Workspace workspace;
        Folder *folder;
        
    public:
        // TODO: allow projects to have stored workspace settings
        Project(Runtime *runtime, Folder *folder) :
            folder(folder),
            runtime(runtime),
            settings(runtime.settings)
        {
            workspace.show_window(new ProjectWindow(this));
        }
        
        ~Project() {
            delete folder;
        }
        
        Settings *settings;
    };
    
}
#endif
