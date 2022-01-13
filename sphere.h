//
// Created by Alexander Shagarov on 10/01/2022.
//

#ifndef INC_01_PPM_IMAGE_SPHERE_H
#define INC_01_PPM_IMAGE_SPHERE_H

#include "hittable.h"

class sphere : public hittable {
public:
    sphere(point3 center, double radius, std::shared_ptr<material> m) : Center(center), Radius(radius), MatPtr(m) {}
    virtual bool hit(const ray& r, double tMin, double tMax, hitRecord& rec) const final;

public:
    point3 Center;
    double Radius;
    std::shared_ptr<material> MatPtr;
};


#endif //INC_01_PPM_IMAGE_SPHERE_H
