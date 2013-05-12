#include <forward_list>
#ifndef __observer_h__
#define __observer_h__
namespace ut {
    
    class Observer {
    public:
        
    };
    
    class Observable {
        std::vector<std::forward_list<Observer *>> observers;
        
    public:
        void notify(int event) {
            for (Observer *obsever : observers[event]) {
                obserer->
            }
        }
    };
    
    
    
};
#endif
