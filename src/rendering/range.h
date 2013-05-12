#include "editing/line.h"
#ifndef __range_h__
#define __range_h__
namespace ut {

    class Range {
    public:
        Range(Line *start_line, int start_col, Line *end_line, int end_col) :
            start_line(start_line),
            start_col(start_col),
            end_line(end_line),
            end_col(end_col) {}
        Line *start_line;
        int start_col;
        Line *end_line;
        int end_col;
    };
    
}
#endif
