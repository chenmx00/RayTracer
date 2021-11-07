//
//  hittable.hpp
//  raytracer
//
//  Created by Minxing Chen on 11/5/21.
//  Copyright © 2021 Minxing Chen. All rights reserved.
//

#ifndef hittable_hpp
#define hittable_hpp

#include "ray.hpp"
struct hit_record {
    point3 p;
    vec3 normal;
    double t;
    bool front_face;
    inline void set_face_normal(const ray& r, const vec3& outward_normal){
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face? outward_normal : -outward_normal;
    }
};

class hittable {
public:
    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const = 0;
};


#endif /* hittable_hpp */
