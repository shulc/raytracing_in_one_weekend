//
// Created by Alexander Shagarov on 09/01/2022.
//
#include "vec3.h"
#include "misc.h"

#include <cmath>
#include <ostream>

vec3 &vec3::operator+=(const vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vec3 &vec3::operator*=(const double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vec3 &vec3::operator/=(const double t) {
    return *this *= 1 / t;
}

double vec3::length() const {
    return sqrt(lengthSquared());
}

double vec3::lengthSquared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

vec3 vec3::random() {
    return vec3(randomDouble(), randomDouble(), randomDouble());
}

vec3 vec3::random(double min, double max) {
    return vec3(randomDouble(min, max), randomDouble(min, max), randomDouble(min, max));
}

bool vec3::nearZero() const {
    constexpr auto s = 1e-8;
    return fabs(e[0]) < s && abs(e[1]) < s && abs(e[2]) < s;
}

std::ostream &operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << " " << v.e[1] << " " << v.e[2];
}

vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

vec3 operator*(double t, const vec3 &v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

vec3 operator/(const vec3 &v, double t) {
    return (1 / t) * v;
}

double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(
            u.e[1] * v.e[2] - u.e[2] * v.e[1],
            u.e[2] * v.e[0] - u.e[0] * v.e[2],
            u.e[0] * v.e[1] - u.e[1] * v.e[0]
            );
}

vec3 unitVector(vec3 v) {
    return v / v.length();
}

void writeColor(std::ostream &out, color pixelColor, int samplesPerPixel) {
    auto r = pixelColor.x();
    auto g = pixelColor.y();
    auto b = pixelColor.z();

    auto scale = 1.0 / samplesPerPixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);
    out
        << static_cast<int>(256 * clamp(r, 0, 0.999)) << " "
        << static_cast<int>(256 * clamp(g, 0, 0.999)) << " "
        << static_cast<int>(256 * clamp(b, 0, 0.999)) << "\n";
}

void normColor(color& pixelColor, int samplesPerPixel) {
    auto& r = pixelColor[0];
    auto& g = pixelColor[1];
    auto& b = pixelColor[2];

    auto scale = 1.0 / samplesPerPixel;
    r = sqrt(scale * r);
    g = sqrt(scale * g);
    b = sqrt(scale * b);
}

vec3 randomInUnitSphere() {
    while (true) {
        const auto p = vec3::random(-1, 1);
        if (p.lengthSquared() >= 1) {
            continue;
        }
        return p;
    }
}

vec3 randomUnitVector() {
    return unitVector(randomInUnitSphere());
}

vec3 randomInHemisphere(const vec3& normal) {
    const vec3 inUnitSphere = randomInUnitSphere();
    if (dot(inUnitSphere, normal) > 0.0) {
        return inUnitSphere;
    }
    return -inUnitSphere;
}

vec3 reflect(const vec3 &v, const vec3 &n) {
    return v - 2 * dot(v, n) * n;
}

vec3 refract(const vec3 &uv, const vec3 &n, double etaiOverEtat) {
    const auto cosTheta = std::min(dot(-uv, n), 1.0);
    const vec3 rOutPerp = etaiOverEtat * (uv + cosTheta * n);
    const vec3 rOutParallel = -sqrt(std::abs(1.0 - rOutPerp.lengthSquared())) * n;
    return rOutPerp + rOutParallel;
}

vec3 randomInUnitDisk() {
    while (true) {
        const auto p = vec3(randomDouble(-1, 1), randomDouble(-1, 1), 0);
        if (p.lengthSquared() >= 1) {
            continue;
        }
        return p;
    }
}
