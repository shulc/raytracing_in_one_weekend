//
// Created by Alexander Shagarov on 09/01/2022.
//

#include "ray.h"

point3 ray::at(double t) const {
    return Origin + t * Direction;
}
