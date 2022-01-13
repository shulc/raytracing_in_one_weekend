//
// Created by Alexander Shagarov on 12/01/2022.
//

#include <cmath>
#include "misc.h"
#include "dielectic.h"
#include "hittable.h"
#include "ray.h"

bool dielectic::scatter(const ray &rIn, const hitRecord &rec, color &attenuation, ray &scattered) const {
    attenuation = color(1.0, 1.0, 1.0);
    const double refractionRatio = rec.frontFace ? (1.0/ir) : ir;

    const vec3 unitDirection = unitVector(rIn.direction());
    const double cosTheta = std::min(dot(-unitDirection, rec.normal), 1.0);
    const double sinTheta = sqrt(1.0 - cosTheta * cosTheta);

    const bool cannotRefract = refractionRatio * sinTheta > 1.0 || reflectance(cosTheta, refractionRatio) > randomDouble();
    const vec3 direction = cannotRefract ? reflect(unitDirection, rec.normal) : refract(unitDirection, rec.normal, refractionRatio);

    scattered = ray(rec.p, direction);
    return true;
}

double dielectic::reflectance(double cosine, double refIdx) {
    // Use Schlick's approximation for reflectance.
    double r0 = (1 - refIdx) / (1 + refIdx);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow(1 - cosine, 5);

}
