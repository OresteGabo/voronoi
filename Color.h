//
// Created by oreste on 28/12/23.
//

#ifndef DIAGRAMMEVORONOI_COLOR_H
#define DIAGRAMMEVORONOI_COLOR_H
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

using std::vector;
using std::string;
class Color {
int d_r,d_g,d_b;
string d_name;
public:
    Color(int r, int g, int b,const string& n="");

    int r() const;

    void r(int r);

    int g() const;

    void g(int g);

    int b() const;

    void b(int b);
    string toString()const;
    cv::Vec3b getVec3b() const;

    static const vector<Color>colors;

    static const Color black;
    static const Color red;
    static const Color green;
    static const Color blue;

    static const Color white;
    static const Color yellow;
    static const Color purple;
    static const Color orange;
    static const Color cyan;
    static const Color pink;
    static const Color brown;
    static const Color gray;
    static const Color olive;

    static const Color lightBlue;
    static const Color darkGreen;
    static const Color gold;
    static const Color navy;
    static const Color indigo;
    static const Color teal;
    static const Color maroon;
    static const Color violet;
    static const Color turquoise;
    static const Color darkSlateGray;

    static const Color firebrick;
    static const Color darkGoldenrod;
    static const Color sienna;
    static const Color mediumVioletRed;
    static const Color darkOliveGreen;
    static const Color mediumOrchid;
    static const Color darkSlateBlue;
    static const Color saddleBrown;
    static const Color darkCyan;
    static const Color darkMagenta;

    static const Color mediumPurple;
    static const Color coral;
    static const Color darkOrange;
    static const Color mediumSeaGreen;
    static const Color royalBlue;
    static const Color darkKhaki;
    static const Color darkSalmon;
    static const Color lightSlateGray;
    static const Color mediumTurquoise;
    static const Color lightCoral;


};


#endif //DIAGRAMMEVORONOI_COLOR_H
