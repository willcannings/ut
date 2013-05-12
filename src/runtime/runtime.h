#include "filesystem/local/local_file.h"
#include "settings.h"
#ifndef __ut__
#define __ut__
namespace ut {

    class Runtime {
    public:
        Runtime() : settings(NULL) {
            settings.load(new LocalFile("/Users/will/dev/text_editor/settings", NULL));
        }
        
        Settings settings;
    };
    
}
#endif
