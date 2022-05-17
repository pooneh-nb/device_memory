#include "navigator_device_memory.h"
#include <iostream>

using namespace blink;


int main() {
   NavigatorDeviceMemory obj;
   float a = obj.deviceMemory();
   std::cout << a;
}

