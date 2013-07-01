//
//  square.h
//  oscar
//
//  Created by Ilya Rostovtsev on 5/14/13.
//
//

#ifndef __oscar__square__
#define __oscar__square__

#include "cinder/gl/gl.h"

class square {
  public:
    square();
    void update( float angle );
    void update( ci::Vec3f pigment );
    void draw();
    
    float rotation;
    cinder::Vec3f color;
};

#endif /* defined(__oscar__square__) */
