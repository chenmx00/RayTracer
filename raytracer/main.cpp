//
//  main.cpp
//  raytracer
//
//  Created by Minxing Chen on 8/26/20.
//  Copyright © 2020 Minxing Chen. All rights reserved.
//

#include <iostream>
#include "color.hpp"
#include "vec3.hpp"
#include "ray.hpp"


int main(int argc, const char * argv[]) {
    // Image size
    const int image_width = 256;
    const int image_height = 256;
    
    //Render
    std::cout << "p3\n" << image_width << ' ' << image_height << "\n255\n";
    
    for(int j = image_height -1; j >=0; --j){
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for(int i = 0; i < image_width; ++i){
            color pixel_color(double(i)/(image_width-1), double(j)/(image_height-1), 0.25);
            write_color(std::cout, pixel_color);
        }
        
    }
    std::cerr << "\nDone. \n";
}
