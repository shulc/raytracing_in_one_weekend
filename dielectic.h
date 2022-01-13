//
// Created by Alexander Shagarov on 12/01/2022.
//

#ifndef INC_01_PPM_IMAGE_DIELECTIC_H
#define INC_01_PPM_IMAGE_DIELECTIC_H

#include "material.h"
#include "vec3.h"

class dielectic : public material {
public:
    explicit dielectic(double indexOfRefraction) : ir(indexOfRefraction) {}
    bool scatter(
            const ray& rIn,
            const hitRecord& rec,
            color& attenuation,
            ray& scattered
            ) const override;
public:
    double ir; // Index of Refraction

private:
    static double reflectance(double cosine, double refIdx);

};


#endif //INC_01_PPM_IMAGE_DIELECTIC_H
