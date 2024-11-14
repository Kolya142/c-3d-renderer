#include "types3d.hpp"
namespace Type3 {

    Vertex::Vertex(float _x, float _y, float _z) {
        x = _x;
        y = _y;
        z = _z;
    }
    Vertex::Vertex()
    {
    }
    Vertex2::Vertex2(float _x, float _y)
    {
        x = _x;
        y = _y;
    }
    Edge::Edge(int _a, int _b) {
        a = _a;
        b = _b;
    }
    Vector2 Vertex::xy() {
        Vector2 v = Vector2();
        v.x = &x;
        v.y = &y;
        return v;
    }
    Vector2 Vertex::xz() {
        Vector2 v = Vector2();
        v.x = &x;
        v.y = &z;
        return v;
    }
    Vector2 Vertex::yx() {
        Vector2 v = Vector2();
        v.x = &y;
        v.y = &x;
        return v;
    }
    Vector2 Vertex::yz() {
        Vector2 v = Vector2();
        v.x = &y;
        v.y = &z;
        return v;
    }
    Vector2 Vertex::zx() {
        Vector2 v = Vector2();
        v.x = &z;
        v.y = &x;
        return v;
    }
    Vector2 Vertex::zy() {
        Vector2 v = Vector2();
        v.x = &z;
        v.y = &y;
        return v;
    }
    Vertex Vertex::clone()
    {
        return Vertex(x, y, z);
    }
    Vertex2 Vector2::vert()
    {
        return Vertex2((float)*x, (float)*y);
    }
    Vertex2 project(Vertex a) {
        float x = a.x;
        float y = a.y;
        float z = a.z;

        float d = 0.8;

        float _x = (x)/(z*d);
        float _y = (y)/(z*d);
        return Vertex2(_x, _y);
    }
    Vertex2 rotate(Vertex2 v, float a) {
        float x = v.x * cos(a) - v.y * sin(a);
        float y = v.x * sin(a) + v.y * cos(a);
        return Vertex2(x, y);
    }
}