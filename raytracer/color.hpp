//
//  color.hpp
//  raytracer
//
//  Created by Minxing Chen on 9/26/20.
//  Copyright © 2020 Minxing Chen. All rights reserved.
//

#ifndef color_hpp
#define color_hpp

#include <iostream>
#include "vec3.hpp"
void write_color(std::ostream &out, color pixel_color, int sample_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();
    auto scale = 1.0 / sample_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;
    
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}
#endif /* color_hpp */
