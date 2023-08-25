#include <iostream>
#include <cmath>

#include "raylib.h"
#include "triangulo.hh"

int main() {
    int screenWidth = 1280;
    int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Triangulo");

    SetTargetFPS(60);

    Triangulo t_0 = Triangulo(Vector2{100, 100}, Vector2{200, 200}, Vector2{300, 100}, Vector2{200, 100});

    t_0.setColor(BLUE);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        t_0.draw();

        EndDrawing();
    }



    return 0;
}
