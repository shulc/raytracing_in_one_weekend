//
// Created by Alexander Shagarov on 11/01/2022.
//

#include "metal.h"
#include "ray.h"
#include "hittable.h"

bool metal::scatter(const ray &rIn, const hitRecord &rec, color &attenuation, ray &scattered) const {
    const vec3 reflected = reflect(unitVector(rIn.direction()), rec.normal);
    scattered = ray(rec.p, reflected + fuzz * randomInUnitSphere());
    attenuation = albedo;
    return dot(scattered.direction(), rec.normal) > 0;
}
