//
// Created by oreste on 28/12/23.
//


#include "Voronoi.h"

Voronoi::Voronoi(const vector<Position> &dPositions, const Position &boundary) :
d_positions(dPositions),d_boundary(boundary) {
    shufflePositions();
}

void Voronoi::shufflePositions() {
    srand(time(0));

    std::vector<int> colorIndices(Color::colors.size());
    for (int i = 0; i < Color::colors.size(); ++i) {
        colorIndices[i] = i;
    }
    shuffleIndex(colorIndices);

    for(int i=0;i<d_positions.size();i++){
        d_positions[i].color(Color::colors[colorIndices[i]]);
        d_positions[i].x(random(0,d_boundary.x()));
        d_positions[i].y(random(0,d_boundary.y()));
    }
}
int Voronoi::random(int min,int max)const{
    if (min > max)
        std::swap(min, max);
    return min + rand() % (max - min + 1);
}

void Voronoi::shuffleIndex(vector<int>& data)const{
    vector<int>shuffledData(0);
    while(data.size()>0){
        int index=random(0,data.size()-1);
        int val=data[index];
        data.erase(data.begin()+index);
        shuffledData.push_back(val);
    }
    data=shuffledData;
}
void Voronoi::display()const{
    cout<<"Voronoi boundaries are"<<d_boundary.toString()<<endl<<endl;
    for(int i=0;i<d_positions.size();i++){
        cout<<"Pos "<<i<<" :color: "<<d_positions[i].color().toString()<<d_positions[i].toString()<<endl;
    }
}

cv::Mat Voronoi::generateVoronoiImage() const {
    // Create a black image as the background
    //cv::Mat voronoiImage = cv::Mat::zeros(height, width, CV_8UC3);
    cv::Mat voronoiImage = cv::Mat::zeros(d_boundary.y(), d_boundary.x(), CV_8UC3);

    // Iterate over each pixel in the image
    for (int y = 0; y < d_boundary.y(); ++y) {
        for (int x = 0; x < d_boundary.x(); ++x) {
            // Find the nearest seed point (d_position) based on distance
            Position currentPixel(x, y);
            int nearestIndex = 0;
            double minDistance = d_boundary.distance(currentPixel);

            for (int i = 1; i < d_positions.size(); ++i) {
                double distance = d_positions[i].distance(currentPixel);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestIndex = i;
                }
            }

            // Assign the color of the nearest seed point to the current pixel
            cv::Vec3b color = d_positions[nearestIndex].color().getVec3b();
            voronoiImage.at<cv::Vec3b>(y, x) = color;
        }
    }
    return voronoiImage;
}
#include <opencv2/opencv.hpp>
#include "Voronoi.h"

cv::Mat Voronoi::approximateImageWithVoronoi() const {
    // Step 1: Calculate the Voronoi diagram using the existing seed points
    cv::Mat voronoiImage = generateVoronoiImage();

    // Step 2: Associate the average color to each region
    cv::Mat approximatedImage = cv::Mat::zeros(d_boundary.y(), d_boundary.x(), CV_8UC3);

    for (int i = 0; i < d_positions.size(); ++i) {
        // Find the pixels belonging to the Voronoi region of the seed point
        std::vector<cv::Point> regionPixels;
        for (int y = 0; y < d_boundary.y(); ++y) {
            for (int x = 0; x < d_boundary.x(); ++x) {
                if (voronoiImage.at<cv::Vec3b>(y, x) == d_positions[i].color().getVec3b()) {
                    regionPixels.push_back(cv::Point(x, y));
                }
            }
        }

        // Calculate the average color in the region
        cv::Vec3d totalColor(0, 0, 0);
        for (const auto& pixel : regionPixels) {
            totalColor += voronoiImage.at<cv::Vec3b>(pixel);
        }

        //cv::Vec3b averageColor(totalColor[0] / regionPixels.size(), totalColor[1] / regionPixels.size(), totalColor[2] / regionPixels.size());
        int average=(totalColor[0]+totalColor[1]+totalColor[2])/regionPixels.size();
        cv::Vec3b averageColor(average,average,average);
        // Assign the average color to the entire region in the approximated image
        for (const auto& pixel : regionPixels) {
            approximatedImage.at<cv::Vec3b>(pixel) = averageColor;
        }
    }

    return approximatedImage;
}


cv::Mat Voronoi::adaptiveApproximateImageWithVoronoi() const {
    // Step 1: Generate a small number of random seed points
    int numSeedPoints = 2 * d_boundary.x() / 1000; // Adjust as needed
    vector<Position> adaptiveSeedPoints = generatePositions(numSeedPoints);

    // Step 2: Calculate the Voronoi diagram using the adaptive seed points
    Voronoi adaptiveVoronoi(adaptiveSeedPoints, d_boundary);
    cv::Mat voronoiImage = adaptiveVoronoi.generateVoronoiImage();

    // Step 3: Associate the average grayscale value to each region
    cv::Mat approximatedImage = cv::Mat::zeros(d_boundary.y(), d_boundary.x(), CV_8UC3);

    for (int i = 0; i < adaptiveVoronoi.d_positions.size(); ++i) {
        // Find the pixels belonging to the Voronoi region of the seed point
        std::vector<cv::Point> regionPixels;
        for (int y = 0; y < d_boundary.y(); ++y) {
            for (int x = 0; x < d_boundary.x(); ++x) {
                if (voronoiImage.at<cv::Vec3b>(y, x) == adaptiveVoronoi.d_positions[i].color().getVec3b()) {
                    regionPixels.push_back(cv::Point(x, y));
                }
            }
        }

        // Step 4: Calculate the variance of grayscale values
        cv::Vec3d totalColor(0, 0, 0);
        for (const auto& pixel : regionPixels) {
            totalColor += voronoiImage.at<cv::Vec3b>(pixel);
        }

        cv::Vec3b averageColor(totalColor[0] / regionPixels.size(), totalColor[1] / regionPixels.size(), totalColor[2] / regionPixels.size());

        // Assign the average color to the entire region in the approximated image
        for (const auto& pixel : regionPixels) {
            approximatedImage.at<cv::Vec3b>(pixel) = averageColor;
        }

        // Step 5: Identify homogeneous regions based on variance threshold
        cv::Mat regionGrayscale;
        cv::cvtColor(approximatedImage, regionGrayscale, cv::COLOR_BGR2GRAY);

        cv::Mat mean, stddev;
        //cv::Mat mean;
        cv::meanStdDev(regionGrayscale, mean, stddev);

        // Define a threshold value (seuil)
        double seuil = 30.0; // Adjust as needed

        // A region is considered homogeneous if V < seuil
       ///TODO A faire
        //if (stddev < seuil) {

       // }
    }

    return approximatedImage;
}

/*
void Voronoi::displayVoronoiImage(const cv::Mat& voronoiImage, const std::string& windowName) const {
    // Display the Voronoi diagram image
    cv::imshow(windowName, voronoiImage);
    cv::waitKey(0);
}
*/
vector<Position> Voronoi::generatePositions(int size){
    vector<Position> v(size);
    for(int i=0;i<size;i++){
        v[i]=Position();
    }
    return v;
}