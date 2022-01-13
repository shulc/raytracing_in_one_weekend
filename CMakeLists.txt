cmake_minimum_required(VERSION 3.21)
project(01_ppm_image)

set(CMAKE_CXX_STANDARD 20)

add_executable(01_ppm_image main.cpp vec3.cpp vec3.h ray.cpp ray.h hittable.cpp hittable.h sphere.cpp sphere.h hittable_list.cpp hittable_list.h misc.cpp misc.h camera.cpp camera.h misc.cpp material.cpp material.h lambertian.cpp lambertian.h metal.cpp metal.h dielectic.cpp dielectic.h image.cpp image.h)
