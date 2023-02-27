cmake_minimum_required(VERSION 3.4...3.18)

project(PySarInterpolation)
add_subdirectory(third_party)
#find_package(SarInterpolation REQUIRED)
#find_package(Eigen3 REQUIRED)
find_package(pybind11 REQUIRED)
pybind11_add_module(PySarInterpolation src/interpolation_py.cpp)

include_directories(${SarInterpolation_INCLUDE_DIR})

target_link_libraries(PySarInterpolation PUBLIC interpolation)
# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(PySarInterpolation
                           PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
