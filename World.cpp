#include "World.hpp"

World::World()
{
    camera = new Camera();
}

void World::Render(sf::RenderWindow *window)
{
    for (int i = 0; i < meshes.size(); i++) {
        camera->Draw(window, meshes[i]);
    }
}