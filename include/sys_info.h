#ifndef SYS_INFO_H
#define SYS_INFO_H

namespace base
{
    struct systemMemoryInfoKB;

    class SysInfo
    {
        
    public:
        // Return the number of bytes of physical memory on the current machine.
        static int AmountOfPhysicalMemory();

        // Return the number of megabytes of physical memory on the current machine.
        static int AmountOfPhysicalMemoryMB();
        
    };
} // namespace base

#endif //SYS_INFO_H
