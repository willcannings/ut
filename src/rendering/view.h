#include <vector>
#include "editing/buffer.h"
#include "range.h"
#ifndef __view_h__
#define __view_h__
namespace ut {

    class View {
        int width;
        int height;
        int scroll;
        std::vector<Range *> selections;
        Buffer *buffer;
        
    public:
        View(Buffer *buffer) : buffer(buffer) {
            selections.push_back(new Range(buffer->lines[0], 0, buffer->lines[0], 0));
        }
        
        ~View() {
            for (Range *selection : selections)
                delete selection;
        }
    };
    
}
#endif
