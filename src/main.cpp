#include "first_app.hpp"

// std
//#include <stdexcept>
#include <cstdlib>
#include <iostream>

int main(void) {
    
    mve::FirstApp app{};

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    EXIT_SUCCESS;
}