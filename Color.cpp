//
// Created by oreste on 28/12/23.
//

#include "Color.h"

Color::Color(int r, int g, int b,const string& name) : d_r(r), d_g(g), d_b(b) ,d_name(name){}

int Color::r() const {
    return d_r;
}

void Color::r(int r) {
    Color::d_r = r;
}

int Color::g() const {
    return d_g;
}

void Color::g(int g) {
    Color::d_g = g;
}

int Color::b() const {
    return d_b;
}

void Color::b(int b) {
    Color::d_b = b;
}




const Color Color::black = Color(0, 0, 0, "black");
const Color Color::red = Color(255, 0, 0, "red");
const Color Color::green = Color(0, 255, 0, "green");
const Color Color::blue = Color(0, 0, 255, "blue");

const Color Color::white = Color(255, 255, 255, "white");
const Color Color::yellow = Color(255, 255, 0, "yellow");
const Color Color::purple = Color(128, 0, 128, "purple");
const Color Color::orange = Color(255, 165, 0, "orange");
const Color Color::cyan = Color(0, 255, 255, "cyan");
const Color Color::pink = Color(255, 192, 203, "pink");
const Color Color::brown = Color(165, 42, 42, "brown");
const Color Color::gray = Color(128, 128, 128, "gray");
const Color Color::olive = Color(128, 128, 0, "olive");

const Color Color::lightBlue = Color(173, 216, 230, "lightBlue");
const Color Color::darkGreen = Color(0, 100, 0, "darkGreen");
const Color Color::gold = Color(255, 215, 0, "gold");
const Color Color::navy = Color(0, 0, 128, "navy");
const Color Color::indigo = Color(75, 0, 130, "indigo");
const Color Color::teal = Color(0, 128, 128, "teal");
const Color Color::maroon = Color(128, 0, 0, "maroon");
const Color Color::violet = Color(238, 130, 238, "violet");
const Color Color::turquoise = Color(64, 224, 208, "turquoise");
const Color Color::darkSlateGray = Color(47, 79, 79, "darkSlateGray");

const Color Color::firebrick = Color(178, 34, 34, "firebrick");
const Color Color::darkGoldenrod = Color(184, 134, 11, "darkGoldenrod");
const Color Color::sienna = Color(160, 82, 45, "sienna");
const Color Color::mediumVioletRed = Color(199, 21, 133, "mediumVioletRed");
const Color Color::darkOliveGreen = Color(85, 107, 47, "darkOliveGreen");
const Color Color::mediumOrchid = Color(186, 85, 211, "mediumOrchid");
const Color Color::darkSlateBlue = Color(72, 61, 139, "darkSlateBlue");
const Color Color::saddleBrown = Color(139, 69, 19, "saddleBrown");
const Color Color::darkCyan = Color(0, 139, 139, "darkCyan");
const Color Color::darkMagenta = Color(139, 0, 139, "darkMagenta");

const Color Color::mediumPurple = Color(147, 112, 219, "mediumPurple");
const Color Color::coral = Color(255, 127, 80, "coral");
const Color Color::darkOrange = Color(255, 140, 0, "darkOrange");
const Color Color::mediumSeaGreen = Color(60, 179, 113, "mediumSeaGreen");
const Color Color::royalBlue = Color(65, 105, 225, "royalBlue");
const Color Color::darkKhaki = Color(189, 183, 107, "darkKhaki");
const Color Color::darkSalmon = Color(233, 150, 122, "darkSalmon");
const Color Color::lightSlateGray = Color(119, 136, 153, "lightSlateGray");
const Color Color::mediumTurquoise = Color(72, 209, 204, "mediumTurquoise");
const Color Color::lightCoral = Color(240, 128, 128, "lightCoral");

string Color::toString() const {
    return d_name==""? "r:"+std::to_string(r())+" v:"+std::to_string(g())+" b:"+std::to_string(b()):d_name;
}
const std::vector<Color> Color::colors = {
        black, red, green,blue,
        white, yellow, purple, orange, cyan, pink, brown, gray, olive,
        lightBlue, darkGreen, gold, navy, indigo, teal, maroon, violet, turquoise, darkSlateGray,
        firebrick, darkGoldenrod, sienna, mediumVioletRed, darkOliveGreen, mediumOrchid, darkSlateBlue, saddleBrown, darkCyan, darkMagenta,
        mediumPurple, coral, darkOrange, mediumSeaGreen, royalBlue, darkKhaki, darkSalmon, lightSlateGray, mediumTurquoise, lightCoral
};

cv::Vec3b Color::getVec3b() const {
    uchar blue = cv::saturate_cast<uchar>(d_b);
    uchar green = cv::saturate_cast<uchar>(d_g);
    uchar red = cv::saturate_cast<uchar>(d_r);

    return cv::Vec3b(blue, green, red);
}
