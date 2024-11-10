#include "lve_pipeline.hpp"

#include <fstream> // to include inputfilestream object for reading string input
#include <stdexcept>
#include <iostream>

namespace lve {

    LvePipeline::LvePipeline(const std::string& vertFilepath, const std::string& fragFilepath){
        try {
        createGraphicsPipeline(vertFilepath, fragFilepath);
        } catch (const std::runtime_error& e) {
            std::cerr << "Error in createGraphicsPipeline " << e.what() << std::endl;
        }
    }

     LvePipeline::~LvePipeline(){
         std::cout << "Pipeline Destroyed" << std::endl;
    }

    std::vector<char> LvePipeline::readFile(const std::string& filePath) {

        // Bitflags: ate - jumps to end to get size, binary - read as binary
        std::ifstream file{filePath, std::ios::ate | std::ios::binary};

        if(!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }

        // casting tellg() to get last position, returns fileSize 
        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0); // Return to pos zero in file
        file.read(buffer.data(), fileSize); //begin reading file and store in buffer

        file.close();
        return buffer;
    }

    void LvePipeline::createGraphicsPipeline(
        const std::string& vertFilepath, const std::string& fragFilepath){

            auto vertCode = readFile(vertFilepath);
            auto fragCode = readFile(fragFilepath);

            std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
            std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
    }

}