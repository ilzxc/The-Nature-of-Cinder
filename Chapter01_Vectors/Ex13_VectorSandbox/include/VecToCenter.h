//
//  VecToCenter.h
//  Ex13_VectorSandbox
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//

#ifndef __Ex13_VectorSandbox__VecToCenter__
#define __Ex13_VectorSandbox__VecToCenter__

#include "cinder/gl/gl.h"

using namespace ci;

class VecToCenter {
  private:
    bool active;
    float magnitude;
    Vec2f centerPoint;
    Vec2f endPoint;
    
  public:
    VecToCenter() {}
    VecToCenter( const bool a, const Vec2f &c ): active(a), magnitude(0), centerPoint(c), endPoint( Vec2f::zero() ) {}
    ~VecToCenter(){}
    void setCenter( const Vec2f& newCenter );
    void setActive( const bool newActive );
    void update( Vec2f current );
    void draw();
};

#endif /* defined(__Ex13_VectorSandbox__VecToCenter__) */
