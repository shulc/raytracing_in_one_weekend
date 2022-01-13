//
// Created by Alexander Shagarov on 12/01/2022.
//

#ifndef INC_01_PPM_IMAGE_IMAGE_H
#define INC_01_PPM_IMAGE_IMAGE_H

#include "vec3.h"
#include <vector>
#include <ostream>
#include <span>

class image {
public:
    image(int width, int height) : Data(width * height), Width(width), Height(height) {}
    void save(std::ostream& out) const;
    color& at(int x, int y);
    const color& at(int x, int y) const;

public:
    std::vector<color> Data;
    int Width;
    int Height;
};

#endif //INC_01_PPM_IMAGE_IMAGE_H
