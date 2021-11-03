//
//  ray.hpp
//  raytracer
//
//  Created by Minxing Chen on 9/27/20.
//  Copyright © 2020 Minxing Chen. All rights reserved.
//

#ifndef ray_hpp
#define ray_hpp

#include <stdio.h>
#include "vec3.hpp"

class ray{
public:
    ray(){}
    ray(const point3& origin, const vec3& direction)
        : orig(origin), dir(direction)
    {}
    
    point3 origin() const {return orig;}
    vec3 direction() const {return dir;}
    
    point3 at(double t) const {
        return orig + t*dir;
    }
    
public:
    point3 orig;
    vec3 dir;
};
#endif /* ray_hpp */
