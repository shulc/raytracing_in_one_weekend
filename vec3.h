//
// Created by Alexander Shagarov on 09/01/2022.
//

#ifndef INC_01_PPM_IMAGE_VEC3_H
#define INC_01_PPM_IMAGE_VEC3_H

#include <ostream>

class vec3 {
public:
    vec3() = default;
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    double x() const { return e[0];}
    double y() const { return e[1];}
    double z() const { return e[2];}

    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    vec3& operator+=(const vec3& v);
    vec3& operator*=(const double t);
    vec3& operator/=(const double t);

    static vec3 random();
    static vec3 random(double min, double max);
    bool nearZero() const;

    double length() const;
    double lengthSquared() const;

public:
    double e[3] = {0, 0, 0};
};

using point3 = vec3;
using color = vec3;

std::ostream& operator<<(std::ostream& out, const vec3& v);
vec3 operator+(const vec3 &u, const vec3 &v);
vec3 operator-(const vec3 &u, const vec3 &v);
vec3 operator*(const vec3 &u, const vec3 &v);
vec3 operator*(double t, const vec3 &v);
vec3 operator*(const vec3 &v, double t);
vec3 operator/(const vec3 &v, double t);

double dot(const vec3& u, const vec3& v);
vec3 cross(const vec3& u, const vec3& v);
vec3 reflect(const vec3& v, const vec3& n);
vec3 refract(const vec3& v, const vec3& n, double etaiOverEtat);

vec3 unitVector(vec3 v);

vec3 randomInUnitSphere();
vec3 randomUnitVector();
vec3 randomInHemisphere(const vec3& normal);
vec3 randomInUnitDisk();

void writeColor(std::ostream& out, color pixelColor, int samplesPerPixel);
void normColor(color& pixelColor, int samplesPerPixel);

#endif //INC_01_PPM_IMAGE_VEC3_H
