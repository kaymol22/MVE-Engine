#pragma once

#include "mve_window.hpp"
#include "mve_pipeline.hpp"
#include <memory>
#include <mve_device.hpp>
#include <mve_swap_chain.hpp>

//std 
#include <memory.h>
#include <vector>

namespace mve {
    class FirstApp {

    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        FirstApp();
        ~FirstApp();
        // Copy constructors
        FirstApp(const MveWindow &) = delete;
        FirstApp &operator = (const MveWindow &) = delete;

        void run();
    private:
        void createPipelineLayout();
        void createPipeline();
        void createCommandBuffers();
        void drawFrame();

        MveWindow mveWindow{ WIDTH , HEIGHT, "Hello Triangle!" };
        MveDevice mveDevice{mveWindow};
        MveSwapChain mveSwapChain {mveDevice, mveWindow.getExtent()};
        std::unique_ptr<MvePipeline> mvePipeline; // Smart pointer for automatic memory management
        VkPipelineLayout pipelineLayout;
        std::vector<VkCommandBuffer> commandBuffers;
    };
}