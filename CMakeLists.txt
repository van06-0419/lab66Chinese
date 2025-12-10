cmake_minimum_required(VERSION 3.30)
project(VectorEditor CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(VectorEditor
    src/Document.cpp
    src/EditorController.cpp
    src/EditorView.cpp
    src/main.cpp
)

target_include_directories(VectorEditor PRIVATE include)