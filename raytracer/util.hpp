//
//  util.hpp
//  raytracer
//
//  Created by Minxing Chen on 11/6/21.
//  Copyright © 2021 Minxing Chen. All rights reserved.
//

#ifndef util_h
#define util_h
#include <cmath>
#include <memory>
#include <limits>
#include <cstdlib>
//comon headers
#include "ray.hpp"
#include "vec3.hpp"

//usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

//constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//util funcs
inline double degree_to_radians(double degree){
    return degree * pi / 180.0;
}

inline double random_double(){
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max){
    return min + (max-min) * random_double();
}

inline double clamp(double x, double min, double max){
    if (x < min) return min;
    if (x > max) return max;
    return x;
}




#endif /* util_h */
