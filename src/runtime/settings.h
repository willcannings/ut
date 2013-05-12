#include <unordered_map>
#include <string>
#include <stdlib.h>
#include "filesystem/file.h"

#ifndef __settings_h__
#define __settings_h__
namespace ut {

    class Settings {
    protected:
        std::unordered_map<std::string, std::string> values;
        Settings *parent;
        File *file;

    public:
        Settings(Settings *parent) : parent(parent) {}
        
        ~Settings() {
            delete file;
        }
        
        void load(File *file) {
            this->file = file;
        }
        
        std::string get_string(std::string name, std::string default_value) {
            // TODO: determine type of values.find
            auto it = values.find(name);
            if (it != values.end()) {
                return it->second;
            } else {
                if (parent)
                    return parent->get_string(name, default_value);
                else
                    return default_value;
            }
        }
        
        int get_int(std::string name, int default_value) {
            std::string value = get_string(name, "");            
            if (!value.empty())
                return strtol(value.c_str(), NULL, 10);
            else
                return default_value;
        }
    };
    
}
#endif
