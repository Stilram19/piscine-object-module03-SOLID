// # include "FileLogger.hpp"
# include "StreamLogger.hpp"
# include <iostream>

int main() {
    try {
        
    }
    catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}
