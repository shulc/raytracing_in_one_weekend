//
// Created by Alexander Shagarov on 10/01/2022.
//

#ifndef INC_01_PPM_IMAGE_HITTABLE_H
#define INC_01_PPM_IMAGE_HITTABLE_H

#include "vec3.h"
#include <memory>

class ray;
class material;

struct hitRecord {
    point3 p;
    vec3 normal;
    std::shared_ptr<material> matPtr;
    double t;
    bool frontFace;

    void setFaceNormal(const ray& r, const vec3& outwardNormal);
};



class hittable {
public:
    virtual bool hit(const ray& r, double tMin, double tMax, hitRecord& rec) const = 0;
    ~hittable() = default;
};


#endif //INC_01_PPM_IMAGE_HITTABLE_H
