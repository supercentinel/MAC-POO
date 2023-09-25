#include <iostream>
#include <raylib.h>

#include "bote.hpp"

//Constructor
Bote::Bote(Vector2 center,
        float width,
        float height,
        float speed,
        Color hullColor,
        Color deckColor,
        Color sailColor,
        Color mastColor) {

    this->center = center;
    this->width = width;
    this->height = height;
    this->speed = speed;
    this->hullColor = hullColor;
    this->deckColor = deckColor;
    this->sailColor = sailColor;
    this->mastColor = mastColor;
}

//setters
void Bote::setCenter(Vector2 center) {
    this->center = center;
}

void Bote::setWidth(float width) {
    this->width = width;
}

void Bote::setHeight(float height) {
    this->height = height;
}

void Bote::setSpeed(float speed) {
    this->speed = speed;
}

void Bote::setHullColor(Color hullColor) {
    this->hullColor = hullColor;
}

void Bote::setDeckColor(Color deckColor) {
    this->deckColor = deckColor;
}

void Bote::setSailColor(Color sailColor) {
    this->sailColor = sailColor;
}

void Bote::setMastColor(Color mastColor) {
    this->mastColor = mastColor;
}

//getters
Vector2 Bote::getCenter() {
    return this->center;
}

float Bote::getWidth() {
    return this->width;
}

float Bote::getHeight() {
    return this->height;
}

float Bote::getSpeed() {
    return this->speed;
}

Color Bote::getHullColor() {
    return this->hullColor;
}

Color Bote::getDeckColor() {
    return this->deckColor;
}

Color Bote::getSailColor() {
    return this->sailColor;
}

Color Bote::getMastColor() {
    return this->mastColor;
}

//methods
void Bote::draw() {
    //draw border of boat DEBUG
    DrawRectangleLines(this->center.x - this->width/2, this->center.y - this->height/2, this->width, this->height, BLACK);
    //draw hull
    //main hull
    DrawRectangle(this->center.x - this->width/2, this->center.y - this->height/2, this->width/3, this->height/3, this->hullColor);
    //triangles sides
    //draw deck
    //draw mast
    //draw sail
}

void Bote::update() {
    //move the boat
    return;
}
