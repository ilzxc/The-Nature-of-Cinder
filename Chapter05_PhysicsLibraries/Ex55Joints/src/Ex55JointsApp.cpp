#include "Box2D/Box2D.h"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "Boundary.h"
#include "Particle.h"
#include "Pair.h"
#include "Windmill.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex55JointsApp : public AppNative {
  public:
    void setup();
    void mouseDown( MouseEvent event );
    void keyDown( KeyEvent event );
    void update();
    void draw();
    void shutdown();
    
    b2World *world;
    float32 timeStep;
    int32 velocityIteration;
    int32 positionIteration;
    
    std::vector< Boundary> boundaries;
    std::vector< Pair > pairs;
    std::vector< Particle > particles;
    Windmill windmill;
};

void Ex55JointsApp::setup() {
    world = new b2World( b2Vec2( 0.0f, 9.8f ) );
    timeStep = 1.0f / 60.0f;
    velocityIteration = 8;
    positionIteration = 3;
    
    boundaries.push_back( Boundary( world, getWindowCenter().x - 50.0f, getWindowHeight() * 0.75f, 100.0f, 5.0f ) );
    boundaries.push_back( Boundary( world, 0.0f, 0.0f, 5.0f, getWindowHeight() ) );
    boundaries.push_back( Boundary( world, getWindowWidth() - 5.0f, 0.0f, 5.0f, getWindowHeight() ) );
    boundaries.push_back( Boundary( world, 5.0, getWindowHeight() - 5.0f, 200.0f, 5.0f ) );
    boundaries.push_back( Boundary( world, getWindowWidth() - 205.0, getWindowHeight() - 5.0f, 200.0f, 5.0f ) );
    windmill = Windmill( world, getWindowCenter() );
}

void Ex55JointsApp::mouseDown( MouseEvent event ) {
    pairs.push_back( Pair( world, event.getPos() ) );
}

void Ex55JointsApp::keyDown( KeyEvent event ) {
    if (event.getCode() == KeyEvent::KEY_SPACE ) {
        windmill.toggleMotor();
    }
}

void Ex55JointsApp::update() {
    if( Rand::randInt( 8 ) == 1 ) {
        particles.push_back( Particle( world, Vec2f( Rand::randFloat( getWindowWidth() * 0.333f, getWindowWidth() * 0.333 + getWindowWidth() * 0.333f ), -20.0f ), Rand::randFloat(2.0f, 4.0f) ) ) ;
    }
    
    world->Step( timeStep, velocityIteration, positionIteration );
    
    for ( vector< Pair >::iterator iter = pairs.begin(); iter != pairs.end(); ) {
        iter->update();
        if ( iter->isDead() ) {
            iter->killBody( world );
            iter = pairs.erase( iter );
        } else { ++iter; }
    }
    
    for ( vector< Particle >::iterator iter = particles.begin(); iter != particles.end(); ) {
        iter->update();
        if ( iter->isDead() ) {
            iter->killBody( world );
            iter = particles.erase( iter );
        } else { ++iter; }
    }
    
    windmill.update();
    
    // debug:
    cout << "Particles: " << particles.size() << "; pairs: "  << pairs.size() << endl;
}

void Ex55JointsApp::draw()
{
    gl::clear( Color( 0.944f, 0.944f, 0.944f ) );
    for ( auto& b : boundaries ) {
        b.draw();
    }
    for ( auto& p : pairs ) {
        p.draw();
    }
    for ( auto& p : particles ) {
        p.draw();
    }
    windmill.draw();
}

void Ex55JointsApp::shutdown() {
    for ( auto& p : pairs ) {
        p.killBody( world );
    }
    for ( auto& p: particles ) {
        p.killBody( world );
    }
    delete world;
}

CINDER_APP_NATIVE( Ex55JointsApp, RendererGl )
