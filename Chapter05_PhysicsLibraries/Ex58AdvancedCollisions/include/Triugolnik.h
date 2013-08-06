//
//  Triugolnik.h
//  Ex58AdvancedCollisions
//
//  Created by Ilya Rostovtsev on 8/6/13.
//
//

#ifndef Ex58AdvancedCollisions_Triugolnik_h
#define Ex58AdvancedCollisions_Triugolnik_h

#include <Box2D/Box2d.h>
#include "cinder/gl/gl.h"
#include "Conversions.h"
#include "ObjectType.h"
#include "Particle.h"

class Triugolnik : public Particle {
private:
    b2Body *body;
    Vec2f  *points;
    
public:
    Triugolnik(): Particle( Vec2f::zero(), 0.0f ) { }
    Triugolnik( b2World *world, const Vec2f &position, float _angle, float _radius );
    ~Triugolnik() { delete points; }
    void update();
    void draw() const;
    void killBody( b2World *world );
    bool isDead() const;
    void onCollisionWith( const int otherObjectKind );
};

#endif
