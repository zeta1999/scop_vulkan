#ifndef SCOP_VULKAN_MODEL_HPP
#define SCOP_VULKAN_MODEL_HPP

#include <vector>

#include "glm/glm.hpp"

#include "Mesh.hpp"

class Model final
{
  public:
    Model() = default;
    explicit Model(std::string const &model_path);
    explicit Model(char const *model_path);
    Model(Model const &src) = delete;
    Model &operator=(Model const &rhs) = delete;
    Model(Model &&src) noexcept = default;
    Model &operator=(Model &&rhs) noexcept = default;
    ~Model() = default;

    void loadModel(std::string const &model_path);
    void loadModel(char const *model_path);
    void printModel() const;

    [[nodiscard]] std::vector<Mesh> const &getMeshList() const;
    [[nodiscard]] std::string const &getDirectory() const;

  private:
    std::vector<Mesh> _mesh_list;
    glm::vec3 _center{};
    glm::vec3 _min_point{};
    glm::vec3 _max_point{};
    std::string _model_path;
    std::string _directory;

    inline void _compute_min_max_points_and_center();
};

#endif