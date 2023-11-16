cmake_minimum_required(VERSION 3.5)
project(HazeRemoval)

find_package(OpenCV REQUIRED)

add_executable(HazeRemoval 
    src/guidedfilter.h
    src/guidedfilter.cpp
    src/hazeremoval.h
    src/hazeremoval.cpp
    src/main.cpp
)
target_link_libraries(HazeRemoval ${OpenCV_LIBRARIES})
