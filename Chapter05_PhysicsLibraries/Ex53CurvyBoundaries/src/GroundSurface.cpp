//
//  Surface.cpp
//  Ex53CurvyBoundaries
//
//  Created by Ilya Rostovtsev on 7/13/13.
//
//

#include "GroundSurface.h"

void GroundSurface::createBody( b2World * world, std::vector<Vec2f> boxPoints ) {
    b2Vec2 *wp = new b2Vec2[boxPoints.size()];
    int i = 0;
    for ( auto& p : boxPoints ) {
        wp[i] = ( Conversions::toPhysics( p ) );
        ++i;
    }
    
    b2ChainShape chain;
    chain.CreateChain( wp, boxPoints.size() );
    
    b2BodyDef bd;
    bd.type = b2_staticBody;
    body = world->CreateBody( &bd );
    
    b2FixtureDef fd;
    fd.shape = &chain;
    body->CreateFixture( &fd );
    
    delete wp;
}

void GroundSurface::draw() const {
    gl::color( 0.37f, 0.37f, 0.37f );
    
    /*
    gl::begin(GL_TRIANGLE_STRIP);
    for (auto& p : points) {
        gl::vertex( p );
    }
    gl::end();
    */
    
    gl::color( 1.0, 0.0, 0.0 );
    gl::begin(GL_LINE_STRIP);
    for (auto& p : points) {
        gl::vertex( p );
    }
    gl::end();
    
}

void GroundSurface::resetSurface( b2World * world ) {
    world->DestroyBody( body );
}