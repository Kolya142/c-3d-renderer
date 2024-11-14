#include "Mesh.hpp"
void Mesh::render(sf::RenderWindow* window)
{
    std::vector<Type3::Vertex2> projs = std::vector<Type3::Vertex2>();
    for (int i = 0; i < vertexes.size(); i++) {        
        Type3::Vertex a_ = vertexes[i].clone();

        Type3::Vertex2 a_yz = rotate(a_.yz().vert(), rotation.x);
        a_.y = a_yz.x;a_.z = a_yz.y;

        Type3::Vertex2 a_xz = rotate(a_.xz().vert(), rotation.y);
        a_.x = a_xz.x;a_.z = a_xz.y;

        Type3::Vertex2 a_xy = rotate(a_.xy().vert(), rotation.z);
        a_.x = a_xy.x;a_.y = a_xy.y;

        a_.x += position.x;
        a_.y += position.y;
        a_.z += position.z;
        Type3::Vertex2 a = project(a_);
        projs.push_back(a);
    }
    for (int i = 0; i < edges.size(); i++) {
        Type3::Edge e = edges[i];
        Type3::Vertex2 a = projs[e.a];
        Type3::Vertex2 b = projs[e.b];
        float l = 50;
        sf::VertexArray line(sf::LinesStrip, 2);
        line[0].position = sf::Vector2f(a.x*l+320, a.y*l+240);
        line[1].position = sf::Vector2f(b.x*l+320, b.y*l+240);
        window->draw(line);
    }
}