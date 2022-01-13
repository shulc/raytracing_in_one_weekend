//
// Created by Alexander Shagarov on 11/01/2022.
//

#ifndef INC_01_PPM_IMAGE_LAMBERTIAN_H
#define INC_01_PPM_IMAGE_LAMBERTIAN_H

#include "material.h"
#include "vec3.h"

class lambertian : public material {
public:
    lambertian(const color& a) : albedo(a) {}

    bool scatter(const ray& rIn, const hitRecord& rec, color& attenuation, ray& scattered) const override;

public:
    color albedo;
};


#endif //INC_01_PPM_IMAGE_LAMBERTIAN_H
