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
    Spring( const float _x, const float _y, const float _length );
    void update( Bob& b, float minLength, float maxLength );
    void draw( const Bob& b) const;
    
private:
    Vec2f anchor;
    float length;
    const float k;
};

#endif
