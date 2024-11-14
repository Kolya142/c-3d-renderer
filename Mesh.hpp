#pragma once
#include "types3d.hpp"

class Mesh {
    public:
    // std::vector<Face> faces;
    std::vector<Type3::Edge> edges;
    std::vector<Type3::Vertex> vertexes;
    Type3::Vertex position;
    Type3::Vertex rotation; // x-yz, y-xz, z-xy
    void render(sf::RenderWindow* window);
};