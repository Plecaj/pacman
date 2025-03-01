#include <iostream>

int main() {
#ifndef PLATFORM_WINDOWS  
    std::cout << "Error: Only Windows is supoported" << std::endl;
    return 1;
#else
    // Rest
#endif
}
