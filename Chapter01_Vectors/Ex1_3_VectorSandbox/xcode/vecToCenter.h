//
//  vecToCenter.h
//  Ex1_3_VectorSandbox
//
//  Created by Ilya Rostovtsev on 4/7/13.
//
//

#ifndef Ex1_3_VectorSandbox_vecToCenter_h
#define Ex1_3_VectorSandbox_vecToCenter_h

#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include "cinder/gl/gl.h"

class vecToCenter {
  public:
    bool active;
    float magnitude;
    ci::Vec2f centerPoint;
    ci::Vec2f endPoint;
    
    vecToCenter( bool );
    void setCenterPoint( ci::Vec2f );
    void update( ci::Vec2f );
    void draw();
};


#endif
