//
//  color.hpp
//  raytracer
//
//  Created by Minxing Chen on 9/26/20.
//  Copyright © 2020 Minxing Chen. All rights reserved.
//

#ifndef color_hpp
#define color_hpp

#include <stdio.h>
#include <iostream>
#include "vec3.hpp"
void write_color(std::ostream &out, color pixel_color) {
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}
#endif /* color_hpp */
