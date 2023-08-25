#ifndef POLIGONO_HH
#define POLIGONO_HH

#include <iostream>
#include <cmath>

#include "raylib.h"

class Poligono {
    private:
        Vector2 center;
        int sides;
        int radius;
        double area;
        double perimeter;
        Color color;
    public:
        Poligono(Vector2 center, int sides, int radius, Color color);
        //getters
        Vector2 getCenter();
        int getRadius();
        int getSides();
        double getArea();
        double getPerimeter();
        Color getColor();
        //setters
        void setCenter(Vector2 center);
        void setRadius(int radius);
        void setSides(int sides);
        void setColor(Color color);
        //methods
        void calculateArea();
        void calculatePerimeter();
        void print();
        void draw();
        void update();
};
#endif
