//
//  Attractor.h
//  Ex56Forces
//
//  Created by Ilya Rostovtsev on 7/23/13.
//
//

#ifndef Ex56Forces_Attractor_h
#define Ex56Forces_Attractor_h

#include "Box2D/Box2D.h"
#include "cinder/gl/gl.h"
#include "Particle.h"

using namespace ci;

class Attractor {
private:
    b2Body *body;
    float mass;
    float G;
    Vec2f location;
    bool dragging;
    bool rollover;
    Vec2f dragOffset;
    
public:
    Attractor() { }
    Attractor( b2World *world, float x, float y );
    ~Attractor() { }
    
    b2Vec2 attract( const Particle& p ) const;
    void draw() const;
    void clicked( const Vec2f& mouse );
    void hover( const Vec2f& mouse );
    void stopDragging();
    void drag( const Vec2f& mouse );
    void killBody( b2World *world );
};

#endif
