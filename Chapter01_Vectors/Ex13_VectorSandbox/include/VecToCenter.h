//
//  VecToCenter.h
//  Ex13_VectorSandbox
//
//  Created by Ilya Rostovtsev on 7/3/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef __Ex13_VectorSandbox__VecToCenter__
#define __Ex13_VectorSandbox__VecToCenter__

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;

class VecToCenter {
public:
    VecToCenter() {}
    VecToCenter( const bool _active, const Vec2f& _centerPoint );

    void setCenter( const Vec2f& newCenter );
    void setActive( const bool newActive );
    void update( const Vec2f& current );
    void draw();
    
private:
    bool active;
    float magnitude;
    Vec2f centerPoint;
    Vec2f endPoint;
};

#endif /* defined(__Ex13_VectorSandbox__VecToCenter__) */
