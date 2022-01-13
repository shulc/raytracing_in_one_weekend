//
// Created by Alexander Shagarov on 10/01/2022.
//

#include <cmath>
#include "camera.h"
#include "misc.h"

camera::camera(
        point3 lookfrom,
        point3 lookat,
        vec3 vup,
        double vfov,
        double aspectRatio,
        double aperture,
        double focusDist
        ) {
    const double theta = degreesToRadians(vfov);
    const double h = tan(theta / 2);
    const double viewportHeigth = 2.0 * h;
    const double viewportWidth = aspectRatio * viewportHeigth;
    w = unitVector(lookfrom - lookat);
    u = unitVector(cross(vup, w));
    v = cross(w, u);

    constexpr auto focalLength = 1.0;

    Origin = lookfrom;
    Horizontal = focusDist * viewportWidth * u;
    Vertical = focusDist * viewportHeigth * v;
    LowerLeftCorner = Origin - Horizontal/2 - Vertical/2 - focusDist * w;
    lensRadius = aperture / 2;
}

ray camera::getRay(double s, double t) const {
    const vec3 rd = lensRadius * randomInUnitDisk();
    const vec3 offset = u * rd.x() + v * rd.y();
    return ray(
            Origin + offset,
            LowerLeftCorner + s * Horizontal + t * Vertical - Origin - offset);
}
