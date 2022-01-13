#include "vec3.h"
#include "ray.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "misc.h"
#include "camera.h"
#include "material.h"
#include "lambertian.h"
#include "dielectic.h"
#include "metal.h"
#include "image.h"

#include "thread_pool.hpp"

#include <iostream>
#include <cmath>
#include <memory>
#include <thread>

color ray_color(const ray& r, const hittable& world, int depth) {
    if (!depth) {
        return color(0, 0, 0);
    }

    hitRecord rec;
    if (world.hit(r, 0.00001, infinity, rec)) {
        ray scattered;
        color attenuation;
        if (rec.matPtr->scatter(r, rec, attenuation, scattered)) {
            return attenuation * ray_color(scattered, world, depth - 1);
        }
        return color(0, 0, 0);
    }
    vec3 unitDirection = unitVector(r.direction());
    auto t = 0.5 * (unitDirection.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

hittable_list randomScene() {
    hittable_list world;

    const auto groundMaterial = std::make_shared<lambertian>(color(0.5, 0.5, 0.5));
    world.add(std::make_shared<sphere>(point3(0, -1000, 0), 1000, groundMaterial));

    for (int a = -11; a < 11; ++a) {
        for (int b = -11; b < 11; ++b) {
            const double chooseMat = randomDouble();
            point3 center(
                    a + 0.9 * randomDouble(),
                    0.2,
                    b + 0.9 * randomDouble()
            );

            if ((center - point3(4, 0.2, 0)).length() > 0.9) {
                std::shared_ptr<material> sphereMaterial;

                if (chooseMat < 0.8) {
                    // diffuse
                    const color albedo = color::random() * color::random();
                    sphereMaterial = std::make_shared<lambertian>(albedo);
                } else if (chooseMat < 0.95) {
                    // metal
                    const color albedo = color::random(0.5, 1);
                    const double fuzz = randomDouble(0, 0.5);
                    sphereMaterial = std::make_shared<metal>(albedo, fuzz);
                } else {
                    // glass
                    sphereMaterial = std::make_shared<dielectic>(1.5);
                }
                world.add(std::make_shared<sphere>(center, 0.2, sphereMaterial));
            }
        }
    }

    const auto material1 = std::make_shared<dielectic>(1.5);
    world.add(std::make_shared<sphere>(point3(0, 1, 0), 1.0, material1));

    const auto material2 = std::make_shared<lambertian>(color(0.4, 0.2, 0.1));
    world.add(std::make_shared<sphere>(point3(-4, 1, 0), 1.0, material2));

    const auto material3 = std::make_shared<metal>(color(0.7, 0.6, 0.5), 0.0);
    world.add(std::make_shared<sphere>(point3(4, 1, 0), 1.0, material3));

    return world;
}

int main() {
    // std::cout << "num threads: " << std::thread::hardware_concurrency() << "\n";
    constexpr int tileSize = 32;

    constexpr double aspectRatio = 3.0 / 2.0;
    constexpr int imageWidth = 480;
    constexpr int imageHeight = static_cast<int>(imageWidth / aspectRatio);
    constexpr int samplesPerPixel = 1 << 8;
    constexpr int maxDepth = 50;

    hittable_list world = randomScene();

    const point3 lookfrom(13, 2, 3);
    const point3 lookat(0, 0, 0);
    const vec3 vup(0, 1, 0);
    const double distToFocus = 10.0;
    const double aperture = 0.1;

    camera cam(
            lookfrom,
            lookat,
            vup,
            20,
            aspectRatio,
            aperture,
            distToFocus
            );

    image img(imageWidth, imageHeight);

    thread_pool pool;

    auto render = [&](const int begin, const int end) {
        for (int j = begin; j < end; ++j) {
            for (int i = 0; i < imageWidth; ++i) {
                color &pixelColor = img.at(i, j);
                for (int s = 0; s < samplesPerPixel; ++s) {
                    auto u = (i + randomDouble()) / (imageWidth - 1);
                    auto v = (j + randomDouble()) / (imageHeight - 1);
                    ray r = cam.getRay(u, v);
                    pixelColor += ray_color(r, world, maxDepth);
                }
                normColor(pixelColor, samplesPerPixel);
            }
        }
    };

    pool.parallelize_loop(0, imageHeight, render, imageHeight / tileSize);
    img.save(std::cout);

    std::cerr << "\nDone.\n";
    return 0;
}
