//
// Created by Alexander Shagarov on 09/01/2022.
//

#ifndef INC_01_PPM_IMAGE_RAY_H
#define INC_01_PPM_IMAGE_RAY_H

#include "vec3.h"

class ray {
public:
    ray() = default;
    ray(const point3& origin, const vec3& direction) : Origin(origin), Direction(direction) {}

    point3 origin() const { return Origin; }
    vec3 direction() const { return Direction; }

    point3 at(double t) const;

public:
    point3 Origin;
    vec3 Direction;
};


#endif //INC_01_PPM_IMAGE_RAY_H
