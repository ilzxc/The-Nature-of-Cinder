//
//  Spring.h
//  Ex37Spring
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef Ex37Spring_Spring_h
#define Ex37Spring_Spring_h

#include "cinder/gl/gl.h"
#include "Bob.h"

using namespace ci;

class Spring {
    
public:
    Spring( const float x, const float y, const float length_ );
    
    void update( Bob& b, float minLength, float maxLength );
    void draw( const Bob& b) const;
    
private:
    const Vec2f anchor;
    float length;
    const float k;
};

#endif
