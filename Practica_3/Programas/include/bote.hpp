#ifndef BOTE_HPP
#define BOTE_HPP

#include <iostream>
#include <raylib.h>

class Bote {
    private:
        Vector2 center;
        float width;
        float height;
        float speed;
        Color hullColor;
        Color deckColor;
        Color sailColor;
        Color mastColor;
    public:
        //Constructor
        Bote(Vector2 center,
                float width,
                float height,
                float speed,
                Color hullColor,
                Color deckColor,
                Color sailColor,
                Color mastColor);
        //setters
        void setCenter(Vector2 center);
        void setWidth(float width);
        void setHeight(float height);
        void setSpeed(float speed);
        void setHullColor(Color hullColor);
        void setDeckColor(Color deckColor);
        void setSailColor(Color sailColor);
        void setMastColor(Color mastColor);
        //getters
        Vector2 getCenter();
        float getWidth();
        float getHeight();
        float getSpeed();
        Color getHullColor();
        Color getDeckColor();
        Color getSailColor();
        Color getMastColor();
        //methods
        void draw();
        void update();

};
#endif
