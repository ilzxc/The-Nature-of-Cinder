//
//  Spring.h
//  Ex37Spring
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#ifndef Ex37Spring_Spring_h
#define Ex37Spring_Spring_h

#include "cinder/gl/gl.h"
#include "Bob.h"

using namespace ci;

class Spring {
private:
    Vec2f anchor;
    float length;
    float k;
    
public:
    Spring() {}
    Spring( float x, float y, float l )
    : anchor( x, y ),
      length( l ),
      k( 0.2f ) { }
    void update( Bob& b, float minLength, float maxLength );
    void draw( const Bob& b) const;
};

#endif
