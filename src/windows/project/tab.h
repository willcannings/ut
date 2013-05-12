#include <vector>
#include "rendering/view.h"
#ifndef __tab_h__
#define __tab_h__
namespace ut {

    class Tab {
        std::vector<View *> views;
        View *active_view;
        
    public:
        Tab() : active_view(NULL) {}
        
        ~Tab() {
            for (View *view : views)
                delete view;
        }
    };
    
}
#endif
