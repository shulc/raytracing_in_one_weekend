//
// Created by Alexander Shagarov on 10/01/2022.
//

#include "hittable_list.h"

void hittable_list::clear() {
    Objects.clear();
}

void hittable_list::add(std::shared_ptr<hittable> object) {
    Objects.push_back(object);
}

bool hittable_list::hit(const ray &r, double tMin, double tMax, hitRecord &rec) const {
    hitRecord tempRec;
    bool hitAnithing = false;
    auto closestSoFar = tMax;

    for (const auto& object : Objects) {
        if (object->hit(r, tMin, closestSoFar, tempRec)) {
            hitAnithing = true;
            closestSoFar = tempRec.t;
            rec = tempRec;
        }
    }

    return hitAnithing;
}
