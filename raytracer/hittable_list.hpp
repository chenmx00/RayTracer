//
//  hittable_list.hpp
//  raytracer
//
//  Created by Minxing Chen on 11/6/21.
//  Copyright © 2021 Minxing Chen. All rights reserved.
//

#ifndef hittable_list_hpp
#define hittable_list_hpp
#include "hittable.hpp"
#include <memory>
#include <vector>
using std::shared_ptr;
using std::make_shared;
class hittable_list : public hittable {
public:
    hittable_list(){}
    hittable_list(shared_ptr<hittable> object){add(object);}
    void clear(){objects.clear();}
    void add(shared_ptr<hittable> object){objects.push_back(object);}
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record &rec) const override;
public:
    std::vector<shared_ptr<hittable>> objects;
    
};

bool hittable_list::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    auto closet_so_far = t_max;
    for (const auto& object : objects){
        if (object->hit(r, t_min, closet_so_far, temp_rec)){
            hit_anything = true;
            closet_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}



#endif /* hittable_list_hpp */
