#ifndef APPROXIMATED_DEVICE_MEMORY_H
#define APPROXIMATED_DEVICE_MEMORY_H

#include <stdint.h>
#include "sys_info.h"

namespace blink
{
    class ApproximatedDeviceMemory
    {
    private:
        static void CalculateAndSetApproximatedDeviceMemory();

        static float approximated_device_memory_gb_;
        static int64_t physical_memory_mb_;

    public:
        // Caches the device's physical memory in static members.
        static void Initialize();
        static float GetApproximatedDeviceMemory();
    };
    
} // namespace blink

#endif // APPROXIMATED_DEVICE_MEMORY_H

