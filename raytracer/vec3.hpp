//
//  vec3.hpp
//  raytracer
//
//  Created by Minxing Chen on 9/26/20.
//  Copyright © 2020 Minxing Chen. All rights reserved.
//

#ifndef vec3_hpp
#define vec3_hpp

#include <stdio.h>
#include <cmath>
#include <iostream>
using std::sqrt;

class vec3 {
public:
    vec3(): e{0, 0, 0} {} //construtor with no parameters
    vec3(double e0, double e1, double e2): e{e0, e1, e2} {} //constructor with parameters
    double x() const {return e[0];}
    double y() const {return e[1];}
    double z() const {return e[2];}
    
    vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]);}
    double operator[] (int i) const {return e[i];}
    double& operator[] (int i) {return e[i];}
    
    vec3& operator+=(const vec3 &v){
        e[0] += v[0];
        e[1] += v[1];
        e[2] += v[2];
        return *this;
    }
    
    vec3& operator*=(const double t){
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }
    
    vec3& operator/=(const double t){
        return *this *= 1/t;
    }
    
    double length() const {
        return sqrt(length_squared());
    }
    
    double length_squared() const{
        return e[0]*e[0] + e[1]*e[1] +e[2]*e[2];
    }
    
    
    
public:
    double e[3];
        
};
using point3 = vec3;
using color  = vec3;

inline std::ostream& operator<<(std::ostream &out, const vec3 &v){
    return out << v.e[0] << ' ' << v.e[1] <<' '<<v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v){
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v){
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v){
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3 &u){
    return vec3(u.e[0] * t, u.e[1] * t, u.e[2] * t);
}

inline vec3 operator*(const vec3 &u, double t){
    return t * u;
}

inline vec3 operator/(vec3 u, double t) {
    return (1 / t) * u;
}

inline double dot(const vec3 &u, const vec3 &v){
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v){
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}
    
inline vec3 unit_vector(vec3 v){
    return v / v.length();
}



#endif /* vec3_hpp */


