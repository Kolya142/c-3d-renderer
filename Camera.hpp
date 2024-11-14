#pragma once
#include "Mesh.hpp"

class Camera {
    public:
    Type3::Vertex position;
    Type3::Vertex rotation;
    void Draw(sf::RenderWindow* window, Mesh* mesh);
};
