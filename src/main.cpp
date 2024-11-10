#include "first_app.hpp"

// std
//#include <stdexcept>
#include <cstdlib>
#include <iostream>

int main(void) {
    
    lve::FirstApp app{};

    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return EXIT_FAILURE;
    }

    EXIT_SUCCESS;
}