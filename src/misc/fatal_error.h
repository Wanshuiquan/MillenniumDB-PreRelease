#include <iostream>

// prints an error and exits the program
inline void FATAL_ERROR(const std::string& error) {
    std::cerr << "\x1B[0;31m";
    std::cerr << "FATAL ERROR:\n";
    std::cerr << error;
    std::cerr << "\n\x1B[0m";
    std::exit(EXIT_FAILURE);
}
