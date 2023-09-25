#include <iostream>
#include <raylib.h>

#include "bote.hpp"

int main(void) {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Bote");
    SetTargetFPS(60);

    Bote b_1 = Bote(Vector2{screenWidth/2, screenHeight/2}, 100, 100, 1, RED, BLUE, GREEN, YELLOW);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        b_1.draw();
        b_1.update();
        EndDrawing();
    }

    return 0;
}
