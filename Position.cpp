//
// Created by oreste on 28/12/23.
//

#include "Position.h"

Position::Position(int x,int y,const Color&c):d_x{x},d_y{y},d_color{c}{}
Position::Position(int x,int y):Position(x,y,Color::black){}
Position::Position(): Position(0,0,Color::black){}
Position::~Position(){}

std::string Position::toString() const {
    return "(" + std::to_string(d_x) + "," + std::to_string(d_y) + ")";
}
double Position::distance(const Position& other) const {
    int deltaX = d_x - other.d_x;
    int deltaY = d_y - other.d_y;
    return std::sqrt(static_cast<double>(deltaX * deltaX + deltaY * deltaY));
}
const Color &Position::color() const {
    return d_color;
}

void Position::color(const Color &c) {
    Position::d_color = c;
}
bool Position::operator==(const Position& other) const {
    return (d_x == other.d_x) && (d_y == other.d_y);
}
