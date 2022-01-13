//
// Created by Alexander Shagarov on 10/01/2022.
//

#ifndef INC_01_PPM_IMAGE_HITTABLE_LIST_H
#define INC_01_PPM_IMAGE_HITTABLE_LIST_H


#include "hittable.h"
#include <vector>
#include <memory>

class hittable_list : public hittable {
public:
    void clear();
    void add(std::shared_ptr<hittable> object);
    bool hit(const ray& r, double tMin, double tMax, hitRecord& rec) const final;

public:
    std::vector<std::shared_ptr<hittable>> Objects;
};


#endif //INC_01_PPM_IMAGE_HITTABLE_LIST_H
