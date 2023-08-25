#include <iostream>
#include <cmath>

#include "raylib.h"
#include "poligono.hh"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Poligono");
    SetTargetFPS(60);

    Poligono p_0 = Poligono(Vector2{screenWidth/2, screenHeight/2}, 10, 50, RED);

    p_0.print();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //Interactions
        if (IsKeyDown(KEY_UP)) {
            p_0.setCenter(Vector2{p_0.getCenter().x, p_0.getCenter().y - 1});
        }

        if (IsKeyDown(KEY_DOWN)) {
            p_0.setCenter(Vector2{p_0.getCenter().x, p_0.getCenter().y + 1});
        }

        if (IsKeyDown(KEY_LEFT)) {
            p_0.setCenter(Vector2{p_0.getCenter().x - 1, p_0.getCenter().y});
        }

        if (IsKeyDown(KEY_RIGHT)) {
            p_0.setCenter(Vector2{p_0.getCenter().x + 1, p_0.getCenter().y});
        }

        if (IsKeyDown(KEY_W)) {
            p_0.setRadius(p_0.getRadius() + 1);
            p_0.update();
        }

        if (IsKeyDown(KEY_S)) {
            p_0.setRadius(p_0.getRadius() - 1);
            p_0.update();
        }

        if (IsKeyPressed(KEY_A)) {
            p_0.setSides(p_0.getSides() + 1);
            p_0.update();
        }

        if (IsKeyPressed(KEY_D)) {
            p_0.setSides(p_0.getSides() - 1);
            p_0.update();
        }

        if (IsKeyDown(KEY_Q)) {
            p_0.setRotation(p_0.getRotation() + 1);
        }

        if (IsKeyDown(KEY_E)) {
            p_0.setRotation(p_0.getRotation() - 1);
        }

        p_0.draw();

        EndDrawing();
    }

    return 0;
}
