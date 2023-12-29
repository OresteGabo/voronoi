cmake_minimum_required(VERSION 3.26)
project(diagrammeVoronoi)

set(CMAKE_CXX_STANDARD 17)

# Find the OpenCV package
find_package(OpenCV REQUIRED)

add_executable(diagrammeVoronoi main.cpp
        Position.cpp
        Position.h
        Color.cpp
        Color.h
        Voronoi.cpp
        Voronoi.h
)

# Link OpenCV to your executable
target_link_libraries(diagrammeVoronoi ${OpenCV_LIBS})