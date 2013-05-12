#include <vector>
#include "window.h"
#ifndef __workspace_h__
#define __workspace_h__
namespace ut {

    class Workspace {
        std::vector<Window *> windows;
        
    public:
        void show_window(Window *window) {
            windows.push_back(window);
        }
    };
    
}
#endif
