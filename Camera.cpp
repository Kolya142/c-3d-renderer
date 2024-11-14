#include "Camera.hpp"

void Camera::Draw(sf::RenderWindow *window, Mesh *mesh)
{
    mesh->rotation.x -= rotation.x;
    mesh->rotation.y -= rotation.y;
    mesh->rotation.z -= rotation.z;
    Type3::Vertex r = mesh->position;
    mesh->position.x -= position.x;
    mesh->position.y -= position.y;
    mesh->position.z -= position.z;
    Type3::Vertex2 meshpositionxz = rotate(mesh->position.xz().vert(), -rotation.y);
    mesh->position.x = meshpositionxz.x;mesh->position.z = meshpositionxz.y; 
    Type3::Vertex2 meshpositionyz = rotate(mesh->position.yz().vert(), -rotation.x);
    mesh->position.y = meshpositionyz.x;mesh->position.z = meshpositionyz.y;
    // Type3::Vertex2 meshpositionxy = rotate(mesh->position.xy().vert(), -rotation.z);
    // mesh->position.x = meshpositionxy.x;mesh->position.y = meshpositionxy.y;   
    // begin


    mesh->render(window);


    // end
    mesh->rotation.x += rotation.x;
    mesh->rotation.y += rotation.y;
    mesh->rotation.z += rotation.z;
    mesh->position = r;
}