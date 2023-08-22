#include <iostream>
#include <cmath>

#include "raylib.h"
#include "elipse.hh"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Elipse");

    SetTargetFPS(60);

    Elipse e_0 = Elipse(100, 100, 250.00, 50.00);
    e_0.setColor(RED);

    e_0.print();

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        e_0.draw();

        EndDrawing();
    }


    return 0;
}
