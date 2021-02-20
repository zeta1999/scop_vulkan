#ifndef SCOP_VULKAN_VULKANMEMORY_HPP
#define SCOP_VULKAN_VULKANMEMORY_HPP

#include <cstdint>
#include <vulkan/vulkan.h>

uint32_t findMemoryType(VkPhysicalDevice physical_device,
                        uint32_t type_filter,
                        VkMemoryPropertyFlags properties);
void createBuffer(VkDevice device,
                  VkBuffer &buffer,
                  VkDeviceSize size,
                  VkBufferUsageFlags usage);
void allocateBuffer(VkPhysicalDevice physical_device,
                    VkDevice device,
                    VkBuffer &buffer,
                    VkDeviceMemory &buffer_memory,
                    VkMemoryPropertyFlags properties);
void copyBuffer(VkDevice device,
                VkCommandPool command_pool,
                VkQueue gfx_queue,
                VkBuffer dst_buffer,
                VkBuffer src_buffer,
                VkDeviceSize size);
void copyBuffer(VkDevice device,
                VkCommandPool command_pool,
                VkQueue gfx_queue,
                VkBuffer dst_buffer,
                VkBuffer src_buffer,
                VkBufferCopy copy_region);
void copyOnMappedMemory(VkDevice device,
                        VkDeviceMemory memory,
                        VkDeviceSize offset,
                        VkDeviceSize size,
                        void const *dataToCopy);

#endif // SCOP_VULKAN_VULKANMEMORY_HPP
