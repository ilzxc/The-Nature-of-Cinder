//
//  Pendulum.h
//  Ex36Pendulum
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//  HWH Maintenance 8/17/13
//

#ifndef Ex36Pendulum_Pendulum_h
#define Ex36Pendulum_Pendulum_h

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Math.h"

using namespace ci;

class Pendulum {
    
public:
    Pendulum( const Vec2f& origin_, const float arm_ );
    
    void update( const Vec2f& mouse );
    void draw() const;
    void clicked( const Vec2f& mouse );
    void stopDragging();
    
private:
    Vec2f location;
    const Vec2f origin;
    const float arm;
    float angle;
    float angleVelocity;
    float angleAcceleration;
    const float radius;
    const float damping;
    bool dragging;

};

#endif
