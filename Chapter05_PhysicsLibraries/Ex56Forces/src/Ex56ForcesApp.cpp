#include <Box2D/Box2D.h>
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "Attractor.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Ex56ForcesApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseDrag( MouseEvent event );
	void update();
	void draw();
    void shutdown();
    
    b2World *world;
    float32 timeStep;
    float32 velocityIterations;
    int32 positionIterations;    
    
    Attractor attractor;
    vector<Particle> particles;
    Vec2f mouseLocation;
};

void Ex56ForcesApp::setup() {
    world = new b2World( b2Vec2( 0.0f, 0.0f ) ); // no gravity in this example!
    timeStep = 1.0f / 60.0f;
    velocityIterations = 8;
    positionIterations = 3;
    
    attractor = Attractor( world, getWindowCenter().x, getWindowCenter().y );
    for (int i = 0; i < 100; ++i) {
        particles.push_back( Particle(world, Vec2f( Rand::randFloat( getWindowWidth() ), Rand::randFloat( getWindowHeight() ) ), randFloat( 7.0f, 14.0f ) ) );
    }
}

void Ex56ForcesApp::mouseDown( MouseEvent event ) {
    attractor.clicked( event.getPos() );
}

void Ex56ForcesApp::mouseUp( MouseEvent event ) {
    attractor.stopDragging();
}

void Ex56ForcesApp::mouseMove( MouseEvent event ) {
    mouseLocation = event.getPos();
}

void Ex56ForcesApp::mouseDrag( MouseEvent event ) {
    mouseLocation = event.getPos();
}

void Ex56ForcesApp::update() {
    attractor.hover( mouseLocation );
    attractor.drag( mouseLocation );
    for ( auto& particle : particles ) {
        particle.update( world, attractor.attract( particle ) );
    }
    world->Step( timeStep, velocityIterations, positionIterations );
    world->ClearForces();
}

void Ex56ForcesApp::draw() {
	gl::clear( Color( 0, 0, 0 ) );
    
    attractor.draw();
    
    for ( auto& particle : particles ) {
        particle.draw();
    }
}

void Ex56ForcesApp::shutdown() {
    for ( auto& particle : particles ) {
        particle.killBody( world );
    }
    attractor.killBody( world );
    delete world;
}

CINDER_APP_NATIVE( Ex56ForcesApp, RendererGl )
