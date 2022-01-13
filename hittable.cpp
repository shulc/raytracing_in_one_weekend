//
// Created by Alexander Shagarov on 10/01/2022.
//

#include "hittable.h"
#include "ray.h"

void hitRecord::setFaceNormal(const ray &r, const vec3 &outwardNormal) {
    frontFace = dot(r.direction(), outwardNormal) < 0;
    normal = frontFace ? outwardNormal : - outwardNormal;
}
