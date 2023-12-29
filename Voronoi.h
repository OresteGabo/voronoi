//
// Created by oreste on 28/12/23.
//
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#ifndef DIAGRAMMEVORONOI_VORONOI_H
#define DIAGRAMMEVORONOI_VORONOI_H
#include<vector>
#include"Position.h"
#include <random>
#include <algorithm>
#include<iostream>
using namespace std;

class Voronoi {
    vector<Position> d_positions;
    Position d_boundary;
public:
    explicit Voronoi(const vector<Position> &dPositions,const Position &boundary);
    void display()const;
    cv::Mat generateVoronoiImage() const;

    static vector<Position>generatePositions(int);
    cv::Mat approximateImageWithVoronoi() const;
    cv::Mat adaptiveApproximateImageWithVoronoi() const;

private:
    int random(int min,int max)const;
    void shuffleIndex(vector<int>&data)const;
    void shufflePositions();
};
#endif //DIAGRAMMEVORONOI_VORONOI_H