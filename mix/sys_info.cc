#include "sys_info.h"

namespace base
{
    // static
    int SysInfo::AmountOfPhysicalMemory() {
        return 8388608;
    }

    int SysInfo::AmountOfPhysicalMemoryMB() {
            return static_cast<int>(SysInfo::AmountOfPhysicalMemory() / 1024 / 1024);
  }
    
    // 
} // namespace base
