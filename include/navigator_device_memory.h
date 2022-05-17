#ifndef NAVIGATOR_DEVICE_MEMORY_H
#define NAVIGATOR_DEVICE_MEMORY_H

#include "approximated_device_memory.h"

namespace blink {
    class NavigatorDeviceMemory{
    
    public:
        float deviceMemory() const; 
};

} // namespace blink

#endif // NAVIGATOR_DEVICE_MEMORY_H
