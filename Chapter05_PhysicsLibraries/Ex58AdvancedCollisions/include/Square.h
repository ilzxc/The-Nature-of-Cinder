//
//  Square.h
//  Ex58AdvancedCollisions
//
//  Created by Ilya Rostovtsev on 7/28/13.
//
//

#ifndef Ex58AdvancedCollisions_Square_h
#define Ex58AdvancedCollisions_Square_h

#include <Box2D/Box2d.h>
#include "cinder/gl/gl.h"
#include "Conversions.h"
#include "ObjectType.h"
#include "Particle.h"

class Square : public Particle {
private:
    b2Body *body;
    Rectf   bounds;
    
public:
    Square(): Particle( Vec2f::zero(), 0.0f ) { }
    Square( b2World *world, const Vec2f &position, float _angle, float radius );
    ~Square() {}
    void update();
    void draw() const;
    void killBody( b2World *world );
    bool isDead() const;
    void onCollisionWith( const int otherObjectKind );
};

#endif
