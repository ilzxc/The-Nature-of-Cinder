#include <Box2D/Box2d.h>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Boundary.h"
#include "Particle.h"
#include "CollisionDetection.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex57CollisionsApp : public AppNative {
  public:
    void setup();
    void mouseDown( MouseEvent event ); 
    void update();
    void draw();
    void shutdown();
    
    b2World *world;
    float32 timeStep;
    int32 velocityIterations;
    int32 positionIterations;
    CollisionDetection collisions;
    
    Boundary floor;
    std::vector< Particle* > particles;
};

void Ex57CollisionsApp::setup() {
    world = new b2World( b2Vec2( 0.0f, 10.0f ) );
    timeStep = 1.0f / 60.0f;
    velocityIterations = 8;
    positionIterations = 3;
    
    world->SetContactListener( &collisions );
    
    floor = Boundary( world, -10, getWindowHeight() - 50, getWindowWidth() + 20, 5.0f);
}

void Ex57CollisionsApp::mouseDown( MouseEvent event ) {
}

void Ex57CollisionsApp::update() {
    if ( Rand::randInt( 100 ) > 80 ) {
        particles.push_back( new Particle( world, Vec2f( Rand::randFloat( getWindowWidth() ), Rand::randFloat(-500.0, 0.0f) ),  Rand::randFloat(5.0f, 15.0f) ) );
    }
    
    world->Step( timeStep, velocityIterations, positionIterations );
    
    for ( auto& p : particles ) {
        p->update( world );
    }
    
    for ( std::vector< Particle* >::iterator iter = particles.begin(); iter != particles.end(); ) {
        if ( (*iter)->isDead() ) {
            (*iter)->killBody( world );
            delete ( *iter );
            iter = particles.erase( iter );
        } else {
            ++iter;
        }
    }
    
    cout << particles.size() << endl;
}

void Ex57CollisionsApp::draw()
{
    gl::clear( Color( 0.789f, 0.789f, 0.789f ) );
    floor.draw();
    for ( auto& p : particles ) {
        p->draw();
    }
}

void Ex57CollisionsApp::shutdown() {
    for ( auto& p : particles ) {
        p->killBody( world );
        delete p;
    }
    delete world;
}

CINDER_APP_NATIVE( Ex57CollisionsApp, RendererGl )
