#include <opencv2/opencv.hpp>
#include "Voronoi.h"

int main() {
    // Create a Voronoi diagram for image approximation
    Voronoi voronoi = Voronoi(Voronoi::generatePositions(40), Position(1000, 1000));

    // Approximate the image using the Voronoi diagram
    cv::Mat approximatedImage = voronoi.approximateImageWithVoronoi();

    // Display the original (Voronoi) and approximated images
    cv::imshow("Voronoi Diagram", voronoi.generateVoronoiImage());
    cv::imshow("Approximated Image", approximatedImage);
    cv::imshow("adaptive Approximate Image", voronoi.adaptiveApproximateImageWithVoronoi());
    cv::waitKey(0);

    cout<<"Size of colors is "<<Color::colors.size();

    return 0;
}