//
// Created by Alexander Shagarov on 10/01/2022.
//

#include <cmath>
#include "sphere.h"
#include "ray.h"

bool sphere::hit(const ray &r, double tMin, double tMax, hitRecord &rec) const {
    vec3 oc = r.origin() - Center;
    auto a = r.direction().lengthSquared();
    auto halfB = dot(oc, r.direction());
    auto c = oc.lengthSquared() - Radius * Radius;
    auto discriminant = halfB * halfB - a * c;

    if (discriminant < 0) {
        return false;
    }
    auto sqrtd = sqrt(discriminant);

    auto root = (-halfB - sqrtd) / a;
    if (root < tMin || tMax < root) {
        root = (-halfB + sqrtd) / a;
        if (root < tMin || tMax < root) {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(root);
    vec3 outwardNormal = (rec.p - Center) / Radius;
    rec.setFaceNormal(r, outwardNormal);
    rec.matPtr = MatPtr;

    return true;
}
