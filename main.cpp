#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include "types3d.hpp"
#include <iostream>
#include "Mesh.hpp"
#include "World.hpp"

void generateTorus(Mesh& torus, float R, float r, int segments = 30, int ringSegments = 30) {
    for (int i = 0; i < segments; ++i) {
        float theta = 2 * M_PI * i / segments;
        for (int j = 0; j < ringSegments; ++j) {
            float phi = 2 * M_PI * j / ringSegments;

            float x = (R + r * cos(phi)) * cos(theta);
            float y = (R + r * cos(phi)) * sin(theta);
            float z = r * sin(phi);

            torus.vertexes.push_back(Type3::Vertex(x, y, z));
        }
    }

    for (int i = 0; i < segments; ++i) {
        for (int j = 0; j < ringSegments; ++j) {
            int nextI = (i + 1) % segments;
            int nextJ = (j + 1) % ringSegments;

            int a = i * ringSegments + j;
            int b = nextI * ringSegments + j;
            int c = nextI * ringSegments + nextJ;
            int d = i * ringSegments + nextJ;

            torus.edges.push_back(Type3::Edge(a, b));
            torus.edges.push_back(Type3::Edge(b, c));
            torus.edges.push_back(Type3::Edge(c, d));
            torus.edges.push_back(Type3::Edge(d, a));
        }
    }
}

int main() {
    #pragma region cube
    Mesh cube = Mesh();
    cube.position.z = 3;
    cube.edges.push_back(Type3::Edge(0, 1));
    cube.edges.push_back(Type3::Edge(1, 2));
    cube.edges.push_back(Type3::Edge(2, 3));
    cube.edges.push_back(Type3::Edge(3, 0));

    cube.edges.push_back(Type3::Edge(0+4, 1+4));
    cube.edges.push_back(Type3::Edge(1+4, 2+4));
    cube.edges.push_back(Type3::Edge(2+4, 3+4));
    cube.edges.push_back(Type3::Edge(3+4, 0+4));

    cube.edges.push_back(Type3::Edge(0, 0+4));
    cube.edges.push_back(Type3::Edge(1, 1+4));
    cube.edges.push_back(Type3::Edge(2, 2+4));
    cube.edges.push_back(Type3::Edge(3, 3+4));

    cube.vertexes.push_back(Type3::Vertex(-1, -1, -1));
    cube.vertexes.push_back(Type3::Vertex(1, -1, -1));
    cube.vertexes.push_back(Type3::Vertex(1, 1, -1));
    cube.vertexes.push_back(Type3::Vertex(-1, 1, -1));

    cube.vertexes.push_back(Type3::Vertex(-1, -1, 1));
    cube.vertexes.push_back(Type3::Vertex(1, -1, 1));
    cube.vertexes.push_back(Type3::Vertex(1, 1, 1));
    cube.vertexes.push_back(Type3::Vertex(-1, 1, 1));
    #pragma endregion

    Mesh torus;
    torus.position.z = 5;
    generateTorus(torus, 2, 1, 30, 30);

    World world = World();
    world.meshes.push_back(&torus);

    sf::RenderWindow window(sf::VideoMode(640, 480), "c++ 3d");
    float t = 0;
    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        torus.rotation.y = t;
        torus.rotation.x = t;
        world.Render(&window);/*
        world.camera->rotation.y = -((float)mouse.x / 640 - 0.5);
        world.camera->rotation.x = -((float)mouse.y / 480 - 0.5);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            world.camera->position.z += 0.001;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            world.camera->position.x -= 0.001;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            world.camera->position.z -= 0.001;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            world.camera->position.x += 0.001;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            world.camera->position.y -= 0.001;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            world.camera->position.y += 0.001;
        }*/
        window.display();
        t += 0.001;
    } 
}
