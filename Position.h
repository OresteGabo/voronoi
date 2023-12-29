//
// Created by oreste on 28/12/23.
//

#ifndef DIAGRAMMEVORONOI_POSITION_H
#define DIAGRAMMEVORONOI_POSITION_H


#include<string>
#include<math.h>
#include <random>
#include "Color.h"

using std::string;
class Position
{
public:
    Position(int x,int y,const Color&);
    Position(int x,int y);
    Position();
    virtual ~Position();
    inline int x() const{ return d_x; }
    inline void x(int val) { d_x = val; }
    inline int y() const{ return d_y; }
    inline void y(int val) { d_y = val; }
    const Color &color() const;
    void color(const Color &color);
    string toString()const;
    bool operator==(const Position& other) const;
    double distance(const Position&)const;
private:
    int d_x;
    int d_y;
    Color d_color;
};

#endif //DIAGRAMMEVORONOI_POSITION_H
