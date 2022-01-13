//
// Created by Alexander Shagarov on 10/01/2022.
//

#ifndef INC_01_PPM_IMAGE_CAMERA_H
#define INC_01_PPM_IMAGE_CAMERA_H

#include "vec3.h"
#include "ray.h"

class camera {
public:
    camera(
            point3 lookfrom,
            point3 lookat,
            vec3 vup,
            double vfov,
            double aspectRatio,
            double aperture,
            double focusDist
            );

    ray getRay(double u, double v) const;

public:
    point3 Origin;
    point3 LowerLeftCorner;
    vec3 Horizontal;
    vec3 Vertical;
    vec3 u;
    vec3 v;
    vec3 w;
    double lensRadius;
};


#endif //INC_01_PPM_IMAGE_CAMERA_H
