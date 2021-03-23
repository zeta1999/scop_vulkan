#ifndef SCOP_VULKAN_VULKANUI_HPP
#define SCOP_VULKAN_VULKANUI_HPP

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_vulkan.h"

#include "VulkanInstance.hpp"
#include "VulkanSwapChain.hpp"

class VulkanUi final
{
  public:
    VulkanUi() = default;
    ~VulkanUi() = default;
    VulkanUi(VulkanUi const &src) = delete;
    VulkanUi &operator=(VulkanUi const &rhs) = delete;
    VulkanUi(VulkanUi &&src) = delete;
    VulkanUi &operator=(VulkanUi &&rhs) = delete;

    void init(VulkanInstance const &vkInstance,
              VulkanSwapChain const &swapChain);
    void resize(VulkanSwapChain const &swapChain);
    void clear();

  private:
    VkInstance _instance{};
    VkPhysicalDevice _physicalDevice{};
    VkDevice _device{};
    VkQueue _graphicQueue{};
    uint32_t _graphicQueueIndex{};
    VkCommandPool _commandPool{};

    VkDescriptorPool _descriptorPool{};

    inline void _init_imgui(VulkanSwapChain const &renderPass);
    inline void _load_fonts();
};

#endif // SCOP_VULKAN_VULKANUI_HPP
