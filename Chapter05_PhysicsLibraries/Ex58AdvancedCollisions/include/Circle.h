//
//  Circle.h
//  Ex58AdvancedCollisions
//
//  Created by Ilya Rostovtsev on 8/6/13.
//
//

#ifndef Ex58AdvancedCollisions_Circle_h
#define Ex58AdvancedCollisions_Circle_h

#include <Box2D/Box2d.h>
#include "cinder/gl/gl.h"
#include "Conversions.h"
#include "ObjectType.h"
#include "Particle.h"

class Circle : public Particle {
private:
    b2Body *body;
    float   radius;
    
public:
    Circle(): Particle( Vec2f::zero(), 0.0f ) { }
    Circle( b2World *world, const Vec2f &position, float _angle, float _radius );
    ~Circle() {}
    void update();
    void draw() const;
    void killBody( b2World *world );
    bool isDead() const;
    void onCollisionWith( const int otherObjectKind );
};

#endif
