//
// Created by Alexander Shagarov on 11/01/2022.
//

#ifndef INC_01_PPM_IMAGE_MATERIAL_H
#define INC_01_PPM_IMAGE_MATERIAL_H

#include "vec3.h"

class ray;
class hitRecord;

class material {
public:
    virtual bool scatter(const ray& rIn, const hitRecord& rec, color& attenuation, ray& scattered) const = 0;
    ~material() = default;
};


#endif //INC_01_PPM_IMAGE_MATERIAL_H
