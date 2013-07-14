//
//  Particle.h
//  Ex53CurvyBoundaries
//
//  Created by Ilya Rostovtsev on 7/13/13.
//
//

#ifndef Ex53CurvyBoundaries_Particle_h
#define Ex53CurvyBoundaries_Particle_h

#include "cinder/gl/gl.h"
#include "Box2D/Box2D.h"
#include "Conversions.h"
#include "cinder/Rand.h"

using namespace ci;

class Particle {
private:
    float   radius;
    b2Body* body;
    Vec2f   position;
    float   angle;
    
    void makeBody( b2World* w );

public:
    Particle() {}
    Particle( b2World * w, float x, float y, float r )
    : radius( r ),
      position( x, y ),
      angle( 0.0f ) {
          Rand::randomize();
          angle = randFloat(360.0);
          makeBody( w );
    }
    
    void update( b2World* w );
    void draw() const;
    void killBody( b2World* w );
    bool isDead() const;
};

    
#endif
