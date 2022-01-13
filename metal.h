//
// Created by Alexander Shagarov on 11/01/2022.
//

#ifndef INC_01_PPM_IMAGE_METAL_H
#define INC_01_PPM_IMAGE_METAL_H

#include "material.h"
#include "vec3.h"

class metal : public material {
public:
    metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

    bool scatter(
            const ray& rIn,
            const hitRecord& rec,
            color& attenuation,
            ray& scattered
            ) const override;

public:
    color albedo;
    double fuzz;
};


#endif //INC_01_PPM_IMAGE_METAL_H
