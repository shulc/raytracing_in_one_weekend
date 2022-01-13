//
// Created by Alexander Shagarov on 10/01/2022.
//

#ifndef INC_01_PPM_IMAGE_MISC_H
#define INC_01_PPM_IMAGE_MISC_H

#include <limits>

constexpr double infinity = std::numeric_limits<double>::infinity();
constexpr double pi =  3.1415926535897932385;

inline double degreesToRadians(double degrees) {
    return degrees * pi / 180.0;
}

double randomDouble();

inline double randomDouble(double min, double max) {
    return min + (max - min) * randomDouble();
}

inline double clamp(double x, double min, double max) {
    if (x < min) {
        return min;
    }
    if (x > max) {
        return max;
    }
    return x;
}

#endif //INC_01_PPM_IMAGE_MISC_H
