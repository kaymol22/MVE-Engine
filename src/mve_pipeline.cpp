#include "mve_pipeline.hpp"

#include <fstream> // to include inputfilestream object for reading string input
#include <stdexcept>
#include <iostream>
#include <vulkan/vulkan_core.h>

namespace mve {

    MvePipeline::MvePipeline(        
        MveDevice& device, 
        const std::string& vertFilepath, 
        const std::string& fragFilepath, 
        const PipelineConfigInfo& configInfo) : mveDevice{device} {
        try {
        createGraphicsPipeline(vertFilepath, fragFilepath, configInfo);
        } catch (const std::runtime_error& e) {
            std::cerr << "Error in createGraphicsPipeline " << e.what() << std::endl;
        }
    }

    std::vector<char> MvePipeline::readFile(const std::string& filePath) {

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

    void MvePipeline::createGraphicsPipeline(
        const std::string& vertFilepath, 
        const std::string& fragFilepath, 
        const PipelineConfigInfo& configInfo){

            auto vertCode = readFile(vertFilepath);
            auto fragCode = readFile(fragFilepath);

            std::cout << "Vertex Shader Code Size: " << vertCode.size() << '\n';
            std::cout << "Fragment Shader Code Size: " << fragCode.size() << '\n';
    }

    void MvePipeline::createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule) {
        VkShaderModuleCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        createInfo.codeSize = code.size();
        createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

        if (vkCreateShaderModule(mveDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
            throw std::runtime_error("failed to create shader module");
        }
    }

    PipelineConfigInfo MvePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height){
        PipelineConfigInfo configInfo{};

        return configInfo;
    }

}