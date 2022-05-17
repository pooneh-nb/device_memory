#include "../include/approximated_device_memory.h"


namespace blink
{
    // static
    float ApproximatedDeviceMemory::approximated_device_memory_gb_ = 0.0;
    int64_t ApproximatedDeviceMemory::physical_memory_mb_ = 0;

    // static
    void ApproximatedDeviceMemory::Initialize() {
        if (approximated_device_memory_gb_ > 0.0)
            return;
        // DCHECK_EQ(0, physical_memory_mb_);
        physical_memory_mb_ = ::base::SysInfo::AmountOfPhysicalMemoryMB();
        CalculateAndSetApproximatedDeviceMemory();
    }

    // static
    float ApproximatedDeviceMemory::GetApproximatedDeviceMemory() {
        Initialize();
        return approximated_device_memory_gb_;
    }

    // static 
    void ApproximatedDeviceMemory::CalculateAndSetApproximatedDeviceMemory() {
        // DCHECK_GT(physical_memory_mb_, 0);
        int lower_bound = physical_memory_mb_;
        int power = 0;

        // Extract the most-significant-bit and its location.
        while (lower_bound > 1) {
            lower_bound >>= 1;
            power ++;
        }

        // The remaining should always be equal to exactly 1.
        // DCHECK_EQ(lower_bound, 1);
        int64_t upper_bound = lower_bound + 1;
        lower_bound = lower_bound << power;
        upper_bound = upper_bound << power;

        // Find the closest bound, and convert it to GB.
        if (physical_memory_mb_ - lower_bound <= upper_bound - physical_memory_mb_)
            approximated_device_memory_gb_ = static_cast<float> (lower_bound) / 1024.0;
        else
            approximated_device_memory_gb_ = static_cast<float> (upper_bound) / 1024.0;

        // Max-limit the reported value to 8GB to reduce fingerprintability of
        // high-spec machines.
        if (approximated_device_memory_gb_ > 8)
            approximated_device_memory_gb_ = 8.0;


    }
    
} // namespace blink

