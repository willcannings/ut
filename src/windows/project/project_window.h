#include <vector>
#include "windows/window.h"
#include "drawer.h"
#include "tab.h"
#ifndef __project_window_h__
#define __project_window_h__
namespace ut {

    class ProjectWindow : public Window {
        std::vector<Tab *> tabs;
        Tab     *active_tab;
        Project &project;
        Drawer  drawer;

    public:
        ProjectWindow(Project &project, int width = 0, int height = 0) :
            project(project),
            drawer(project),
            Window()
        {
            active_tab = new Tab();
            tabs.push_back(active_tab);
            
            if (width == 0 || height == 0) {
                width = project.settings.get_int("window_width");
                height = project.settings.get_int("window_height");
            }
            
            set_dimensions(width, height);
        }
        
        ~ProjectWindow() {
            for (Tab *tab : tabs)
                delete tab;
        }
    };
    
}
#endif
