//
//  Pendulum.h
//  Ex36Pendulum
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#ifndef Ex36Pendulum_Pendulum_h
#define Ex36Pendulum_Pendulum_h

#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Math.h"

#define PI 3.141592653589793f

using namespace ci;

class Pendulum {
private:
    Vec2f location;
    Vec2f origin;
    float arm;
    float angle;
    float angleVelocity;
    float angleAcceleration;
    float radius;
    float damping;
    bool dragging;
    
public:
    Pendulum() { }
    Pendulum( const Vec2f& origin_, const float arm_ )
    : location( Vec2f::zero() ),
      origin( origin_ ),
      arm( arm_ ),
      angle( PI / 4.0 ),
      angleVelocity( 0.0f ),
      angleAcceleration( 0.0f ),
      radius( 24.0f ),
      damping( 0.995f ),
      dragging( false ) { }
    
    void update( const Vec2f& mouse );
    void draw() const;
    void clicked( const Vec2f& mouse );
    void stopDragging();
};

#endif
