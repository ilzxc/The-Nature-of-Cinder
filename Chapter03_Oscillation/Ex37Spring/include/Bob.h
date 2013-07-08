//
//  Bob.h
//  Ex37Spring
//
//  Created by Ilya Rostovtsev on 7/8/13.
//
//

#ifndef Ex37Spring_Bob_h
#define Ex37Spring_Bob_h

#include "cinder/gl/gl.h"

using namespace ci;

class Bob {
private:
    Vec2f location;
    Vec2f velocity;
    Vec2f acceleration;
    float mass;
    float damping;
    Vec2f dragOffset;
    bool dragging;
    
public:
    Bob(){ }
    Bob( float x, float y )
    : location( x, y ),
    velocity( Vec2f::zero() ),
    acceleration( Vec2f::zero() ),
    mass( 24.0f ),
    damping( 0.98f ),
    dragOffset( Vec2f::zero() ),
    dragging( false ) { }
    
    void update( const Vec2f& mouseLocation );
    void draw() const;
    void clicked( const Vec2f& mouseLocation );
    void stopDragging();
    void applyForce( const Vec2f& force );
    Vec2f getLocation() const;
    void setLocation( const Vec2f& newLocation );
};

#endif
