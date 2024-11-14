#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>

namespace Type3 {
    struct Vertex2 {
        float x;
        float y;
        Vertex2(float _x, float _y);
    };
    struct Vector2 {
        float* x;
        float* y;
        Vertex2 vert();
    };
    struct Vertex {
        float x;
        float y;
        float z;
        Vertex(float _x, float _y, float _z);
        Vertex();
        Vector2 xy();
        Vector2 xz();
        Vector2 yx();
        Vector2 yz();
        Vector2 zx();
        Vector2 zy();
        Vertex clone();
    };
    Vertex2 project(Vertex a);
    Vertex2 rotate(Vertex2 v, float a);
    struct Edge {
        int a;
        int b;
        Edge(int _a, int _b);
    };
    struct Face {
        int a;
        int b;
        int c;
    };
}