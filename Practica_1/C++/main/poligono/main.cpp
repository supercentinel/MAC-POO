#include <iostream>
#include <cmath>
#include <string>

#include "raylib.h"
#include "randomColor.h"
#include "poligono.hh"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Poligono");
    SetTargetFPS(60);

    Poligono p_0 = Poligono(Vector2{screenWidth/2, screenHeight/2}, 10, 50, RED);

    p_0.print();

    while (!WindowShouldClose()) {
        //Update
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

        if (IsKeyPressed(KEY_R)) {
            p_0.setColor(getRandomColor());
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);

        //Instructions
        DrawText("Use the arrow keys to move the polygon", 10, 10, 20, RED);
        DrawText("Use W and S to change the radius", 10, 30, 20, RED);
        DrawText("Use A and D to change the number of sides", 10, 50, 20, RED);
        DrawText("Use Q and E to rotate the polygon", 10, 70, 20, RED);
        DrawText("Press R to randomize the color", 10, 90, 20, RED);

        //Values
        DrawText(("Center: " + std::to_string(p_0.getCenter().x) + ", " + std::to_string(p_0.getCenter().y)).c_str(), screenWidth-300, 10, 20, RED);

        DrawText(("Radius: " + std::to_string(p_0.getRadius())).c_str(), screenWidth-300, 30, 20, RED);
        DrawText(("Sides: " + std::to_string(p_0.getSides())).c_str(), screenWidth-300, 50, 20, RED);
        DrawText(("Area: " + std::to_string(p_0.getArea())).c_str(), screenWidth-300, 70, 20, RED);
        DrawText(("Perimeter: " + std::to_string(p_0.getPerimeter())).c_str(), screenWidth-300, 90, 20, RED);
        DrawText(("Rotation: " + std::to_string(p_0.getRotation())).c_str(), screenWidth-300, 110, 20, RED);
        DrawText(("Color: " + std::to_string(p_0.getColor().r) + ", " + std::to_string(p_0.getColor().g) + ", " + std::to_string(p_0.getColor().b) + ", " + std::to_string(p_0.getColor().a)).c_str(), screenWidth-300, 130, 20, RED);

        p_0.draw();

        EndDrawing();
    }

    return 0;
}
