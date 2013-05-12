#ifndef __window_h__
#define __window_h__
namespace ut {

    class Window {
    public:
        Window() {}
        
        void set_dimensions(int width, int height) {
            this->width = width;
            this->height = height;
        }
        
        int width;
        int height;
    };
    
}
#endif
