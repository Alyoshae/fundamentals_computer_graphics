#pragma once
#include "vec3.h"

class ray {
public:
    ray() {}
    ray(const point3& origen, const vec3& direccion) 
        : orig(origen), dir(direccion) {}

    point3 origin() const { return orig; }
    vec3 direction() const { return dir; }

    point3 at(double t) const {
        return orig + t * dir;
    }

private:
    point3 orig;
    vec3 dir;
};