#pragma once
#include "Mesh.hpp"
#include "Camera.hpp"
#include <vector>
class World {
    public:
    Camera* camera;
    std::vector<Mesh*> meshes;
    World();
    void Render(sf::RenderWindow* window);
};