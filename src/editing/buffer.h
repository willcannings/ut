#include <forward_list>
#include "filesystem/file.h"
#include "line.h"

#ifndef __buffer_h__
#define __buffer_h__
namespace ut {
    
    enum BufferState {
        BUFFER_STATE_UNMODIFIED,
        BUFFER_STATE_MODIFIED
    };
    
    class Buffer {
        std::forward_list<Line *> lines;
        File        *file;
        
    public:
        Buffer(File *file) : file(file), state(BUFFER_STATE_UNMODIFIED) {}
        
        ~Buffer() {
            for (Line *line : lines)
                delete(line);
        }
        
        void load_lines();
        BufferState state;
    };
    
};
#endif
