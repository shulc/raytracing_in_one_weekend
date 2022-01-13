//
// Created by Alexander Shagarov on 11/01/2022.
//

#include "lambertian.h"
#include "hittable.h"
#include "ray.h"

bool lambertian::scatter(const ray &rIn, const hitRecord &rec, color &attenuation, ray &scattered) const {
    auto scatterDirection = rec.normal + randomUnitVector();

    if (scatterDirection.nearZero()) {
        scatterDirection = rec.normal;
    }

    scattered = ray(rec.p, scatterDirection);
    attenuation = albedo;
    return true;
}
