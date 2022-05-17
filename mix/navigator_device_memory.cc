#include "navigator_device_memory.h"

namespace blink
{
    float NavigatorDeviceMemory::deviceMemory() const{
        return ApproximatedDeviceMemory::GetApproximatedDeviceMemory();
    }
} // namespace blink
